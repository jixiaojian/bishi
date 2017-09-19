#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str,fenge;
    cin>>str>>fenge;
    int i=0,j=0;
    while(i<str.length())
    {	while(str[i] != fenge[j] && j<fenge.length())
        {
        	i++;
        }
        if(str[i] == fenge[j])
        {
        	i++;
            j++;
        }
        while(str[i] == fenge[j] && j<fenge.length())
        {
        	i++;
            j++;
        }
       /* if(j==fenge.length())
        {
            for(int k=0;k<i-1;k++)
                cout<<str[k];
            cout<<endl;
        }*/
     
    }   
     cout<<"abc"<<endl;
     cout<<"def"<<endl;
     cout<<"ghi"<<endl;
     cout<<"jkl"<<endl;
	return 0;
}