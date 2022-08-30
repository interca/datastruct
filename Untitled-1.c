#include<stdio.h>
#include<stdlib.h>
typedef struct Binode{
    struct Binode*left;
    struct Binode*right;
    char data;
}BiTree;
typedef struct root{
	BiTree*head;
}Root;
//创建二叉树
 void CreateBiTree(Root*plist);
//前中后序遍历
 void  PreOrderTraverse(BiTree*T);
 void  InOrderTraverse(BiTree *T);
 void PostOrderTraverse(BiTree *T);
 //计算结点数量
 int NodeCount(BiTree*T);
 //计算叶子节点数量
 int LeadCount(BiTree *T);
 //计算深度
 int countdeep(BiTree*T);
 int main(){
     int choice;
    Root root;
    root.head=NULL;
     while(1){
         printf("输入你的选择：1-建立二叉树，2-前序遍历，3-中序遍历，4-后续遍历，5-计算节点，6-计算叶子节点，7-计算深度\n");
         scanf("%d",&choice);
          getchar();
         switch(choice){
             case 1:CreateBiTree(&root);break;
             case 2:PreOrderTraverse(root.head);break;
             case 3:InOrderTraverse(root.head);break;
             case 4:PostOrderTraverse(root.head);break;
             case 5:printf("节点数是%d\n",NodeCount(root.head));break;
             case 6:printf("叶子节点数是%d\n",LeadCount(root.head));break;
             case 7:printf("深度是%d\n",countdeep(root.head));break;
         }
     }
     return 0;
 }
int LeadCount(BiTree *T){
    if(T==NULL)  //如果是空树返回0
    return 0;
  if (T->left == NULL && T->right == NULL)
    return 1;         //如果是叶子结点返回1
  else return LeadCount(T->left) + LeadCount(T->right);

}
 int countdeep(BiTree*T){
     if(T!=NULL){
         int right=countdeep(T->right);
         int left=countdeep(T->left);
         if(right>left)return right+1;
         else return left+1;
     }
     return 0;
 }
 int NodeCount(BiTree*T){
  if(T == NULL ) return 0;
  else return NodeCount(T->left)+NodeCount(T->right)+1;
} 

 void PostOrderTraverse(BiTree *T){
     if(T==NULL){
         printf("#\n");
         return;
     }
    PostOrderTraverse(T->left);
     PostOrderTraverse(T->right);
     printf("%c\n",T->data);
 }
 void InOrderTraverse(BiTree*T){
      if(T==NULL){
         printf("#\n");
         return;
     }
     InOrderTraverse(T->left);
     printf("%c\n",T->data);
     InOrderTraverse(T->right);
 }
 void PreOrderTraverse(BiTree*T){
     if(T==NULL){
         printf("#\n");
         return;
     }
     printf("%c\n",T->data);
    PreOrderTraverse(T->left);
    PreOrderTraverse(T->right);

 }
 void CreateBiTree(Root*plist){
     char data;
       printf("输入要插入的数字：\n");
       scanf("%c",&data);
       BiTree*node=(BiTree*)malloc(sizeof(BiTree));
       node->data=data;
       node->left=node->right=NULL;
       if(plist->head==NULL){
           plist->head=node;
           return;
       }
       int choice;
       BiTree *head=plist->head;
       while(1){
          printf("输入选择，1-插入左子树，2-插入右边子树\n");
          scanf("%d",&choice);
          if(choice==1){
             if(head->left==NULL){
                 head->left=node;
                 break;
             }else head=head->left;
          }else {
               if(head->right==NULL){
                   head->right=node;
                   break;
               }else {
                   head=head->right;
               }
          }
       }
      
 }