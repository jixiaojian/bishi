#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
//cout << setprecision(3);      //����setprecision��������ʾ����Ч����λ����  
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
		//cout <<setiosflags(ios::fixed);   //���setprecision��������С������(С��������Чλ��)  
        cout << fixed;                                  //��Ϊcout��һ��������setiosflags(ios::fixed)�ļ�д��ʽ����Ч����һ��  
		cout << setprecision(2) << result << endl; 
		//cin.clear();
	}
	return 0;
}