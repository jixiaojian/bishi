#include <iostream>
using namespace std;

int main()
{
	//无论是float还是double类型的变量，都有精度限制。所以一定要避免将浮点变量用“==”或“！=”与数字比较，应该设法转化成“>=”或“<=”形式。
	float f=0.0000001;
	cout<<f<<endl;
	if(abs(f)<1e-6)   //float有6位有效位,double有15位有效位
		cout<<"f很接近0"<<endl;
	else
		cout<<"f不接近0"<<endl;
	return 0;
}