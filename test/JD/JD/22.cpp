#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//神奇数： 242拆分两组为{2，2}和{4}，各组相加和相等
bool check(int n) 
{
    char s[11];
    int cur = 0, t = 0;
   //将一个数分离：个、十、百、千。。。。至s[i]，然后相加
	while(n > 0) 
	{
        s[cur] = n % 10;
        t += s[cur++];
        n /= 10;
    }
    if(t % 2) //相加和为奇数则不是神奇数
		return false;
    t /= 2;  //二分查找
    bool ok[42] = {0};
    ok[s[0]] = true;
    for(int i = 1; i < cur; i++) 
	{
        int v = s[i];
        for(int j = 41; j >= 0; j--) //所有数位和最大为81(9*9,r<10e9)
		{
            if(ok[j] && j + v <= 41) 
			{
                ok[j + v] = true;
            }
        }
        if(ok[t]) 
		{
            return true;
        }
    }
    return false;
}
int l, r;
int main() 
{
    int res = 0;
    cin >> l >> r;
    for(int i = l; i <= r; i++) 
	{
        if(check(i)) 
			res++;
    }
    cout << res << endl;
    return 0;
}
