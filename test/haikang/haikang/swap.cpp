#include<iostream>
using namespace std;

void swap_int(int a , int b)
{
   int temp = a;
   a = b;
    b = temp;
}

void swap_str(char*a , char*b)
{
    char*temp = a;
    a = b;
    b = temp;
}

int main(void)
{
    int a = 10;
    int b = 5;
    char*str_a = "hello world";
    char*str_b = "world hello";
    swap_int(a , b);
    swap_str(str_a , str_b);
    printf("%d %d %s %s\n",a,b,str_a,str_b);

    return 0;
}