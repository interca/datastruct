#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];//图的主体
    int flag[100][100];//判断边是否被收入树中
    int *dist;//判断点是否被收入树中是就等于0；
    int*vist;//判断结点是否被访问过，遍历图的时候用
    int k,l,n;
    int count;
}T1;
void creat(T1*T);
void prime(T1*T);
void wfs(T1*T,int k);
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
    Node*last;
}List;
void push(List*plist,int number);
int pop(List*plist);
void set(T1*T,int number);
void creatmintree(T1*T);
int main(){
    int n,k,l;
    printf("input n,k,l:\n");
    scanf("%d%d%d",&n,&k,&l);
    T1 T;
    T.n=n;
    T.l=l;
    T.k=k;
    T.count=0;
    T.dist=(int*)malloc(sizeof(int)*n);
    T.vist=(int*)malloc(sizeof(int)*n);
    creat(&T);
    prime(&T);
    creatmintree(&T);
    printf("\n");
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           printf("%d ",T.a[i][j]);
       }
       printf("\n");
    }
    wfs(&T,T.k);
    printf("\n");
    printf("THE count is %d\n",T.count);
    return 0;
}
void wfs(T1*T,int k){
    List list;
    list.head=list.last=NULL;
    push(&list,k);
    while(list.head){
        k=pop(&list);
        printf("%d ",k);
        T->vist[k]=1;
        for(int i=0;i<T->n;i++){
            if(T->a[k][i]>0&&T->vist[i]==0){
                T->vist[i]=1;
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
void creatmintree(T1*T){
    int i,j;
    int n=T->n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(T->flag[i][j]==0){//如果边没有被收入，那就把边设为0；
                T->a[i][j]=-1;
            }
        }
    }
}
void set(T1*T,int number){
    int i,j;
    int n=T->n;
    int min=10000;
    int v;
    for(i=0;i<n;i++){
          if(T->a[i][number]>0&&i!=number&&T->dist[i]==0&&T->a[i][number]<min){
              min=T->a[i][number];
              v=i;
          }
    }
    T->flag[v][number]=1;
    T->flag[number][v]=1;
    T->count=T->count+T->a[v][number];
}
void prime(T1*T){
    int min,v,i,j;
    int imprise;
    int n=T->n;
    while(1){
        min=10000;
        imprise=0;
        for(i=0;i<n;i++){
            if(T->dist[i]!=0&&T->dist[i]<min){
                min=T->dist[i];
                v=i;
                imprise=1;
            }
        }
        if(imprise==0)break;
        T->dist[v]=0;
        set(T,v);
        printf("v=%d",v);
        for(i=0;i<n;i++){
            if(T->a[v][i]>0&&T->dist[i]!=0&&v!=i){
                if(T->a[v][i]<T->dist[i]){
                    T->dist[i]=T->a[v][i];
                }
            }
        }
    }
}
void creat(T1*T){//初始化
    int i,j,q,c1,c2;
    int n=T->n;
    for(i=0;i<n;i++){
        T->dist[i]=1000;
        T->vist[i]=0;
        for(j=0;j<n;j++){
           T->a[i][j]=-1;
           T->flag[i][j]=0;//初始都没有被收入
        }
    }
    for(i=0;i<T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
        T->a[c2][c1]=q;
    }
   
    for(i=0;i<n;i++){
        if(T->a[T->k][i]>0){
            T->dist[i]=T->a[T->k][i];
        }
    }
    T->dist[T->k]=0;
    T->vist[T->k]=0;
}