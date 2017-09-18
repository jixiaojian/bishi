#include <iostream>
#include <string>
#include <vector>
using namespace std;

//��һ������n�����n��С����������ɵ����������պϵ���ϡ��õݹ�ʵ���������
void Gofor(int l_n, int r_n, string s, int n, vector<string>& result){
// n �����ŵ�����
// ���"("��������")"һ��, ����")"������������һ������ô����һ���𰸾ͳ�����
    if (l_n == r_n && r_n == n)     
        result.push_back(s);                                  
// ���"("������������С����ô��һ��"("
    if (l_n < n)    
        Gofor(l_n+1, r_n, s+"(", n, result);
// ���")"��������"("������С, ��ô��һ��")"
    if (r_n < l_n)                  
        Gofor(l_n, r_n+1, s+")", n, result);
}
 
vector<string> Parenthesis(int n)
{
    vector<string> result(0);
    if (n == 0) return result;
// ��һ��"("��ʼ
    string start = "(";
// ���Ǵ�һ��"("��ʼ����ôleft_number = 1��right_number = 0
    int left_number = 1; 
    int right_number = 0; 
// ��ʼ�ݹ�
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