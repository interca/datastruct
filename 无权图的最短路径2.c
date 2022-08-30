#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int *dist;
int *path;
typedef struct node{
    struct node *next;
    int value;
}Node;
typedef struct list{
    Node*head;
    Node*last;
}List;
typedef struct list1{
    Node*head;
}List1;
void creat(int k,int n);
void insert(int k,int n);
void print(int k,int n);
void push(List*plist,int number);
int pop(List*plist);
void push1(List*plist,int number);
int main(){
    int n,k,l,c1,c2;
    int i;
    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    dist=(int*)malloc(n*sizeof(int));
    path=(int*)malloc(n*sizeof(int));
    creat(k,n);
    for(i=0;i<l;i++){
        scanf("%d%d",&c1,&c2);
        a[c1][c2]=1;
    }
    insert(k,n);
    printf("\n");
    print(k,n);
    return 0;
}
void print(int k,int n){
   List list;
   list.head=NULL;
   int i;
   int number;
   while(1){
       printf("input a number :\n");
       scanf("%d",&number);
       printf("The %d distant %d is %d\n",k,number,dist[number]);
       while(1){
           push1(&list,number);
           if(number==k)break;
           number=path[number];
       }
       while(list.head){
           number=pop(&list);
           printf("%d ",number);
       }
       printf("\n");
   }
}
void insert(int k,int n){
    List list;
    int i;
    list.head=list.last=NULL;
    push(&list,k);
    while(list.head){
        k=pop(&list);
        for(i=0;i<n;i++){
            if(a[k][i]==1&&dist[i]==-1){
            dist[i]=dist[k]+1;
            path[i]=k;
            push(&list,i);
            }
        }
    }
}
int pop(List*plist){
      Node*p=plist->head;
      plist->head=plist->head->next;
      return p->value;
}
void push1(List*plist,int number){
    Node*p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;
    if(plist->head==NULL){
        plist->head=p;
    }
    else {
        p->next=plist->head;
        plist->head=p;
    }
}
void push(List*plist,int number){       //队列
    Node*p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;
    if(plist->head==NULL){
        plist->head=plist->last=p;
    }else {
        plist->last->next=p;
        plist->last=p;
    }
}
void creat(int k,int n){
    int i,j;
    for(i=0;i<n;i++){
        dist[i]=-1;
        for(j=0;j<n;j++){
            a[i][j]=-1;
        }
    }
    dist[k]=0;
}
