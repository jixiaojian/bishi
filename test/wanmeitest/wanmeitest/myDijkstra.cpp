#include <iostream>
#include <vector>
using namespace std;

#define MAX 20
typedef enum{DG,UDG} Gkind;
typedef struct graph
{
	int vexNum;  //顶点数
	int edgeNum; //边数
	char vex[MAX];//顶点数组
	int matrix[MAX][MAX];//邻接矩阵
	Gkind kind;  //有向图，无向图
}Graph;

int vertexLoc(const Graph &G,const char &v);

void createGraph(Graph &G)
{
	G.kind = DG;
	//顶点数
	const int n=5;
	char V[n+1]={"12345"};

	//边数
	const int en=6;
	char V1[en+1]={"112234"};
	char V2[en+1]={"233455"};
	int endis[en+1]={50,70,15,30,40,20};
	
	//初始化
	G.vexNum = n;
	G.edgeNum = en;
	for(int i=0;i<n;i++)
	{
		G.vex[i] = V[i];
	}
	for(int i=0;i<en;i++)
		for(int j=0;j<en;j++)
		{
			G.matrix[i][j]=INT_MAX;
		}
	for(int i=0;i<en;i++)
		{
			int v1=vertexLoc(G,V1[i]);
			int v2=vertexLoc(G,V2[i]);
			if(G.kind == DG)
				G.matrix[v1][v2]=endis[i];
			else
				G.matrix[v1][v2]=G.matrix[v2][v1]=endis[i];
		}
}
int vertexLoc(const Graph &G,const char &v)
{
	for(int i=0;i<G.vexNum;i++)
	{
		if(G.vex[i] == v)
			return i;
	}
}
void shortest_Dijkstra(Graph &G,int v0)
{
	int n=G.vexNum;
	bool flag[MAX];  //某顶点是否为最短路径
	int path[MAX];   //表示v0到vi的最短路径上的直接前驱顶点
	long long dis[MAX];   //v0到顶点vi的最短距离
	for(int i=0;i<n;i++)
	{
		flag[i]=false;
		dis[i]=G.matrix[v0][i];
		path[i]=G.matrix[v0][i]== INT_MAX ? -1:0;
	}
	flag[v0] = true;
	dis[v0] = 0;
	//找v0到vi的最小值
	for(int i=0;i<n;i++)
	{
		int MIN = INT_MAX,k;
		for(int i=0;i<n;i++)
		{
			if(!flag[i] && dis[i] < MIN)
			{
				MIN = dis[i];
				k = i;
			}
		}
		flag[k] = true;
		for(int i = 0; i < n; i++)
		{
			if(!flag[i] && dis[k] + G.matrix[k][i] < dis[i])
			{
				dis[i] = MIN + G.matrix[k][i];
				path[i] = k;
			}
		}
	}
	//输出路径和长度
	for(int vi = 0; vi < n; ++ vi)
	{
        cout << G.vex[vi];
        if(flag[vi])
		{
            for(int vj = path[vi]; vj != -1; vj = path[vj])
			{
                cout << "←" << G.vex[vj];
            }
            cout << " (" << dis[vi] << ")" << endl;
        }
		else
		{
            cout << " (INF)" << endl;
        }
    }
	//输出到终点的最短路径
	vector<vector<char>> vec;
	for(int i = 0; i < n; ++ i)
	{
		vector<char> temp;
		temp.push_back(G.vex[i]);
        if(flag[i])
		{
            for(int vj = path[i]; vj != -1; vj = path[vj])
			{
                temp.push_back(G.vex[vj]); 
            }
             //temp.push_back(dis[i]);
        }
		vec.push_back(temp);
    }
	for(vector<char> ::reverse_iterator it = vec[n-1].rbegin(); it!=vec[n-1].rend(); it++)
	{
		cout<< *it ;
		if(it!=vec[n-1].rend()-1)
			cout<<"->";
	}
	cout<<"("<<dis[n-1]<<")";
}

int main()
{
	Graph G;
	createGraph(G);
	shortest_Dijkstra(G,0);
}