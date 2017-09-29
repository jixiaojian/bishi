#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetNext(string p,vector<int> &next);

int KMPstrStr(const string s1, const string s2)
{
	int i = 0;
	int j = 0;	
	vector<int> next;
	GetNext(s2,next);
	//next = GetNext(s2);
	int n1 = s1.length();
	int n2 = s2.length();
	while((i < n1) && (j < n2))
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
	//int next[10000];
	next.resize(p.length());
	if(p.length()<=0)
		return;
	next[0]=-1;
	int k=-1; //Ç°×º
	int j=0;  //ºó×º
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
	//return next;
}
int main()
{
	string s1,s2;
    cin>>s1>>s2;
    cout<<KMPstrStr(s1, s2)<<endl;
	return 0;
}