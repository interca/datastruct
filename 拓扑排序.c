#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];//图本身
    int *indegree;//入度
    int n,l;
}T1;
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
    Node*last;
}List;
void push(List*plsit,int number);//将结点压入队列
int pop(List*plsit);//抛出队列
void creat(T1*T);//初始化
void topsort(T1*T);//拓扑排序算法
int main(){
    int n,l;
    printf("input n l:\n");
    scanf("%d%d",&n,&l);
    T1 T;
    T.n=n;
    T.l=l;
    T.indegree=(int*)malloc(sizeof(int)*n);
    creat(&T);
    topsort(&T);
    return 0;
}
void topsort(T1*T){
    List list;
    int i;
    int n=T->n;
    int count=0;
    int v;
    list.head=list.last=NULL;
    for(i=0;i<n;i++){   //将所有入度等于零的点压入队列
        if(T->indegree[i]==0){
            push(&list,i);
        }
    }
    while(list.head){
        v=pop(&list);
        printf("%d ",v);
        count++;
        for(i=0;i<n;i++){
            if(T->a[v][i]>0){
                if(--T->indegree[i]==0){ // 将v临接点入度全部减一
                  push(&list,i);
                }
            }
        }
    }
}
void creat(T1*T){//初始化图
  int c1,c2,i,j;
  int n=T->n;
  for(i=0;i<n;i++){
      T->indegree[i]=0;
      for(j=0;j<n;j++){
          T->a[i][j]=-1;
      }
  }
  for(i=0;i<T->l;i++){
      scanf("%d%d",&c1,&c2);
      T->a[c1][c2]=1;
      T->indegree[c2]++;
  }
}
int pop(List*plist){
    Node*p=plist->head;
    plist->head=plist->head->next;
    return p->value;
}
void push(List*plist,int number){
    Node*p=(Node*)malloc(sizeof(Node));
    p->value=number;
    p->next=NULL;
    if(plist->head==NULL){
        plist->head=plist->last=p;
    }
    else{
        plist->last->next=p;
        plist->last=p;
    }
}