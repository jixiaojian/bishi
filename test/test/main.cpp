#include <iostream>
#include <vector>
#include <string>
#include "sum.h"
#include "mergeIntervals.h"
#include "insertIntervals.h"
using namespace std;

extern vector<int> twosum(vector<int> num,int target);
// 对指针p和q之间的所有字符逆序
void ReverseWord(char* p, char* q)
{
    while(p < q)
    {
        char t = *p ;
        *p++ = *q ;
        *q-- = t ;
    }
}

// 将句子按单词逆序
char* ReverseSentence(char* s)
{
    // 这两个指针用来确定一个单词的首尾边界
    char* p = s ; // 指向单词的首字符
    char* q = s ; // 指向空格或者 '\0'

    while(*q != '\0')
    {
        if (*q == ' ')
        {
            ReverseWord(p, q - 1) ;
            q++ ; // 指向下一个单词首字符
            p = q ;
        }
        else
            q++ ;
    }

    ReverseWord(p, q - 1) ; // 对最后一个单词逆序
    ReverseWord(s, q - 1) ; // 对整个句子逆序

    return s ;
}
char* rever(char *s)
{
	char* result=(char*)malloc(sizeof(char)*strlen(s));
	//char* result = s;
	for(int i = 0;i < strlen(s);i++)
	{
		if(s[i] != ' ')
			continue;
		for(int j = 0;j<i;j++)
			{
				result[strlen(s) - i+j] = s[j];
		    }
	}
	return result;
}
char* reverword(char* s)
{
	/*
	char *p = s;
	char *q = s;
	while(*q)
	{
		++q;
	}
	q--;
	while(p < q)
	{
		char temp = *p;
		*p++ = *q;           //
		*q-- = temp;
	}
	*/
	int mid = strlen(s)/2;
	char temp;
	for(int i = 0;i < mid;i++)
	{
		temp = s[i];
		s[i] = s[strlen(s)-1-i]; 
		s[strlen(s)-1-i] = temp;
	}
	return s;
}
char find_first_not_repeat_char(char *str)
{
    if (str == NULL)
        return '\0';

    int table[256] = {0};
    for(char *p = str; *p != '\0'; p++){
        table[*p]++;
    }

    for(char *p = str; *p != '\0'; p++){
        if (table[*p] == 1)
            return *p;
    }

    return '\0';
}
int main()
{
	//isnumber
	string isnmb = "  +.3e 1";
	cout<<isnumber(isnmb)<<endl;
	//mergeIntervals,insertIntervals
	Solution A;
	Solution2 A2;
	vector<Interval> test,mergeIntervals,insertIntervals;
	test.push_back(Interval(1,3));
	test.push_back(Interval(2,6));
	test.push_back(Interval(8,10));
	test.push_back(Interval(15,18));
	mergeIntervals = A.merge(test);
	insertIntervals = A2.insert(test,Interval(4,9));
	//SJF
	SJF();
	//路径相乘最大
	vector<int> values;
	values.push_back(-1);
	values.push_back(2);
	values.push_back(3);
	vector<vector<int>> edges;
	vector<int> edge;
	edge.push_back(1);
	edge.push_back(2);
	edges.push_back(edge);
	edge.clear();
	edge.push_back(1);
	edge.push_back(3);
	edges.push_back(edge);
	cout<<callujingmulti(3,values,edges)<<endl;
	//BST
	int bst[15];
	for(int i = 0;i < 15; i++)
	{
		bst[i] = i+1;
	}
	BSP T = (BSP)malloc(sizeof(BSTNode));
	T = create(bst,sizeof(bst)/4);
	min(bst[0],bst[1]);
	vector<int> bstvector;
	medorder(T,bstvector);        //中序遍历，按递增输出
	//worddingzhen
	char *arrword[]={"abcd","defg","ghij","jkl","lkn"};
	canArrangeWords(5,arrword);
	int a1=5;
	a1+=a1-=a1*a1;//从右向左
	//a1+= a1*a1 -=a1;
	cout<<a1<<endl; //40
	int a2=0,b=1,c=2;
	cout<<(a2 || b + c && b == c)<<endl;  //true+true=true 与2不相等 返回false.若c=1,true==1,返回true
	//快速、归并和堆排序比较
	sortcompare();
	//myheap
	int a[]={50,36,66,76,95,12,25,36};
	heapsort(a,sizeof(a)/4);
	//STLheap
	heap();
	//priority_queue
	paidui();	
	//GetMaxSeqsum
	vector<int> nums;
	int x;
	while(cin>>x)
		nums.push_back(x);
	cout<<findKthLargest(nums,2)<<endl; 
	cout<<maxSubArray(nums)<<endl;

	int val[]={-23,17,-7,11,-21,-34};
	//int val[]={-5,20,-4,10,-18};
	getMaxSeq(val, sizeof(val)/4); 

	//setMatrixZero(vector<vector<int>> &matrix)
	vector<vector<int>> matrix;
	vector<int> one;
	one.push_back(0);
	one.push_back(1);
	one.push_back(2);
	one.push_back(3);
	vector<int> two;
	two.push_back(1);
	two.push_back(1);
	two.push_back(2);
	two.push_back(3);
	vector<int> three;
	three.push_back(1);
	three.push_back(1);
	three.push_back(2);
	three.push_back(0);
	matrix.push_back(one);
	matrix.push_back(two);
	matrix.push_back(three);
	setMatrixZero(matrix);
	int m = matrix.size();
	int n = matrix[0].size();
	for(int i =0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	//palindrome回文
	cout<<ToLower('A')<<endl;
	string palindrome = "A man,a plan,a canal:Panama";
	cout<<isPalindrome(palindrome)<<endl;
	//Parenthesis
	vector<string> parentese = Parenthesis(2);
	for(int i=0;i<parentese.size();i++)
		cout<<parentese[i]<<endl;
	//mypow
	cout<<mypow(0,2)<<endl;
	//mergearrays
	int n1[9] = {1,4,5,9};
	int n2[5] = {2,3,6,8,10};
	mergearray(n1,4,n2,5);
	for(int i=0;i<9;i++)
		cout<<n1[i]<<" ";
	cout<<endl;
	//strStr()
	string s1 = "abcdefg";
	string s2 = "fgd";
	cout<<strStr(s1,s2)<<endl;

	//valid
	string valid = "({[()]}";
	string Invalid = "{[())}";
	cout<<isValid(valid)<<endl;
	cout<<isValid(Invalid)<<endl;

	//threesum
	vector<int> arr,result3;
	arr.push_back(-1);
	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(-1);
	arr.push_back(-4);
	arr.push_back(-2);
	result3 = threesumsort(arr,0);
	int number=0;
	for(int i =0;i<result3.size();i++)
	{
		cout<<result3[i]<<" ";
		number++;
		if(number%3 == 0)
			cout<<endl;
	}
	//reverword
	char s[11]="helloworld";//不能用char *s="helloworld"
	char* r = reverword(s);
	cout<<r<<endl;
	char sreverse[100]="hello world ni hao";
	cout<<ReverseSentence(sreverse)<<endl;

	//find_first_not_repeat_char
	char* str="abcdba";
	char re = find_first_not_repeat_char(str);
	cout<<re<<endl;
	//twosum
	vector<int> num,result;
	num.push_back(2);
	num.push_back(7);
	num.push_back(4);
	num.push_back(5);
	int target = 9;
	result = twosum(num,target);
	for(int i =0;i<result.size();i++)
	{
		cout<<result[i]<<" ";
	}
}