#include <iostream>
#include <string>
using namespace std;
//字符串s2在s1中的位置（暴力匹配）
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
			i = i - j + 1; //一旦不匹配，i后退，j归零
			j = 0;				
		}
	}
	if(j == s2.length())
		return i - j;
	else
		return -1;
}


