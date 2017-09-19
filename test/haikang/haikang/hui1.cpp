#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
using namespace std;
//Unix·����
//   "/home/", => "/home"
//   "/a/./b/../../c/", => "/c"
/*�ظ��������ֵ�'/'��ֻ��1�������������ظ��������ֵ�'/'��
���·������"."���򲻴���
���·������".."������Ҫ��ջ�����ջΪ�գ���������
���·����Ϊ�����ַ�������ջ��
��������ȡ��ջ��Ԫ�أ����ѱ����·������
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
			if(temp.compare(".")==0)//"."���ص�ǰĿ¼����ʲô��������
			{
				continue;
			}
			else if(temp.compare("..")==0)//".."�����ϲ�Ŀ¼
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