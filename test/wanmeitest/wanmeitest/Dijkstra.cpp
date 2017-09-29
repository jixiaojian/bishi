#include <iostream>
#include <climits>
using namespace std;

#define MAX_VERTEX_NUM 20  // ������������ 
typedef char VerType;      // ����ṹ , �������ĸ���� 
typedef int ArcType;       // �ߵĽṹ , Ȩֵ 
typedef enum {DG, UDG} GKind;  // ͼ���ͣ�{����ͼ,����ͼ}

// ͼ�Ĵ洢�ṹ 
typedef struct
{
    int verNum, arcNum;  // ��������, ������ 
    GKind kind;          // ͼ���� 
    VerType vertex[MAX_VERTEX_NUM];                 //����
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //�� 
}Graph;


void CreateGraphByArray(Graph &G);                 // ����ͼG (ͨ��Ԥ���������)
int  VertexLoc(const Graph &G, const VerType &v);  // ��ȡ����v��ͼG�е�λ�� 
void ShortestPath_Dijkstra(Graph &G, int k);       // ���·���㷨 (�Ͻ�˹�����㷨)


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


    // ���붥�� 
    G.verNum = vn;
    for(int i = 0; i < G.verNum; ++ i){
        G.vertex[i] = V[i];
    }

    // ��ʼ���ڽӾ��� 
    for(int vi = 0; vi < G.verNum; ++ vi){
        for(int vj = 0; vj < G.verNum; ++ vj){
            G.arcs[vi][vj] = INT_MAX;
        }
    }

    // ����� 
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
    bool S[MAX_VERTEX_NUM];          // ��ʾv0��vi�����·���Ƿ��Ѿ�ȷ�� 
    int Path[MAX_VERTEX_NUM];        // ��ʾv0��vi�����·���ϵ�ֱ��ǰ������ 
    long long D[MAX_VERTEX_NUM];     // ��ʾv0��vi�����·������ 
	
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

    /* ������·�� */
    for(int vi = 0; vi < N; ++ vi)
	{
        cout << G.vertex[vi];
        if(S[vi])
		{
            for(int vj = Path[vi]; vj != -1; vj = Path[vj])
			{
                cout << "��" << G.vertex[vj];
            }
            cout << " (" << D[vi] << ")" << endl;
        }
		else
		{
            cout << " (INF)" << endl;
        }
    }
}