#include <iostream>
#include <string>
#include <stack>
using namespace std;
//��һ��ջ������������Ŵ����д�������������ž���ջ������������ž���ջ��Ԫ��(�ж�ջ�Ƿ�Ϊ��)���Ƿ����һ�����ţ�
//��ɾ͵��������Ҵ�����һ����������ţ������ƥ���ֱ�ӷ��ؽ�����������ջΪ����ƥ����ȷ��
bool isValid(string s)
{
	stack<char> mystack;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(' || s[i]=='[' || s[i]=='{')
			mystack.push(s[i]);
		if(s[i] == ')')
		{
			if(!mystack.empty())
			{
				if(mystack.top() != '(')
					return false;
				else
					mystack.pop();
			}
			else
				return false;
		}
		if(s[i] == ']')
		{
			if(!mystack.empty())
			{
				if(mystack.top() != '[')
					return false;
				else
					mystack.pop();
			}
			else
				return false;
		}
		if(s[i] == '}')
		{
			if(!mystack.empty())
			{
				if(mystack.top() != '{')
					return false;
				else
					mystack.pop();
			}
			else
				return false;
		}
	}
	if(mystack.empty())
		return true;
	else
		return true;
}