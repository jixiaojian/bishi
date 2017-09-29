#include <iostream>
#include <climits>
using namespace std;

#define MAX_VERTEX_NUM 20  // 顶点数量上限 
typedef char VerType;      // 顶点结构 , 顶点的字母名称 
typedef int ArcType;       // 边的结构 , 权值 
typedef enum {DG, UDG} GKind;  // 图类型，{有向图,无向图}

// 图的存储结构 
typedef struct
{
    int verNum, arcNum;  // 顶点数量, 边数量 
    GKind kind;          // 图类型 
    VerType vertex[MAX_VERTEX_NUM];                 //顶点
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //边 
}Graph;


void CreateGraphByArray(Graph &G);                 // 创建图G (通过预定义的数组)
int  VertexLoc(const Graph &G, const VerType &v);  // 获取顶点v在图G中的位置 
void ShortestPath_Dijkstra(Graph &G, int k);       // 最短路径算法 (迪杰斯特拉算法)


int graphDijkstra()
{
    Graph G;
    CreateGraphByArray(G);
    ShortestPath_Dijkstra(G, 0);
    return 0;
}


void CreateGraphByArray(Graph &G)
{
    G.kind = DG;

    const int vn = 6;
    VerType V[vn + 1] = {"012345"};

    const int en = 8;
    VerType V1[en + 1] = {"00012344"};
    VerType V2[en + 1] = {"25423535"};
    ArcType E[en] = {10,100,30,5,50,10,20,60};


    // 输入顶点 
    G.verNum = vn;
    for(int i = 0; i < G.verNum; ++ i){
        G.vertex[i] = V[i];
    }

    // 初始化邻接矩阵 
    for(int vi = 0; vi < G.verNum; ++ vi){
        for(int vj = 0; vj < G.verNum; ++ vj){
            G.arcs[vi][vj] = INT_MAX;
        }
    }

    // 输入边 
    G.arcNum = en;
    for(int i = 0; i < G.arcNum; ++ i){
        VerType &v1 = V1[i], &v2 = V2[i];
        ArcType &e = E[i];
        int vi = VertexLoc(G, v1), vj = VertexLoc(G, v2);
        if(vi == G.verNum || vj == G.verNum){
            continue;
        }
        if(UDG == G.kind){
            G.arcs[vi][vj] = G.arcs[vj][vi] = e;
        }else{
            G.arcs[vi][vj] = e;
        }
    }
}

int VertexLoc(const Graph &G, const VerType &v)
{
    for(int i = 0; i < G.verNum; ++ i){
        if(G.vertex[i] == v){
            return i;
        }
    }
    return G.verNum;
}

void ShortestPath_Dijkstra(Graph &G, int v0)
{
    const int N = G.verNum;
    bool S[MAX_VERTEX_NUM];          // 表示v0到vi的最短路径是否已经确定 
    int Path[MAX_VERTEX_NUM];        // 表示v0到vi的最短路径上的直接前驱顶点 
    long long D[MAX_VERTEX_NUM];     // 表示v0到vi的最短路径长度 
	
    for(int v = 0; v < N; ++ v){
        S[v] = false;
        D[v] = G.arcs[v0][v];
        Path[v] = D[v] != INT_MAX ? v0 : -1;
    }
    S[v0] = true;
    D[v0] = 0;

    for(int i = 1; i < N; ++ i)
	{
        int min = INT_MAX, v;
        for(int w = 0; w < N; ++ w)
		{
            if(!S[w] && D[w] < min)
			{
                v = w;
                min = D[w];
            }
        }

        if(min != INT_MAX)
		{
            S[v] = true;
            for(int w = 0; w < N; ++ w)
			{
                if(!S[w] && (D[v] + G.arcs[v][w] < D[w]))
				{
                    D[w] = D[v] + G.arcs[v][w];
                    Path[w] = v;
                }
            }
        }
    }

    /* 输出最短路径 */
    for(int vi = 0; vi < N; ++ vi)
	{
        cout << G.vertex[vi];
        if(S[vi])
		{
            for(int vj = Path[vi]; vj != -1; vj = Path[vj])
			{
                cout << "←" << G.vertex[vj];
            }
            cout << " (" << D[vi] << ")" << endl;
        }
		else
		{
            cout << " (INF)" << endl;
        }
    }
}