#include <iostream>
#include <string>
#include <vector>
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
//KMP
int KMPstrStr(const string s1, const string s2)
{
	int i = 0;
	int j = 0;
	vector<int> next;
	GetNext(s2,next);
	int n1 = s1.length();
	int n2 = s2.length();
	while(i < n1 && j < n2)
	{
		if(j==-1 || s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			j=next[j];
		}
	}
	if(j == s2.length())
		return i - j;
	else
		return -1;
}
void GetNext(string p,vector<int> &next)
{
	next.resize(p.length());
	next[0]=-1;
	int k=-1;
	int j=0;
	while(j<p.length()-1)
	{
		if(k==-1 || p[j]==p[k])
		{
			++j;
			++k;
			if(p[j]!=p[k])
				next[j]=k;
			else
				next[j]=next[k];
		}
		else
			k=next[k];
	}
}


