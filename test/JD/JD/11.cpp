#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
long long n;
//
int main() 
{
    cin >> n;
    long long l = 1, r = 2000000000LL, mid;
    while(l < r) 
	{
        mid = (l + r) / 2;
        if(mid * (mid + 1) / 2 >= n)
            r = mid;
        else 
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
*/
void Func(int &nVal1);
class A
{
   int i;
};
class B{
   A *p;
public:
   B()
   {p=new A;}
   ~B()
   {delete p;}   //�������Σ�
};
void sayHello(B b)
{
	cout<<"hello"<<endl;
}
int main()
{
   B b;
   sayHello(b);   //�˴����������
   int a;
   Func(a);
   //Func(*a);����
   //Func(&a);
}//�˴����������
