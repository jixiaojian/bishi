#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>
#include <ctime>
using namespace std;

struct idea {
   int num;//idea的编号
   int pm;//PM的编号
   int st;//提出时间
   int ct;//所需时间
   int p;//优先级

   bool operator < (const idea& a) const {
       if (ct == a.ct) {
           return pm > a.pm;
       }
       return ct > a.ct;
   }
};

bool pmCom(const idea& a, const idea& b) {
   return a.st < b.st;//按照提出时间排序从小到大排序
}


int main()
{
   int n, m, p;
   cin>>n>>m>>p;

   vector<idea> ve(p);
   vector<int> vans(p, 0);
   for (int i = 0; i < p; ++i) 
   {
       cin>>ve[i].pm>>ve[i].st>>ve[i].p>>ve[i].ct;
       ve[i].num = i;
   }
   sort(ve.begin(), ve.end(), pmCom);

   priority_queue<idea> que;//在当前程序员时间内的idea优先队列，类似于最小堆
   priority_queue<int, vector<int>, greater<int>> pro;//程序员的优先队列，类似于最小堆
   for (int i = 0; i < m; ++i) 
   {
       pro.push(0);//每个程序员的初始时间都是0
   }

   for (int i = 0; i < p || !que.empty();) 
   {
       //每次程序员需要挑选所需时间最小的，最小时间相同则选择pm序号最小的
       while (i < p && ve[i].st <= pro.top()) 
	   {
           que.push(ve[i]);
           i++;
       }
       if (que.empty()) 
	   {
           que.push(ve[i]);
           int t = ve[i].st;
           ++i;
           while (i < p && ve[i].st == t) 
		   {
               que.push(ve[i]);
               ++i;
           }
       }

       idea ide = que.top();
       que.pop();
       int it = max(pro.top(), ide.st) + ide.ct;
       pro.pop();
       pro.push(it);
       vans[ide.num] = it;
   }

   for (int i = 0; i < p; ++i) {
       cout<<vans[i]<<endl;
   }
   return 0;
}
/*
2 2 5
1 1 1 2
1 2 1 1
1 3 2 2
2 1 1 2
2 3 5 5
3
4
5
3
9
*/