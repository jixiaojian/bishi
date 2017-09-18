#include <queue>  
#include <cstring>  
#include <cstdio>  
using namespace std;  
//�ṹ��  
struct Node  
{  
    char szName[20];  
    int  priority;  
    Node(int nri, char *pszName)  
    {  
        strcpy(szName, pszName);  
        priority = nri;  
    }  
};  
//�ṹ��ıȽϷ��� ��дoperator()  
struct NodeCmp  
{  
    bool operator()(const Node &na, const Node &nb)  
    {  
        if (na.priority != nb.priority)  
            return na.priority <= nb.priority;  
        else  
            return strcmp(na.szName, nb.szName) > 0;  
    }  
};  
void PrintfNode(Node &na)  
{  
    printf("%s %d\n", na.szName, na.priority);  
}  
int paidui()  
{  
    //���ȼ�����Ĭ����ʹ��vector���������ײ����ݽṹΪ�ѡ�  
    priority_queue<Node, vector<Node>, NodeCmp> a;  
  
    //��5���˽����.�����ȼ�����  --1, "С��" 3, "С��" 5, "С�� "5, "С̷"
    a.push(Node(5, "С̷"));  
    a.push(Node(3, "С��"));  
    a.push(Node(1, "С��"));  
    a.push(Node(5, "С��"));  
  
    //��ͷ��2���˳���  
    PrintfNode(a.top());  //"5, "С̷"
    a.pop();  
    PrintfNode(a.top());  //5, "С��
    a.pop();  
    printf("--------------------\n");  
  
    //�ٽ���3����  
    a.push(Node(2, "С��"));  
    a.push(Node(2, "Сǿ"));  
    a.push(Node(3, "С��"));  
  
    //�����˶����γ���  
    while (!a.empty())  
    {  
        PrintfNode(a.top());  
        a.pop();  
    }  
  
    return 0;  
}  