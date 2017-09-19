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
//第二题
/* 指定条件的最小子集合
 * 集合包含顺序,是连续子数组;
 * 条件:使得子数组中最小的数和数组元素之和的乘积最大,找出这样的最大乘积,不要求输出具体数组
 * 每个元素大小0-100
 * 数组个数n,n为0-500000
 * 测试数据
 * 3
 * 6 1 2
 * 输出36*/
int n;
int d[500001];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> d[i];
    }

    int ans = -1;
    for (int i = 0; i < n; ++i)
    {
        int middle = d[i];//把当前值认为是子数组中的最小值
        int sum = d[i];
        for (int j = i + 1; j < n; ++j)//向右搜索
        {
			if(middle <= d[j])       //比当前值大，相加
				sum += d[j];
			else
				break;			
		}
        for (int j = i - 1;  j >= 0; --j)//向左搜索
		{
			if(middle <= d[j])      //比当前值大，相加
				sum += d[j];
			else
				break;
		}
            
        ans = max(ans, middle * sum);
    }
    cout << ans << endl;

    return 0;
}
