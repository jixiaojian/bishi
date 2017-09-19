
#include <iostream>
#include <numeric>
#include <limits>
using namespace std;
// 请完成下面这个函数，实现题目要求的功能
// 当然，你也可以不按照这个模板来作答，完全按照自己的想法来 ^-^
//第n年兔子年龄总和
int result(int x, int y) 
{
    if(y == 1 || y == 2)
       return 2*y;
    if(y == 3)
       return 8;
    if(y <= x)
    {
		int i = 2;
		int s = y;
		while(s>=1)
		{
			s = s-i;
			y+=s;
			i++;
		}
		y = 2*y;
    }
    return 0;
}
int main() {
    int x, y;
    cin >> x;
    cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
    cin >> y;
    cin.ignore (numeric_limits<std::streamsize>::max(), '\n');
    int res = result(x,y);
    cout << res << endl;
    return 0;
}