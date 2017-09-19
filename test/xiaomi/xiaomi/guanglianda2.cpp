#include <iostream>
#include <string> 
#include <map>
#include <unordered_map>
#include <hash_map>
#include <iterator>
#include <vector>
using namespace std;

//������������k���ڵ�
struct node
{
	int data;
	struct node *next;
};

node* findKth(node *head,unsigned int k)
{
	if(head==NULL)
		return NULL;
	if(k<0)
		return NULL;
	node *p1=head,*p2=head;
	while(k--)
	{
		if(p2->next!=NULL)
		{
			p2=p2->next;
		}
		else
			return NULL;//k��ֵ����������
	}
	while(p2!=NULL)
	{
		p2=p2->next;
		p1=p1->next;
	}
	return p1;


}