#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
using namespace std;
//Unix路径简化
//   "/home/", => "/home"
//   "/a/./b/../../c/", => "/c"
/*重复连续出现的'/'，只按1个处理，即跳过重复连续出现的'/'；
如果路径名是"."，则不处理；
如果路径名是".."，则需要弹栈，如果栈为空，则不做处理；
如果路径名为其他字符串，入栈。
最后，再逐个取出栈中元素（即已保存的路径名）
*/
string fun(string path)
{
	if(path.length()==0)
		return 0;
	list<string> stk;
	string ret;
	int i=0;
	while(i<path.length())
	{
		int index=i;
		string temp;
		while(i<path.length() && path[i]!='/')
		{
			temp+=path[i];
			i++;
		}
		if(index!=i)
		{
			if(temp.compare(".")==0)//"."返回当前目录，则什么都不做。
			{
				continue;
			}
			else if(temp.compare("..")==0)//".."返回上层目录
			{
				if(!(stk.empty()))
					stk.pop_back();
			}
			else
				stk.push_back(temp);
		}
		i++;
	}
	while(!(stk.empty()))
	{
		ret+="/"+stk.front();
		stk.pop_front();
	}
	if(ret.length()==0)
		return "/";
	return ret;
}
int main()
{
	string  path;
	cin>>path;
	cout<<fun(path)<<endl;
	return 0;
}