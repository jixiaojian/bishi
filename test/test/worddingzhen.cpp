#include <iostream>
using namespace std;

int canArrangeWords(int num,char** arr)
{
    // WRITE YOUR CODE HERE
	int count=0;
    while(*arr)
    {
        char *p=*arr;
        while(*p!='\0')
            p++;
		p--;
		char *p1= *++arr;
		count++;
		if(count >= num)
			break;
        if(count < num && p1!= NULL && *p != *p1)
            return -1;
    }
    return 1;        
}