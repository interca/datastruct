#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int value;
    struct node * left;
    struct node*right;
}Node;

//树头结点
Node *head;

//创建二插搜索树
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
//寻找关键字
void find(int x){
    Node * h = head;
    while(h !=NULL){
        if(x > h ->value)h = h->right;
        else if(x < h->value)h = h->left;
        else {
            printf("找到了\n");
            return;
        }
    }
    printf("没有找到\n");
}

void midPrintf(Node*h){
    if(h == NULL)return;
    midPrintf(h->left);
    printf("%d ",h->value);
    midPrintf(h->right);
}
//找左边最大的值
 int findmax(Node *root){
    while(root->right!=NULL)root=root->right;
    return root->value;
}


//删除
Node* delete(Node*root,int x){
   Node*temp = (Node*)malloc(sizeof(Node));
   if(root == NULL)return root;
   //要删除的数比当前结点小  递归删除左边
   if(root->value > x)root->left = delete(root->left,x);
   else if(root ->value <x)root->right = delete(root->right,x);
   //要删除的就是当前结点
   else {
       //找到左边子树最大值覆盖当前结点  然后删除左边子树最大值
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
        printf("1-查找关键字 ,2-中序遍历  3-删除关键字\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 : 
              printf("输入要查找的数字\n");
              scanf("%d",&x);
              find(x);
              break;
            case 2:
              midPrintf(head);
              printf("\n");
              break;
            case 3:
              printf("输入要删除的数字\n");
              scanf("%d",&x);
              delete(head,x); 
              break;
        }
    }
}
