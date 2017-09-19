#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 500005

struct point 
{
   int num, pos;//num��ʾ���֣�pos��ʾ������num�����е��±�
   point(int num, int pos) : num(num), pos(pos) {}
   point() {}
}stk[MAX];//����ģ��ջ

int num[MAX], sum[MAX], le[MAX], ri[MAX];
int n;
/**
* ˼·�����������е�ÿ�����֣����԰��������ǵ�ǰ�������С��������ֻ��Ҫ�ҵ����������߽���ұ߽磨��һ��С���������λ�ã�������������л���Ϊ����������ұ߽��������ĺ͵ĳ˻������ľ��Ǵ𰸡�
* ���ڸ��������ر����Ҫ��O(n)ʱ�������,���忴���롣
*/

int main() 
{
   cin>>n;
   sum[0] = 0;
   for (int i = 1; i <= n; ++i) 
   {
       cin>>num[i];
       sum[i] = sum[i - 1] + num[i];
   }

   memset(le, 0, sizeof(le));
   memset(ri, 0, sizeof(ri));

   //��ÿ�������ұ߽�
   int len = -1;
   for (int i = 1; i <= n; ++i) 
   {
       while (len > -1 && num[i] < stk[len].num)
	   {//��ǰ��С��ջ��������ǰ����λ�þ���ջ�������ұ߽�
           ri[stk[len--].pos] = i;
       }
       stk[++len] = point(num[i], i);
   }
   //��ÿ��������߽�
   len = -1;
   for (int i = n; i > 0; --i) 
   {
       while (len > -1 && num[i] < stk[len].num) 
	   {//��ǰ��С��ջ��������ǰ����λ�þ���ջ��������߽�
           le[stk[len--].pos] = i;
       }
       stk[++len] = point(num[i], i);
   }

   int ans = 0;
   for (int i = 1; i <= n; ++i) 
   {
       if (ri[i] == 0) 
	   {
           ri[i] = n + 1;
       }
       ans = max(ans, (sum[ri[i] - 1] - sum[le[i]]) * num[i]);
   }
   cout<<ans<<endl;
   return 0;
}
/**
4
1 2 3 4
4
4 3 2 1
7
1 2 3 4 3 2 1
**/
