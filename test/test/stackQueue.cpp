//������ջʵ�ֶ���
//˼·��һ��ջAΪ������У�һ��ջBΪ������С�
//��������в�Ϊ�գ�ֱ�����B�е�ֵ����Ϊ�գ���A�е�ֵ������B��
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
	T front()         //����Ԫ��
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
