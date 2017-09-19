#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool rever(string name,string pwd)
{
	int n1 = name.length();
	int n2 = pwd.length();
	int i = 0;
	int j = n2-1;
	if(n1 == n2)
	{
		while(name[i++] == pwd[j--] && i<n1 && j>=0);
		if(i==n1 && j==-1)
			return true;
	}
	return false;
}
bool onlyone(string pwd)
{
	int i=0;
	int n = pwd.length();
	while(pwd[i++]>='0' && pwd[i++]<='9' && i<n);
	if(i==n)
		return true;
	i=0;
	while(pwd[i++]>='a' && pwd[i++]<='z' && i<n);
	if(i==n)
		return true;
	i=0;
	while(pwd[i++]>='A' && pwd[i++]<='Z' && i<n);
	if(i==n)
		return true;
	i=0;
	while(!(pwd[i++]>='0' && pwd[i++]<='9') && !(pwd[i++]>='a' && pwd[i++]<='z') && !(pwd[i++]>='A' && pwd[i++]<='Z') && i<n);
	if(i==n)
		return true;
	return false;
}
bool onlytwo(string pwd)
{
	int i=0;
	int n = pwd.length();
	int countdig=0,countalp=0,countAlp=0,count4=0;
	for(int i=0;i<n;i++)
	{
		if(pwd[i]>='0' && pwd[i]<='9' && i<n)
		{
			countdig++;
		}
		if(pwd[i]>='a' && pwd[i]<='z' && i<n)
		{
			countalp++;
		}
		if(pwd[i]>='A' && pwd[i]<='Z' && i<n)
		{
			countAlp++;
		}
		if(!(pwd[i]>='0' && pwd[i]<='9') && !(pwd[i]>='a' && pwd[i]<='z') && !(pwd[i]>='A' && pwd[i]<='Z') && i<n)
		{
			count4++;
		}		
	}
	if((countdig>0 && countalp>0 && !count4) || (countdig>0 && countAlp>0 &&!count4))
		return true;
	return false;
}
bool two(string pwd)
{
	int i=0;
	int n = pwd.length();
	int countdig=0,countalp=0,countAlp=0,count4=0;
	for(int i=0;i<n;i++)
	{
		if(pwd[i]>='0' && pwd[i]<='9' && i<n)
		{
			countdig++;
		}
		if(pwd[i]>='a' && pwd[i]<='z' && i<n)
		{
			countalp++;
		}
		if(pwd[i]>='A' && pwd[i]<='Z' && i<n)
		{
			countAlp++;
		}
		if(!(pwd[i]>='0' && pwd[i]<='9') && !(pwd[i]>='a' && pwd[i]<='z') && !(pwd[i]>='A' && pwd[i]<='Z') && i<n)
		{
			count4++;
		}
	}
	if((countdig>0 && count4>0 && !countalp && !countAlp) || (count4>0 && countAlp>0 && !countalp && !countdig) || (count4>0 && countalp>0 && !countAlp && !countdig))
		return true;
	return false;
}
int main()
{
	char a[]="abccdd";
	cout<<sizeof(a)<<endl;
	cout<<strlen(a)<<endl;
	string name,pwd;
	cin>>name>>pwd;

	if(pwd.length()<8 || name == pwd || rever(name,pwd) || onlyone(pwd))
		cout<<0<<endl;
	else if(pwd.length()>8 && onlytwo(pwd))
		cout<<1<<endl;
	else if(pwd.length()>8 && two(pwd))
		cout<<2<<endl;
	else 
		cout<<3<<endl;
	return 0;
}




