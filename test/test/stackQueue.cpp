//用两个栈实现队列
//思路：一个栈A为输入队列，一个栈B为输出队列。
//若输出队列不为空，直接输出B中的值。若为空，则将A中的值弹出到B中
#include <iostream>
#include <stack>
using namespace std;
template<class T>
class Myqueue
{
private:
	stack<T> A;
	stack<T> B;
public:
	void push(T num)
	{
		A.push(num);
	}
	void pop()
	{
		if(B.empty())
		{
			while(!A.empty())
			{

				B.push(A.top);
				A.pop();
			}
			B.pop();
		}
		else
			B.pop();
	}
	T front()         //队首元素
	{
		if(B.empty())
		{
			while(!A.empty())
			{

				B.push(A.top);
				A.pop();
			}
			return B.top;
		}
		else
			return B.top;
	}
};
