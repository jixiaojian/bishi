#include <iostream>
#include <string>
using namespace std;

int main() 
{
	char a[14]="hello";
	//a = "hello";
	//a[14] = {'h','e','l'};
  while(1) 
  {
    char a[3][3]; //二维数组存储棋盘数据
    int xCount = 0, oCount = 0; //X和0的个数
    for(int i = 0; i < 3; ++i) 
	{
      string s = "";
      getline(cin, s);
      if(s.size() == 0) return 0; //终止条件
      for(int j = 0; j < 3; ++j) 
	  {
        a[i][j] = s[j]; //赋值
        // 计数
        if(s[j] == 'X') ++xCount;
        else if(s[j] == '0') ++oCount;
      }
    }
    
    // 计算差值和基本判断
    int diff = xCount - oCount;
    if(diff != 0 && diff != 1) 
	{
      cout << "x" << endl;
      continue;
    }
    
    int wx = 0, wo = 0; //X赢和0赢的标志
    // 判断行
    for(int i = 0; i < 3; ++i) 
	{
      if(a[i][1] != '.' && a[i][0] == a[i][1] && a[i][2] == a[i][1]) 
	  {
        if(a[i][1] == 'X') wx = 1;
        else wo = 1;
      }
    }
    // 判断列
    for(int i = 0; i < 3; ++i) 
	{
      if(a[1][i] != '.' && a[0][i] == a[1][i] && a[2][i] == a[1][i]) 
	  {
        if(a[1][i] == 'X') wx = 1;
        else wo = 1;
      }
    }
    // 判断对角
    if(a[1][1] != '.' && ((a[0][0] == a[1][1] && a[2][2] == a[1][1]) || (a[0][2] == a[1][1] && a[2][0] == a[1][1]))) 
	{
      if(a[1][1] == 'X') wx = 1;
      else wo = 1;
    }
    
    // 判断输出
    if(wx && wo || wx && !diff || wo && diff) cout << "x" << endl; //X与0不能同时赢；X赢时diff不能为0；0赢时diff不能为1
    else if(wx) cout << "1 won" << endl;
    else if(wo) cout << "2 won" << endl;
    else if(xCount + oCount == 9) cout << "draw" << endl;
    else if(diff) cout << "2" << endl;
    else if(diff == 0) cout << "1" << endl;
  }
}