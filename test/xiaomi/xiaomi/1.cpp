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
/*	while(cin>>str)
	{
		cout<<guard(str)<<endl;
	}	
*/
	
	string str1="We can insert a string";  
    string str2="a str into ";  
	/*
	cout<<str1.insert(14,str2)<<endl;
	cout<<str1.insert(14,str2,2,9)<<endl;
	cout<<str1.insert(14,"test hello",5)<<endl;
	cout<<str1.insert(14,6,'*')<<endl;


	cout<<str1.replace(3,3,"may")<<endl;
	cout<<str1.replace(3,3,"can could",4,5)<<endl;
	cout<<str1.replace(3,5,"can could",3)<<endl;
	cout<<str1.replace(3,3,5,'*')<<endl;

	cout<<endl;
	*/
    //在字符串指定位置前面插入指定字符串  
    cout <<str1.insert(14,str2)<<endl;  
    //在字符串指定位置前面插入指定字符串的子串（从指定索引开始的指定个数的字符）  
    cout <<str1.insert(14,str2,2,9)<<endl;  
    //插入指定字符串的前n个字符  
    cout <<str1.insert(14,"test hello",5)<<endl;  
    //插入n个相同字符到字符串中  
    cout <<str1.insert(14,6,'*')<<endl;  
      
    //替换指定索引开始的指定长度的子串  
    cout <<str1.replace(3,3,"may")<<endl;  
    //用给定字符串的指定子串来进行替换  
    //如下，实际上使用的是could来进行替换  
    cout <<str1.replace(3,3,"can could",4,5)<<endl;  
    //使用给定字符串的前n个字符来进行替换：can  
    cout <<str1.replace(3,5,"can could",3)<<endl;  
    //使用指定个数的重复字符来进行替换  
    cout <<str1.replace(3,3,5,'*')<<endl;  
      
    string word="We";  
    size_t index=str1.find(word);  
    if(index!=string::npos)  
    //删除指定索引开始的指定长度的字符  
    cout <<str1.erase(index,word.length())<<endl;  
    return 0;  

}