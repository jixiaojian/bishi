#include <iostream>
#include <string>
#include <vector>
using namespace std;

//给一个整数n，输出n对小括号所能组成的所有正常闭合的组合。用递归实现所有情况
void Gofor(int l_n, int r_n, string s, int n, vector<string>& result){
// n 是括号的总数
// 如果"("的数量和")"一样, 并且")"的数量和总数一样，那么就有一个答案就出现了
    if (l_n == r_n && r_n == n)     
        result.push_back(s);                                  
// 如果"("的数量比总数小，那么加一个"("
    if (l_n < n)    
        Gofor(l_n+1, r_n, s+"(", n, result);
// 如果")"的数量比"("的数量小, 那么加一个")"
    if (r_n < l_n)                  
        Gofor(l_n, r_n+1, s+")", n, result);
}
 
vector<string> Parenthesis(int n)
{
    vector<string> result(0);
    if (n == 0) return result;
// 从一个"("开始
    string start = "(";
// 我们从一个"("开始，那么left_number = 1，right_number = 0
    int left_number = 1; 
    int right_number = 0; 
// 开始递归
    Gofor(left_number, right_number, start, n, result);
    return result;
}
/*
vector<string> generateParenthesis(int n) 
{
        vector<string> aList(0);
        if(n <= 0)
		{
            return aList;
        }
         getList(n,n,"",aList);
         return aList;

    }
 void getList(int left,int right,string curStr,vector<string> aList)
 {
        if(left > right){
            return;
        }
        if(left == 0&&right == 0){
            aList.push_back(curStr);
        }
        if(left > 0){
            getList(left-1, right, curStr+"(", aList); 
        }
        if(right > 0){
            getList(left, right-1, curStr+")", aList);
        }

    }
*/