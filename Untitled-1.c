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
//����������
 void CreateBiTree(Root*plist);
//ǰ�к������
 void  PreOrderTraverse(BiTree*T);
 void  InOrderTraverse(BiTree *T);
 void PostOrderTraverse(BiTree *T);
 //����������
 int NodeCount(BiTree*T);
 //����Ҷ�ӽڵ�����
 int LeadCount(BiTree *T);
 //�������
 int countdeep(BiTree*T);
 int main(){
     int choice;
    Root root;
    root.head=NULL;
     while(1){
         printf("�������ѡ��1-������������2-ǰ�������3-���������4-����������5-����ڵ㣬6-����Ҷ�ӽڵ㣬7-�������\n");
         scanf("%d",&choice);
          getchar();
         switch(choice){
             case 1:CreateBiTree(&root);break;
             case 2:PreOrderTraverse(root.head);break;
             case 3:InOrderTraverse(root.head);break;
             case 4:PostOrderTraverse(root.head);break;
             case 5:printf("�ڵ�����%d\n",NodeCount(root.head));break;
             case 6:printf("Ҷ�ӽڵ�����%d\n",LeadCount(root.head));break;
             case 7:printf("�����%d\n",countdeep(root.head));break;
         }
     }
     return 0;
 }
int LeadCount(BiTree *T){
    if(T==NULL)  //����ǿ�������0
    return 0;
  if (T->left == NULL && T->right == NULL)
    return 1;         //�����Ҷ�ӽ�㷵��1
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
       printf("����Ҫ��������֣�\n");
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
          printf("����ѡ��1-������������2-�����ұ�����\n");
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