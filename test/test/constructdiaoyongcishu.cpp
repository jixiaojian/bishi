/*C++构造函数初始化按下列顺序被调用：
 
•首先，任何虚拟基类的构造函数按照它们被继承的顺序构造；
•其次，任何非虚拟基类的构造函数按照它们被继承的顺序构造；
•最后，任何成员对象的构造函数按照它们声明的顺序调用；
*/
#include <iostream>
#include <windows.h>
using namespace std;
class OBJ1{
 public:
 OBJ1(){ cout<<"OBJ1\n"; }
};
class OBJ2{
 public:
 OBJ2(){ cout<<"OBJ2\n";}
};
class Base1{
 public:
 Base1(){ cout<<"Base1\n";}
};
class Base2{
 public:
 Base2(){ cout <<"Base2\n"; }
};
class Base3{
 public:
 Base3(){ cout <<"Base3\n"; }
};
class Base4{
 public:
 Base4(){ cout <<"Base4\n"; }
};
class Derived :public Base1, virtual public Base2,public Base3, virtual public Base4//继承顺序
{
public:
 Derived() :obj2(), obj1(),Base1(), Base2(), Base3(),Base4()
 {//初始化列表
 cout <<"Derived ok.\n";
 }
 protected:
 OBJ1 obj1;//声明顺序.     先调用基类的构造函数，按继承顺序；然后调用派生类的成员变量的构造函数，按声明顺序；最后调用派生类的构造函数。
 OBJ2 obj2;
};



class AA
 {
 public:
     AA():n(10){cout << "AA" << endl;}
 private:
     int n;
 };
 
 class BB
 {
 public:
     BB():d(2.0){cout << "BB" << endl;}
 private:
     double d;
 };
 
 class CC
 {
 public:
     CC():k(20){cout << "CC" << endl;}
     void print()
     {
         cout << "i = " << i << endl;
         cout << "k = " << k << endl;
     }
 
 private:
     AA aa;
     BB bb;
     int i;
     double k;
 };


int main()
{
 /*Derived aa;//初始化
 cout <<"This is ok.\n";

 CC c;
 c.print();
 */
 char a[30]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
 DWORD *i;
 i=(DWORD*)a;
 i++;
 int p=*((char*)i);
 cout<<p<<endl;
 return 0;
}
