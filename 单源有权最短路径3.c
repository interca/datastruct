#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];
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

    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    T.n=n;
    T.l=l;
    T.k=k;
    T.path=(int*)malloc(sizeof(int)*n);
    T.dist=(int*)malloc(sizeof(int)*n);
    T.collect=(int*)malloc(sizeof(int)*n);
    creat(&T);
    disk(&T);
    print(&T);
    return 0;

}
void print(T1*T){
    int i,number;
    List list;
    list.head=NULL;
    while(1){
        printf("input a number:\n");
        scanf("%d",&number);
        printf("THE %d distant %d is %d\n",T->k,number,T->dist[number]);
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
    int min,v;
    int i;
    int imprise=0;
    while(1){
        imprise=0;
        min=10000;
       for(i=0;i<T->n;i++){
           if(T->collect[i]==0&&T->dist[i]<min){
               min=T->dist[i];
               v=i;imprise=1;
           }
       }
       if(imprise==0)break;
       T->collect[v]=1;
       for(i=0;i<T->n;i++){
           if(T->a[v][i]>0&&T->collect[i]==0){
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
    for(i=0;i<n;i++){
       T-> dist[i]=1000;//距离全部初始化正无穷
       T->collect[i]=0;//全部没有收录
        for(j=0;j<n;j++){
           T->a[i][j]=-1;
        }
    }
    for(i=0;i<T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
    }
    T->dist[T->k]=0;
    T->collect[T->k]=1;
    for(i=0;i<n;i++){
        if(T->a[T->k][i]>0){
            T->path[i]=T->k;
            T->dist[i]=T->a[T->k][i];
        }
    }
}