#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstdio>
/*1、定义一个栈这里我们称为最小栈，原来的栈我们称为数据栈。

2、最小栈和数据栈元素个数一定相同。最小栈的栈顶元素为数据栈的所有元素的最小值。

3、数据栈入栈一个元素A，最小栈需要拿这个元素与最小栈栈顶元素B比较，如果A小于B，则最小栈入栈A。否则最小栈入栈B。

4、当数据栈出栈一个元素时，最小栈也同时出栈一个元素。
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
        
        printf("当前栈的最小元素为：%d\n",minStack.top());
    }
    return 0;
}