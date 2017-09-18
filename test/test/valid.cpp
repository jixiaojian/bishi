#include <iostream>
#include <string>
#include <stack>
using namespace std;
//用一个栈来对输入的括号串进行处理，如果是左括号就入栈，如果是右括号就与栈顶元素(判断栈是否为空)看是否组成一对括号，
//组成就弹出，并且处理下一个输入的括号，如果不匹配就直接返回结果。若到最后，栈为空则匹配正确。
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