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
   int num;//idea�ı��
   int pm;//PM�ı��
   int st;//���ʱ��
   int ct;//����ʱ��
   int p;//���ȼ�

   bool operator < (const idea& a) const {
       if (ct == a.ct) {
           return pm > a.pm;
       }
       return ct > a.ct;
   }
};

bool pmCom(const idea& a, const idea& b) {
   return a.st < b.st;//�������ʱ�������С��������
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

   priority_queue<idea> que;//�ڵ�ǰ����Աʱ���ڵ�idea���ȶ��У���������С��
   priority_queue<int, vector<int>, greater<int>> pro;//����Ա�����ȶ��У���������С��
   for (int i = 0; i < m; ++i) 
   {
       pro.push(0);//ÿ������Ա�ĳ�ʼʱ�䶼��0
   }

   for (int i = 0; i < p || !que.empty();) 
   {
       //ÿ�γ���Ա��Ҫ��ѡ����ʱ����С�ģ���Сʱ����ͬ��ѡ��pm�����С��
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