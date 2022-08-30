#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];//图的主体
    int flag[100][100];//判断边是否被收入，是：1否：0
    int root;//记录树根
    int *vist;//记录结点是否被访问过
    int l;//边数
    int n;//结点数
    int *dist;//结点到树的距离
    int k;
    int count;//记录权重
}T1;
T1*T;
void creat();//初始化图
void wfs(int k);//遍历树
void prime(int k);//求生成树算法
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
void set(int number);//将边设为已经收入状态
void creattree();
int main(){
    int n,l,k,i,j;
    printf("inpput n and l,k:\n");
    scanf("%d%d%d",&n,&l,&k);
    T=(T1*)malloc(sizeof(T1));
    T->count=0;
    T->n=n;
    T->l=l;
    T->k=k;
    T->vist=(int*)malloc((n)*sizeof(int));
    T->dist=(int*)malloc((n)*sizeof(int));
    creat();
    prime(T->k);
    printf("\n");
    creattree();
           wfs(T->k);
           printf("\n");
           printf("qis%d\n",T->count);
           for(i=0;i<T->n;i++){
               for(j=0;j<T->n;j++){
                   printf("%d ",T->a[i][j]);
               }
               printf("\n");
           }
    return 0;
}
void wfs(int k){
    List list;
    list.head=list.last=NULL;
    push(&list,k);
    T->vist[k]=1;
    printf("k=%d\n",k);
    while(list.head){
        k=pop(&list);
        printf("%d  ",k);
        for(int i=0;i<T->n;i++){
            if(T->vist[i]==0&&T->a[k][i]>0){
                T->vist[i]=1;
                push(&list,i);
            }
        }
    }
}
void creattree(){
   
    int i,j;
    for(i=0;i<T->n;i++){
        for(j=0;j<T->n;j++){
            if(T->flag[i][j]!=1){
                T->a[i][j]=-1;
            }
        }
    }
}
void set(int number){
    int i;
    int min=100;
    int c1;
    for(int i=0;i<T->n;i++){
        if(T->a[i][number]>0&&i!=number&&T->dist[i]==0&&T->a[i][number]<min){
            min=T->a[i][number];
            c1=i;
        }
    }
    T->flag[c1][number]=1;
    T->flag[number][c1]=1;
    T->count=T->count+T->a[c1][number];
}
void prime(int k){
    int min=-1;
    int i;
    int imprise=0;
    int v;
    while(1){
          imprise=0;
          min=10000;
          int v;
         for(i=0;i<T->n;i++){
             if(T->dist[i]!=0){
                 imprise=1;
             //   printf("T->dist[%d]=%d\n",i,T->dist[i]);
                 if(T->dist[i]<min){
                     min=T->dist[i];
                     v=i;
                 }
             }
         }
         if(imprise==0)break;
         printf("v=%d",v);
         T->dist[v]=0;
         set(v);
         for(i=0;i<T->n;i++){
             if(T->a[v][i]>0&&T->dist[i]!=0&&v!=i&&T->a[v][i]<T->dist[i]){
                 T->dist[i]=T->a[v][i];
                
             }
            
            
         }
    }
}
void creat(){///初始化图并且输入权重
    int i,j;
    int c1,c2,q;
    for(i=0;i<T->n;i++){
        T->vist[i]=0;//都没有被访问
        T->dist[i]=1000;
        for(j=0;j<T->n;j++){
            T->a[i][j]=-1;//权重全为-1
            T->flag[i][j]=0;//初始都没有被收入
        }
    }
    printf("input q:\n");
    for(i=0;i<T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=T->a[c2][c1]=q;
    }
    for(i=0;i<T->n;i++){
        if(T->a[T->k][i]>0){
           T->dist[i]=T->a[T->k][i];
        }
    }
   T->dist[T->k]=0;
  
}
int pop(List*plist){
    Node*p=plist->head;
    plist->head=plist->head->next;
    return p->value;
}
void push(List*plist,int number){
    Node*p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->value=number;
    if(plist->head==NULL){
        plist->head=plist->last=p;
    }
    else {
        plist->last->next=p;
        plist->last=p;
    } 
}