#include <iostream>
#include <string>
using namespace std;
//�ַ���s2��s1�е�λ�ã�����ƥ�䣩
int strStr(string s1, string s2)
{
	int i = 0;
	int j = 0;
	while(i < s1.length() && j < s2.length())
	{
		if(s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1; //һ����ƥ�䣬i���ˣ�j����
			j = 0;				
		}
	}
	if(j == s2.length())
		return i - j;
	else
		return -1;
}


