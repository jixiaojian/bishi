#include <iostream>
#include <string>
using namespace std;
/*"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
"+.1"  => true
"1."   => true
".34"  => true
两个e/E，两个小数点，两个正负号就是错的
*/
bool isnumber(string str)
{
	if(str.length()<=0)
		return false;
	int i=0,j = str.length()-1;
	while(str[i]==' ')
			i++;
	while(str[j]==' ')
			j--;
	int addnum=0,subnum=0,enumber=0,pointnum=0;
	while(i < j)
	{				
		if((str[i]>='0' && str[i]<='9') && ((str[i+1]>='0' && str[i+1]<='9') || str[i+1]=='e' || str[i+1]=='E'|| str[i+1]=='.'))
		{
				i++;
				if(enumber > 1)
					return false;
				if(str[i+1]=='e' || str[i+1]=='E')
					enumber++;
		}

		else if(str[i]=='+' && ((str[i+1]>='0' && str[i+1]<='9') || str[i+1]=='.'))
			{
				if(addnum>1)
					return false;
				addnum++;
				i++;
			}
		else if(str[i]=='-' && ((str[i+1]>='0' && str[i+1]<='9') || str[i+1]=='.'))
			{
				if(subnum>1)
					return false;
				subnum++;
				i++;
			}
		else if(str[i]=='.' && (str[i+1]>='0' && str[i+1]<='9'))
			{
				if(pointnum>1)
					return false;
				pointnum++;
				i++;
			}
		else
			return false;		
	}
	return true;
}