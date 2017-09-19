#include <iostream>
#include <string>
#include <vector>  

using namespace std;

string game(string &str)
{
	if(str.length()==0)
        return "";
    else if(str.length()==1)
    {
        for(int i=1;i<=26;i++)
    	if(str[0]==i)
            str= "a"+i-1;
    }
    return str;
}
int main()
{
    string str;
    while(cin>>str)
    {
    	cout<<game(str)<<endl;
    }
    
	return 0;
}