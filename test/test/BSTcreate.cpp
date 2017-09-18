#include <iostream>
#include <vector>
using namespace std;

typedef struct BSTNode
{
	int data;
	struct BSTNode *Lchild,*Rchild;
}BSTNode,*BSP;

BSP insert(BSP T,BSP s)
{
	if(T==NULL)
		return s;
	else if(s->data == T->data)
	{
		free(s);
		return T;
	}
	else if(s->data < T->data)
		T->Lchild = insert(T->Lchild,s);
	else
		T->Rchild = insert(T->Rchild,s);
	return T;
}
BSP create(int data[],int n)
{
	BSP T = NULL;
	for(int i = 0; i < n; i++)
	{
		BSP s = (BSP)malloc(sizeof(BSTNode));
		s->data = data[i];
		s->Lchild = NULL;
		s->Rchild = NULL;
		T = insert(T,s);
	}
	return T;
}
BSP search(BSP T,int key)
{
	if(T== NULL)
		return NULL;
	if(key == T->data)
		return T;
	else if(key < T->data)
		return search(T->Lchild,key);
	else
		return search(T->Rchild,key);
}

void medorder(BSP T,vector<int> &a)
{
	//vector<int> a;
	if(T== NULL)
		return;
	medorder(T->Lchild,a); //◊Û
	a.push_back(T->data);  //∏˘
	medorder(T->Rchild,a); //”“

}