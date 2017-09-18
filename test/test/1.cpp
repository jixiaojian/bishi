#include <iostream>
#include <string>
using namespace std;
string result(char *a[],int hlen,int wlen)
{
    int xcount=0,ocount=0;
	for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
      {       
      	 if(a[i][j] == 'X')
         {
         	xcount++;
         }
        if(a[i][j] == '0')
         {
         	ocount++;
         }
        if(xcount > ocount && (xcount+ocount)!=9)
           return "2";
        else if(xcount == ocount  && (xcount+ocount)!=9)
          return "1";
        for(int j=0;j<3;j++)
        {  
          if(a[0][j] =='X')
          xcount++;
        if(a[1][j] =='X')
        {
          xcount=0;
          xcount++;
        }
         if(a[2][j] =='X')
        {
          xcount=0;
          xcount++;
        }
        if(xcount ==3 )
           return "1 won";
        if(a[0][j] =='0')
          ocount++;
           if(a[1][j] =='0')
        {
          ocount=0;
          ocount++;
        }
         if(a[2][j] =='0')
        {
          ocount=0;
          ocount++;
        }
        if(ocount ==3 )
           return "2 won";
        if(a[0][0] == a[1][1] ==a[2][2] == 'X')
             return "1 won";
        if(a[0][0] == a[1][1] ==a[2][2] == '0')
             return "2 won";
        }
        for(int i=0;i<3;i++)
        {  
          if(a[i][0] =='X')
          xcount++;
        if(a[i][1] =='X')
        {
          xcount=0;
          xcount++;
        }
         if(a[i][2] =='X')
        {
          xcount=0;
          xcount++;
        }
        if(xcount ==3 )
           return "1 won";
        if(a[i][0] =='0')
          ocount++;
        if(a[i][1] =='0')
        {
          ocount=0;
          ocount++;
        }
         if(a[i][2] =='0')
        {
          ocount=0;
          ocount++;
        }
        if(ocount ==3 )
           return "2 won";       
        }
        if((xcount+ocount)==9  && xcount > ocount)
          return "Draw";       
        else
          return "x";           
      }
}
int main()
{
	char *a[3]; //二维数组存储棋盘数据
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
	string out="";
    out = result(&a[0],3,3);
    cout<<out<<endl;
	/*
	char* input[3];
    for(int i=0;i<3;i++)
    {
		for(int j=0;j<3;j++)
      {
      	 scanf("%d",&(input[i][j]));
      }
	//cin.get();
	  getchar();
	}
    string out="";
    out = result(&input[3],3,3);
    cout<<out<<endl;*/
	return 0;
}
