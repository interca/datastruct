#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    struct tree*left;
    struct tree*right;
    int value;
}Tree;
typedef struct root{
    Tree*head;
}Root;
typedef struct node{
    Tree*jie;
    struct node*next;
}Node;
typedef struct list{
    Node*head;
}List;
void insert(Root*plist,int number);//插入
Tree*delect(Tree*head,int number);//删除
Tree*findmax(Tree*head);//最大值
Tree*findmin(Tree*head);//最小值
void printftree(Tree*head);//打印树
void push(List*plist,Tree*jie);//将结点压入堆栈
Tree* pop(List*plist);//抛出堆栈
int main(){
    int i,number,choice,n;
    Root root;
    root.head=NULL;

    printf("input n:\n");
    scanf("%d",&n);
    printf("creat a tree:\n");
    for(i=0;i<n;i++){
        scanf("%d",&number);
        insert(&root,number);
    }

    while(1){
        printf("input your choice:1-insert,2-delect,3-findmax,4-findmin,5-printftree\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("input a number:\n");scanf("%d",&number);insert(&root,number);break;
            case 2:printf("input a number");scanf("%d",&number);delect(root.head,number);break;
            case 3:printf("THE max is %d\n",findmax(root.head)->value);break;
            case 4:printf("The min is %d\n",findmin(root.head)->value);break;
            case 5:printftree(root.head);printf("\n");break;
        }
    }
    return 0;
}
Tree*delect(Tree*head,int number){
    Tree*temp;
    if(head==NULL)printf("没有找到");
    else if(number>head->value){
        head->right=delect(head->right,number);
    }
    else if(number<head->value){
        head->left=delect(head->left,number);
    }
    else{
         if(head->right&&head->left){
              temp=findmax(head->left);
              if(temp!=NULL){
              head->value=temp->value;
              head->left=delect(head->left,head->value);
            }else{
                temp=findmin(head->right);
                head->value=temp->value;
                head->right=delect(head->right,head->value);
            }
         }
         else{//只有一个儿子或者没有儿子
                temp=head;
                if(head->right==NULL){
                    head=head->left;
                }else{
                    head=head->right;
                }
                free(temp);
         }
    }
    return head;
}
Tree*pop(List*plist){
    Node*p=plist->head;
    plist->head=plist->head->next;
    return p->jie;
}
void push(List*plist,Tree*jie){
    Node*p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->jie=jie;
    if(plist->head==NULL){
        plist->head=p;
    }
    else {
        p->next=plist->head;
        plist->head=p;
    }
}
void printftree(Tree*head){
    List list;
    list.head=NULL;
    while(head||list.head){
        while(head){
            push(&list,head);
            head=head->left;
        }
        if(list.head){
            head=pop(&list);
            printf("%d ",head->value);
            head=head->right;
        }
    }
}
Tree*findmin(Tree*head){
    while(head->left){
        head=head->left;
    }
    return head;
}
Tree*findmax(Tree*head){
    while(head->right){
        head=head->right;
    }
    return head;
}
void insert(Root*plist,int number){
    Tree*p=(Tree*)malloc(sizeof(Tree));
    p->value=number;
    p->left=p->right=NULL;
    if(plist->head==NULL){
        plist->head=p;
    }
    else{
        Tree*temp=plist->head;
        while(1){
            if(number>temp->value){
                if(temp->right==NULL){
                    temp->right=p;break;
                }
                else {
                    temp=temp->right;
                }
            }
            else{
                if(temp->left==NULL){
                    temp->left=p;break;
                }
                else{
                    temp=temp->left;
                }
            }
        }
    }
}
