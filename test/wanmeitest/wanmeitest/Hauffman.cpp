/** ������������ **/
#include<stdio.h>
#include<stdlib.h> 
#define LENGTH 6

typedef int ElemType;  

typedef struct HuffmanTreeNode{  
    ElemType data;  //���������нڵ��Ȩֵ
    struct HuffmanTreeNode* left;  
    struct HuffmanTreeNode* right;  
}HuffmanTreeNode,*PtrHuffman;  


/**
 * ������������
 */
PtrHuffman createHuffmanTree(ElemType arr[])
{
    PtrHuffman ptrArr[LENGTH];
    PtrHuffman ptr,pRoot=NULL;  

    for (int i = 0; i < LENGTH; i++)
	{  //��ʼ���ṹ��ָ������,������ÿһ��Ԫ��Ϊһ���ṹ��ָ������
        ptr = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));  
        ptr->data = arr[i];  
        ptr->left = ptr->right = NULL; 
        ptrArr[i] = ptr;
    }
    
    for(int i = 1; i < LENGTH; i++)
	{  //���� n-1 ��ѭ��������������  
        //k1��ʾɭ���о�����СȨֵ�����������±�,k2Ϊ����С���±�
        int k1 = -1, k2;
        for(int j = 0; j < LENGTH; j++)
		{  
            if (ptrArr[j] != NULL && k1 == -1)
			{  
                k1 = j;  
                continue;  
            }  
            if (ptrArr[j] != NULL){  
                k2 = j;  
                break;  
            }  
        }  
        //��ָ�������е�ָ��ָ�����Сֵ��ֵ��������Ϊk1��,��Сֵ��ֵ��������Ϊk2��
        for (int j = k2; j < LENGTH; j++){
            if(ptrArr[j] != NULL){
                if(ptrArr[j]->data < ptrArr[k1]->data){
                    k2 = k1;
                    k1 = j;
                }else if(ptrArr[j]->data < ptrArr[k2]->data){
                    k2 = j;
                }
            }
        }
        //����СȨֵ���ʹ���СȨֵ������һ������,pRootָ���������
        pRoot = (PtrHuffman)malloc(sizeof(HuffmanTreeNode));
        pRoot->data = ptrArr[k1]->data + ptrArr[k2]->data;
        pRoot->left = ptrArr[k1];
        pRoot->right = ptrArr[k2];

        ptrArr[k1] = pRoot; //��ָ��������ָ�븳��ptrArrָ��������k1λ��
        ptrArr[k2] = NULL; //k2λ��Ϊ��
    }

    return pRoot;
}

/**
 * �������������Ȩ·������WPL
 */
ElemType calculateWeightLength(PtrHuffman &ptrTree,int len){
    if(ptrTree==NULL){ //��������0
        return 0;
    }else{
        if(ptrTree->left==NULL && ptrTree->right==NULL){ //���ʵ�Ҷ�ӽڵ�
            return ptrTree->data * len;
        }else{
            return calculateWeightLength(ptrTree->left,len+1) + calculateWeightLength(ptrTree->right,len+1); //���µݹ����
        }
    }
}


/**
 * ������������(Ҷ�ӽڵ㰴����ʽ���δ�ӡ�����)
 */
void HuffmanCoding(PtrHuffman &ptrTree,int len){
    //��̬�ֲ������൱��ȫ�ֱ���(ֻ��ֻ��������������ܷ���,�������������Ǻ�ȫ�ֱ�������)�����˳�֮���������,����ֻ�ڵ�һ�ν����ʱ������ʼ��,�Ժ��������ʼ�����,����ԭ����ֵ
    static int arr[20];  
    if(ptrTree != NULL){
        if(ptrTree->left==NULL && ptrTree->right==NULL){
           printf("���ȨֵΪ%d�ı���: ", ptrTree->data); 
           for(int i = 0; i < len; i++){
               printf("%d", arr[i]);      
           }   
           printf("\n"); 
        }else{
            arr[len] = 0;
            HuffmanCoding(ptrTree->left,len+1);
            arr[len] = 1;
            HuffmanCoding(ptrTree->right,len+1);
        }
    }
}


/**
 * ��ӡ���������и����ڵ�ĺ��ӽڵ�
 * ��ΪҶ�ӽڵ�,��ֻ��ʾ��ʾ��Ϣ
 * @param node ��Ҫ��ʾ���ӽڵ�ĸ��ڵ�
 */
void printHuffmanTreeChildNode(PtrHuffman node){
    if(node->left == NULL && node->right == NULL){
        printf("x=%d�ǹ��������е�Ҷ�ӽڵ�",node->data);
        printf("\n\n");
        return;
    }
    if(node->left != NULL){
        printf("x=%d�ڹ��������е����ӽڵ���lchild=%d",node->data,node->left->data);
        printf("\n");
    }
    if(node->right != NULL){
        printf("x=%d�ڹ��������е��Һ��ӽڵ���rchild=%d",node->data,node->right->data);
        printf("\n");
    }
    printf("\n");
}


/**
 * �����ӡ���������Ľڵ�
 */
void midOrderprintHuffmanTreeNode(PtrHuffman &pRoot){
    if(pRoot==NULL){
        return;
    }else{
        midOrderprintHuffmanTreeNode(pRoot->left);
        printf("%d ",pRoot->data);
        midOrderprintHuffmanTreeNode(pRoot->right);
    }
}

/**
 * �����ӡ���������Ľڵ�
 */
void PreOrderprintHuffmanTreeNode(PtrHuffman &pRoot){
    if(pRoot==NULL){
        return;
    }else{
        printHuffmanTreeChildNode(pRoot); //���δ�ӡ���������и����ڵ�ĺ��ӽڵ�
        PreOrderprintHuffmanTreeNode(pRoot->left);
        PreOrderprintHuffmanTreeNode(pRoot->right);
    }
}


/**
 * ���Գ������
 */
int main(){
    ElemType arr[] = {3,9,5,12,6,15};

    PtrHuffman pRoot = createHuffmanTree(arr);  //����ָ������������ڵ��ָ��

    printf("==========�����ӡ���������ڵ�����==========\n");
    midOrderprintHuffmanTreeNode(pRoot);
    printf("\n\n");

    printf("==========�����ӡ���������ڵ��ϵ==========\n");
    PreOrderprintHuffmanTreeNode(pRoot);

    printf("==========�����Ȩ·������==========\n");
    printf("WeightLength=%d\n",calculateWeightLength(pRoot,0));
    printf("\n");

    printf("==========���ڵ�Ĺ�����������==========\n");
    HuffmanCoding(pRoot,0);

    fprintf(stdout,"\n");
    
    return 0;
} 
