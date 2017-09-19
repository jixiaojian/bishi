#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
//cout << setprecision(3);      //单用setprecision是设置显示的有效数字位数。  
//cout << setprecision(0) << f << endl;  
int main()
{
	int n,m;
	double result=0;
	while(cin>>n>>m)
	{
		result= 0;
		double n1=n;
		for(int i=0;i<m;i++)
		{
			result+=n1;
			n1= sqrt(n1);
		}
		//cout<<result<<endl;
		//cout <<setiosflags(ios::fixed);   //配合setprecision就是设置小数精度(小数点后的有效位数)  
        cout << fixed;                                  //作为cout的一个参数是setiosflags(ios::fixed)的简写形式，等效于上一行  
		cout << setprecision(2) << result << endl; 
		//cin.clear();
	}
	return 0;
}