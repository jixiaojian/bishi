#include <iostream>
#include <string>
using namespace std;

bool isAlpha(char c);
bool isPalindrome(string s)
{
	int i=0;
	int j=s.length()-1;
	if(j==0)
		return false;
	while(i<j)
	{
		while(i<j && !isAlpha(s[i]))
			i++;
		while(i<j && !isAlpha(s[j]))
			j--;
		if(tolower(s[i])!=tolower(s[j]))
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}
bool isAlpha(char c)
{
	if(c >='a' && c <= 'z' || c >='A' && c <= 'Z' || c >='0' && c <= '9' )
		return true;
	else
		return false;
}
char ToLower(char c)
{
	if(c >='A' && c <= 'Z')
		c += 32;
	return c;
}