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
    //���ַ���ָ��λ��ǰ�����ָ���ַ���  
    cout <<str1.insert(14,str2)<<endl;  
    //���ַ���ָ��λ��ǰ�����ָ���ַ������Ӵ�����ָ��������ʼ��ָ���������ַ���  
    cout <<str1.insert(14,str2,2,9)<<endl;  
    //����ָ���ַ�����ǰn���ַ�  
    cout <<str1.insert(14,"test hello",5)<<endl;  
    //����n����ͬ�ַ����ַ�����  
    cout <<str1.insert(14,6,'*')<<endl;  
      
    //�滻ָ��������ʼ��ָ�����ȵ��Ӵ�  
    cout <<str1.replace(3,3,"may")<<endl;  
    //�ø����ַ�����ָ���Ӵ��������滻  
    //���£�ʵ����ʹ�õ���could�������滻  
    cout <<str1.replace(3,3,"can could",4,5)<<endl;  
    //ʹ�ø����ַ�����ǰn���ַ��������滻��can  
    cout <<str1.replace(3,5,"can could",3)<<endl;  
    //ʹ��ָ���������ظ��ַ��������滻  
    cout <<str1.replace(3,3,5,'*')<<endl;  
      
    string word="We";  
    size_t index=str1.find(word);  
    if(index!=string::npos)  
    //ɾ��ָ��������ʼ��ָ�����ȵ��ַ�  
    cout <<str1.erase(index,word.length())<<endl;  
    return 0;  

}