#include <iostream>
 
struct Node
{
        int key;
        Node *left;
        Node *right;
};
 
bool isBSTUtil(Node * node, int min, int max);
 
//判断是否为BST
bool isBST(Node * node )
{
        return(isBSTUtil( node, INT_MIN, INT_MAX));
}
 
//如果是一颗二叉查找树，且值范围在[min, max]，则返回true
bool isBSTUtil(Node * node , int min , int max )
{
        //空树也是BST
        if ( node == NULL)
               return true;
 
        //如果节点值违反了最大/最小约束条件，则不是BST
        if ( node->key < min || node->key > max)
               return false;
 
        //递归检查子树
        return  isBSTUtil( node->left, min, node->key - 1) &&
              isBSTUtil( node->right, node->key + 1, max);
}
 
 
// 创建一个新的BST节点
Node *createNewNode(int item )
{
        Node *temp = new Node;
       temp->key = item;
       temp->left = temp->right = NULL;
        return temp;
}
  
int test()
{
    /* tree1的定义
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
 
        /* tree2的定义
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
