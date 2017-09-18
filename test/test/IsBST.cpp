#include <iostream>
 
struct Node
{
        int key;
        Node *left;
        Node *right;
};
 
bool isBSTUtil(Node * node, int min, int max);
 
//�ж��Ƿ�ΪBST
bool isBST(Node * node )
{
        return(isBSTUtil( node, INT_MIN, INT_MAX));
}
 
//�����һ�Ŷ������������ֵ��Χ��[min, max]���򷵻�true
bool isBSTUtil(Node * node , int min , int max )
{
        //����Ҳ��BST
        if ( node == NULL)
               return true;
 
        //����ڵ�ֵΥ�������/��СԼ������������BST
        if ( node->key < min || node->key > max)
               return false;
 
        //�ݹ�������
        return  isBSTUtil( node->left, min, node->key - 1) &&
              isBSTUtil( node->right, node->key + 1, max);
}
 
 
// ����һ���µ�BST�ڵ�
Node *createNewNode(int item )
{
        Node *temp = new Node;
       temp->key = item;
       temp->left = temp->right = NULL;
        return temp;
}
  
int test()
{
    /* tree1�Ķ���
            4
          /   
         2     5
        / 
       1   3 
	   */
    
       Node *root = createNewNode(4);
       root->left = createNewNode(2);
       root->right = createNewNode(5);
       root->left->left = createNewNode(1);
       root->left->right = createNewNode(3);
 
        if (isBST(root))
              std::cout << "tree1 is BST";
        else
              std::cout << "tree1 is not BST";
 
        /* tree2�Ķ���
            4
          /   
         2     5
        /     /
       1     3
       */
       root = createNewNode(4);
       root->left = createNewNode(2);
       root->left->left = createNewNode(1);
       root->right = createNewNode(5);
       root->right->left = createNewNode(3);
 
        if (isBST(root))
              std::cout << "tree2 is BST";
        else
              std::cout << "tree2 is not BST";

 
        return 0;
}
