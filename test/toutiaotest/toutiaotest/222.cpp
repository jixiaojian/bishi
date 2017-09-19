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
   int num, pos;//num表示数字，pos表示数字在num数组中的下标
   point(int num, int pos) : num(num), pos(pos) {}
   point() {}
}stk[MAX];//用来模拟栈

int num[MAX], sum[MAX], le[MAX], ri[MAX];
int n;
/**
* 思路：对于数组中的每个数字，可以把它看成是当前区间的最小数，这样只需要找到这个数的左边界和右边界（第一个小于这个数的位置），这个数的序列积就为这个数和左右边界区间数的和的乘积，最大的就是答案。
* 由于给的数组特别大，需要在O(n)时间内求解,具体看代码。
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

   //求每个数的右边界
   int len = -1;
   for (int i = 1; i <= n; ++i) 
   {
       while (len > -1 && num[i] < stk[len].num)
	   {//当前数小于栈顶数，当前数的位置就是栈顶数的右边界
           ri[stk[len--].pos] = i;
       }
       stk[++len] = point(num[i], i);
   }
   //求每个数的左边界
   len = -1;
   for (int i = n; i > 0; --i) 
   {
       while (len > -1 && num[i] < stk[len].num) 
	   {//当前数小于栈顶数，当前数的位置就是栈顶数的左边界
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
