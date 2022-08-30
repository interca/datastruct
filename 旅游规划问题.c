#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];//图本身
    int *dist;//记录路径长度
    int *path;//打印路径
    int *cost;//花费
    int k,n,l;
    int costing[100][100];//路之间花费
    int c;
    int *collect;//判断结点有没有被收入

}T1;
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
}List;
void dijkstra(T1*T);//主要算法
void print(T1*T);//打印路径函数
void creat(T1*T);//初始化函数
void push(List*plist,int number);
int pop(List*plist);
int main(){
    int n,k,l;
    printf("input n,k,l:\n");
    scanf("%d%d%d",&n,&k,&l);

    T1 T;
    T.n=n;
    T.l=l;
    T.k=k;
    T.collect=(int *)malloc(sizeof(int)*n);
    T.dist=(int*)malloc(sizeof(int)*n);
    T.path=(int*)malloc(sizeof(int)*n);
    T.cost=(int*)malloc(sizeof(int)*n);
    creat(&T);
    dijkstra(&T);
    printf("\n");
    print(&T);
    return 0;
}
void print(T1*T){
    int number;
    int n=T->n;
    List list;
    list.head=NULL;
    while(1){
        printf("input a number:\n");
        scanf("%d",&number);
        printf("The %d distant %d is %d,cost %d \n",T->k,number,T->dist[number],T->cost[number]);
        while(1){
            push(&list,number);
            if(number==T->k)break;
            number=T->path[number];
        }
        while(list.head){
            number=pop(&list);
            printf("%d ",number);
        }
        printf("\n");
    }
}
void dijkstra(T1*T){
    int min,i,j,n,v;
    n=T->n;
    int imprise;
    while(1){
        imprise=0;
        min=10000;
        for(i=0;i<n;i++){
            if(T->collect[i]==0&&T->dist[i]<min){
                imprise=1;
                min=T->dist[i];
                v=i;
            }
        }
        if(imprise==0)break;
        T->collect[v]=1;
        for(i=0;i<n;i++){
            if(T->a[v][i]>0&&T->collect[i]==0){
                if(T->a[v][i]+T->dist[v]<T->dist[i]){
                    T->dist[i]=T->a[v][i]+T->dist[v];
                    T->path[i]=v;
                    T->cost[i]=T->cost[v]+T->costing[v][i];
                }else if(T->a[v][i]+T->dist[v]==T->dist[i]&&(T->cost[v]+T->costing[v][i])<T->cost[i]){
                    T->cost[i]=T->cost[v]+T->costing[v][i];
                    T->path[i]=v;
                }
            }
        }
    }
}
void creat(T1*T){
    int i,j,c1,c2,q,c;
    int n=T->n;
    for(i=0;i<n;i++){
        T->dist[i]=1000;
        T->cost[i]=-1;
        T->collect[i]=0;//开始都没有被收入
        for(j=0;j<n;j++){
            T->a[i][j]=-1;//路之间初始没有联通
            T->costing[i][j]==0;//路之前没有过路费
        }
    }
    T->dist[T->k]=0;
    T->cost[T->k]=0;
    T->cost[i]=0;
    T->collect[T->k]=1;//根结点被收入默认
    for(i=0;i<T->l;i++){
        scanf("%d%d%d%d",&c1,&c2,&q,&c);
        T->a[c1][c2]=q;
        T->costing[c1][c2]=c;
    }
   
    for(i=0;i<T->n;i++){
        if(T->a[T->k][i]>0){
            T->dist[i]=T->a[T->k][i];
            T->cost[i]=T->costing[T->k][i];
            T->path[i]=T->k;
        }
    }
    printf("%d",T->dist[1]);
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
int pop(List*plist){
    Node*p=plist->head;
    plist->head=plist->head->next;
    return p->value;
}