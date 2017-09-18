#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>
/*1������һ��ջ�������ǳ�Ϊ��Сջ��ԭ����ջ���ǳ�Ϊ����ջ��

2����Сջ������ջԪ�ظ���һ����ͬ����Сջ��ջ��Ԫ��Ϊ����ջ������Ԫ�ص���Сֵ��

3������ջ��ջһ��Ԫ��A����Сջ��Ҫ�����Ԫ������Сջջ��Ԫ��B�Ƚϣ����AС��B������Сջ��ջA��������Сջ��ջB��

4��������ջ��ջһ��Ԫ��ʱ����СջҲͬʱ��ջһ��Ԫ�ء�
*/
using namespace std;

stack<int> dataStack;
stack<int> minStack;

int main() 
{
    int n;
    while(cin>>n)
    {
        if(!minStack.empty() && minStack.top() <= n)
        {
            dataStack.push(n);
            minStack.push(minStack.top());
        }
        else
        {
            dataStack.push(n);
            minStack.push(n);
        }
        
        printf("��ǰջ����СԪ��Ϊ��%d\n",minStack.top());
    }
    return 0;
}