#include <iostream>
#include <climits>
#include <iomanip>
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
void ShortestPath_Floyd(Graph &G);                 // 最短路径算法 (弗洛伊德算法) 


int main()
{
    Graph G;
    CreateGraphByArray(G);
    ShortestPath_Floyd(G);
    return 0;
}


void CreateGraphByArray(Graph &G)
{
    G.kind = DG;

    const int vn = 4;
    VerType V[vn + 1] = {"0123"};

    const int en = 8;
    VerType V1[en + 1] = {"00112223"};
    VerType V2[en + 1] = {"13323012"};
    ArcType E[en] = {1,4,2,9,8,3,5,6};


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

void ShortestPath_Floyd(Graph &G)
{
    const int N = G.verNum;
    int Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];      //表示vi和vj之间的最短路上的前驱顶点 
    long long D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //表示vi和vj之间的最短路径长度 

    for(int i = 0; i < N ; ++ i){
        for(int j = 0; j < N; ++ j){
            D[i][j] = G.arcs[i][j];
            Path[i][j] = D[i][j] != INT_MAX ? i : -1;
        }
    }

    for(int k = 0; k < N; ++ k){
        for(int i = 0; i < N; ++ i){
            for(int j = 0; j < N; ++ j){
                if(D[i][k] + D[k][j] < D[i][j]){
                    D[i][j] = D[i][k] + D[k][j];
                    Path[i][j] = Path[k][j];
                }
            }
        }
    }

    /* 输出每对最短路径 */
    for(int i = 0; i < N; ++ i){
        for(int j = 0; j < N; ++ j){
            cout << G.vertex[i] << "→" << G.vertex[j] << ": " << G.vertex[j];
            for(int vi = Path[i][j]; vi != i; vi = Path[i][vi]){
                cout << "←" << G.vertex[vi];
            }
            cout << "←" << G.vertex[i] << " (" << D[i][j] << ")" << endl;
        }
    }
}