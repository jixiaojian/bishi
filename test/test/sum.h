#include <iostream>
#include <vector>
#include <array>
using namespace std;

typedef struct BSTNode
{
	int data;
	struct BSTNode *Lchild,*Rchild;
}BSTNode,*BSP;

vector<int> twosumsort(vector<int> arr,int k);
vector<int> threesumsort(vector<int> arr,int k);
bool isValid(string s);
int strStr(string s1, string s2);
void mergearray(int nums1[],int m,int nums2[],int n);
double mypow(double d,int n);
vector<string> Parenthesis(int n);
bool isPalindrome(string s);
char ToLower(char c);
void setMatrixZero(vector<vector<int>> &matrix);
void getMaxSeq(int val[], int count) ;
int maxSubArray(vector<int>& nums);
int paidui();
int findKthLargest(vector<int>& nums, int k);
int heap();
void heapsort(int a[],int n);
int sortcompare();
int canArrangeWords(int num,char** arr);
BSP create(int data[],int n);
void medorder(BSP T,vector<int> &a);
int callujingmulti(int num,vector<int> values,vector<vector<int>> edges);
int SJF();
bool isnumber(string str);