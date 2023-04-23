#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int value;
    struct node * left;
    struct node*right;
}Node;

//��ͷ���
Node *head;

//��������������
void creatTree(int a){
   Node*n = (Node*)malloc(sizeof(Node));
   n->left = n->right = NULL;
   n->value = a;
   if(head == NULL){
     head = n;
   }else {
      Node*h = head;
      while(1){
        if(a > h->value){
            if(h->right ==NULL){
                h->right = n;
                break;
            }else h = h->right;
        }else {
            if(h ->left == NULL){
                h ->left =  n;
                break;
            }else h = h ->left;
        }
      }
   }
}
//Ѱ�ҹؼ���
void find(int x){
    Node * h = head;
    while(h !=NULL){
        if(x > h ->value)h = h->right;
        else if(x < h->value)h = h->left;
        else {
            printf("�ҵ���\n");
            return;
        }
    }
    printf("û���ҵ�\n");
}

void midPrintf(Node*h){
    if(h == NULL)return;
    midPrintf(h->left);
    printf("%d ",h->value);
    midPrintf(h->right);
}
//���������ֵ
 int findmax(Node *root){
    while(root->right!=NULL)root=root->right;
    return root->value;
}


//ɾ��
Node* delete(Node*root,int x){
   Node*temp = (Node*)malloc(sizeof(Node));
   if(root == NULL)return root;
   //Ҫɾ�������ȵ�ǰ���С  �ݹ�ɾ�����
   if(root->value > x)root->left = delete(root->left,x);
   else if(root ->value <x)root->right = delete(root->right,x);
   //Ҫɾ���ľ��ǵ�ǰ���
   else {
       //�ҵ�����������ֵ���ǵ�ǰ���  Ȼ��ɾ������������ֵ
     if(root->left !=NULL && root->right !=NULL){
         temp->value = findmax(root->left);
         root->value = temp->value;
         root->left = delete(root->left,temp->value);
     }else {
        if(root->left == NULL)root = root->right;
        else root = root->left;
     }
   }
   return root;
}
int main(){
    int a[10] = {1,3,5,-1,4,2,-11,20,-3,7};
    for(int i = 0 ; i < 10 ; i ++){
        creatTree(a[i]);
    }
    int x;
    while(1){
        int choice;
        printf("1-���ҹؼ��� ,2-�������  3-ɾ���ؼ���\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
              printf("����Ҫ���ҵ�����\n");
              scanf("%d",&x);
              find(x);
              break;
            case 2:
              midPrintf(head);
              printf("\n");
              break;
            case 3:
              printf("����Ҫɾ��������\n");
              scanf("%d",&x);
              delete(head,x); 
              break;
        }
    }
}
