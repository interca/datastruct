#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
}List;
void insert(List*plist,int number);
void print(Node*head);
int main(){
    int n,number,i;
    List list;
    list.head=NULL;

    printf("input a number:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&number);
        insert(&list,number);
    }
    print(list.head);
    return 0;
}
void insert(List*plist,int number){
    Node*p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->value=number;
    if(plist->head==NULL){
        plist->head=p;
    }
    else {
        p->next=plist->head;
        plist->head=p;
    }
}
void print(Node*head){
    for(;head;head=head->next){
        printf("%d ",head->value);
    }
}