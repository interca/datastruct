#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define Max LONG_MAX;
typedef struct t{
    int **a;
    int *dist;
    int *path;
    int *collect;
    int n,k,l;
}T1;
void disk(T1*T);
void creat(T1*T);
void print(T1*T);
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
}List;
void push(List*plist,int number);
int pop(List*plist);

int main(){
    int n,k,l;
    int i;
    T1 T;

    scanf("%d %d",&n,&l);
    T.a = (int**)malloc(sizeof(int*)*(n+1));
    for (i = 1; i <= n; i++){
       T.a[i] = (int*)malloc(sizeof(int)*(n+1));
    }
    T.n=n;
    T.l=l;
    T.k=1;
    T.path=(int*)malloc(sizeof(int)*(n+1));
    T.dist=(int*)malloc(sizeof(int)*(n+1));
    T.collect=(int*)malloc(sizeof(int)*(n+1));
    creat(&T);
    disk(&T);
    for(i=2;i<=n;i++){
        printf("%d\n",T.dist[i]);
    }
    return 0;

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
        plist->head=p;
    }
    else{
        p->next=plist->head;
        plist->head=p;
    }
}
void disk(T1*T){
    int max=Max;
    int min,v;
    int i;
    int imprise=0;
    while(1){
        imprise=0;
        min=Max;
       for(i=1;i<=T->n;i++){
           if(T->collect[i]==0&&T->dist[i]<min){
               min=T->dist[i];
               v=i;imprise=1;
           }
       }
       if(imprise==0)break;
       T->collect[v]=1;
     
       for(i=1;i<=T->n;i++){
           if(T->a[v][i]<max&&T->collect[i]==0){
               if(T->dist[v]+T->a[v][i]<T->dist[i]){
                   T->dist[i]=T->dist[v]+T->a[v][i];
                   T->path[i]=v;
               }
           }
       }
    }
}
void creat(T1*T){//初始化
    int i,j,c1,c2,q;
    int n=T->n;
    for(i=1;i<=n;i++){
       T-> dist[i]=Max;
       T->collect[i]=0;
        for(j=1;j<=n;j++){
           T->a[i][j]=Max;
        }
    }
    for(i=1;i<=T->l;i++){
        scanf("%d %d %d",&c1,&c2,&q);
       
        T->a[c1][c2]=q;
    }
    T->dist[T->k]=0;
    T->collect[T->k]=1;
    int max=Max;
    for(i=1;i<=n;i++){
        if(T->a[T->k][i]<(max)){
            T->path[i]=T->k;
            T->dist[i]=T->a[T->k][i];
        }
    }
}
