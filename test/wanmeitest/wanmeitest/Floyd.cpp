#include <iostream>
#include <climits>
#include <iomanip>
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
void ShortestPath_Floyd(Graph &G);                 // ���·���㷨 (���������㷨) 


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

void ShortestPath_Floyd(Graph &G)
{
    const int N = G.verNum;
    int Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];      //��ʾvi��vj֮������·�ϵ�ǰ������ 
    long long D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //��ʾvi��vj֮������·������ 

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

    /* ���ÿ�����·�� */
    for(int i = 0; i < N; ++ i){
        for(int j = 0; j < N; ++ j){
            cout << G.vertex[i] << "��" << G.vertex[j] << ": " << G.vertex[j];
            for(int vi = Path[i][j]; vi != i; vi = Path[i][vi]){
                cout << "��" << G.vertex[vi];
            }
            cout << "��" << G.vertex[i] << " (" << D[i][j] << ")" << endl;
        }
    }
}