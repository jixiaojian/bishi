#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	
	while(n)
	{
        if(n<=0)
        { 
            cout<<"error";
        	return 0;
        }
      else
      {
			cout<<str;
            n--;
      }
	}
  cout<<endl;
  return 0;
}