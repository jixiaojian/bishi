#include <iostream>
#include <set>
#include <limits.h>
#include <vector>
#include <unordered_map>
using namespace std;
#define MAX 100
// 邻接矩阵
typedef struct _graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;

// 边的结构体
typedef struct _EdgeData
{
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重
}EData;
/*
 * Dijkstra最短路径。
 * 即，统计图(G)中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *        G -- 图
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 */
void dijkstra(Graph G, int vs, int prev[], int dist[])
{
    int i,j,k;
    int min;
    int tmp;
    int flag[MAX];      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。

    // 初始化
    for (i = 0; i < G.vexnum; i++)
    {
        flag[i] = 0;              // 顶点i的最短路径还没获取到。
        prev[i] = 0;              // 顶点i的前驱顶点为0。
        dist[i] = G.matrix[vs][i];// 顶点i的最短路径为"顶点vs"到"顶点i"的权。
    }

    // 对"顶点vs"自身进行初始化
    flag[vs] = 1;
    dist[vs] = 0;

    // 遍历G.vexnum-1次；每次找出一个顶点的最短路径。
    for (i = 1; i < G.vexnum; i++)
    {
        // 寻找当前最小的路径；
        // 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
        min = INT_MIN;
        for (j = 0; j < G.vexnum; j++)
        {
            if (flag[j]==0 && dist[j]<min)
            {
                min = dist[j];
                k = j;
            }
        }
        // 标记"顶点k"为已经获取到最短路径
        flag[k] = 1;

        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
        for (j = 0; j < G.vexnum; j++)
        {
			tmp = (G.matrix[k][j]==INT_MAX ? INT_MAX : (min + G.matrix[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) )
            {
                dist[j] = tmp;
                prev[j] = k;
            }
        }
    }

    // 打印dijkstra最短路径的结果
    printf("dijkstra(%c): \n", G.vexs[vs]);
    for (i = 0; i < G.vexnum; i++)
        printf("  shortest(%c, %c)=%d\n", G.vexs[vs], G.vexs[i], dist[i]);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
struct vertex
{
    int version; // version number
    vertex *pre; // for building the path, points to its parent, the root's pre is NULL
    vertex(int v)
	{
        version = v;
        pre = nullptr; 
    }
};

class graph
{
public:
    vector<vector<pair<int,int> > >adj; // pair<destination, length>
    unordered_map<int,int> version_index; // version to index
    vector<vertex*> v;
    int n = 0; // No. of Vertices
    void add_edge(int start, int end, int len)
	{
        if(version_index.find(start) == version_index.end())
		{
            version_index[start] = n++;
            v.push_back(new vertex( start));
            adj.push_back(vector<pair<int,int> >());
        }
        if(version_index.find(end) == version_index.end())
		{
            version_index[end] = n++;
            v.push_back(new vertex(end));
            adj.push_back(vector<pair<int,int> >());
        }
        adj[version_index[start]].push_back(make_pair(version_index[end], len));
    }
};

void dijkstra(graph G, int source, int target){
	/*	
	 *  dijkstra algorithm
	 *	calculate the shortest distances and find the corresponding paths form source to every other vertex in the graph 
	 *  we will only print the path and the distance from source to the given target
	 */ 
    vector<int> min_distance(G.n, INT_MAX); // initial all the distances from start to current vertex to be infinite
    min_distance[source] = 0;   // length from source to source is 0 
    set<pair<int,int> > V; // pair<distance, source>, pairs in set are sorted by the first element in pair by default, 
    					   //  we can use this trick instead of a min heap for the priority queue in dijkstra algorithm here
    V.insert(make_pair(0,source)); // init 
    while(!V.empty()){
        int s = V.begin()->second; //  vertex we want to extract, we first store this vertex in s
        V.erase(V.begin()); // extract the minimal element from the set
        for(auto x : G.adj[s]){
            // x is pair<dest,distance>
            // for all the edges starts from s
            if(min_distance[x.first] > min_distance[s] + x.second){
                // if we find a shorter distance, update the new shorter distance
                // also update the pointer for later path building
                // the pre pointer is pointing to its parent, reverse the linked-list later we can get the path
                G.v[x.first]->pre = G.v[s]; 
                min_distance[x.first] = min_distance[s] + x.second;
                V.insert(make_pair(min_distance[x.first],x.first));
            }
        }
    }
    // now we have all we need, let's print the path and the shortest distance
    auto x = G.v[target];
    vector<int> path;
    while(x){
        path.push_back(x->version);
        x = x->pre;
    }
    // print version number from last to first in the vector
    for(int i = (int)path.size()-1; i >= 0 ;--i){
        cout << path[i];
        if(i > 0) cout << "->";
    }
    // print the shortest distance in brackets
    cout << "(" << min_distance[target] << ")" << endl;
}
int main(){
    int start, end;
    cin >> start >> end ;
    graph G;
  	int s,g,l;
    while(cin >>s && cin >> g && cin >>l){
            G.add_edge(s, g, l);
     }
    dijkstra(G, G.version_index[start], G.version_index[end]);
    for(auto& x: G.v){
        delete x;   // de-allocate memory
        x = nullptr;
    }
    return 0;
}