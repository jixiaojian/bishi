#include <iostream>
#include <string>
#include <vector>  

using namespace std;

void upper(char &a)
{
	if(a>='a' && a<='z')
	{
		a=a-32;
	}
}
bool isup(char a)
{
	if(a>='A' && a<='Z')
	{
		return true;
	}
	else
		return false;
}
bool islow(char a)
{
	if(a>='a' && a<='z')
	{
		return true;
	}
	else
		return false;
}
bool isalp(char a)
{
	if(a>='A' && a<='Z' || (a>='a' && a<='z'))
	{
		return true;
	}
	else
		return false;
}
bool isnum(char a)
{
	if(a>='0' && a<='9')
	{
		return true;
	}
	else
		return false;

}
string guard(string str)
{
	int i=1;
	string result;
	str="_"+str+"_";	
	while(i<str.length())
	{
		if(str.length()==3)
		{
			upper(str[i]);
			return str;;
		}
		if(str[i]=='.')
		{
			str[i]='_';
			i++;
			continue;
		}
		if(isup(str[i]))
		{
			i++;
			continue;			
		}
		if(str[i-1]!='_' && !isnum(str[i-1]) && isnum(str[i]))
		{
			str.insert(i,"_");
			i++;
			continue;
		}		
		if(islow(str[i]) && isup(str[i+1]))
		{	
			str.insert(i+1,"_");
		}
		if(isnum(str[i]) && isalp(str[i+1]))
		{	
			str.insert(i+1,"_");
		}
		i++;
	}
	int j=0;
	while(j<str.length())
	{
		upper(str[j]);
		j++;
	}
	return str;
}
int main()
{
	string str;
	while(cin>>str)
	{
		cout<<guard(str)<<endl;
	}	
	return 0;
}