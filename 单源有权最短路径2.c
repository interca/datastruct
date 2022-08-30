#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];
    int*collect;
    int *dist;
    int *path;
    int n;
    int k;
    int l;
}T1;
void creat(T1*T);
void disk(T1*T);
typedef struct  node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
}List;
void print(T1*T);
void push(List*plist,int number);
int pop(List*plist);
int main(){
    int n,k,l;
    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    T1 T;
    T.dist=(int*)malloc(n*sizeof(int));
    T.collect=(int*)malloc(n*sizeof(int));
    T.path=(int*)malloc(n*sizeof(int));
    T.k=k;
    T.l=l;
    T.n=n;
    creat(&T);
   
    disk(&T);
    printf("\n");
    print(&T);
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
    else {
        p->next=plist->head;
        plist->head=p;
    }
}
void print(T1*T){
    List list;
    list.head=NULL;
    int number;
    while(1){
        printf("input a number:\n");
        scanf("%d",&number);
        printf("The %d near %d is %d\n",T->k,number,T->dist[number]);
        if(number==T->k)printf("error\n");
        else {
            while(1){
                push(&list,number);
                if(number==T->k)break;
                number=T->path[number];
            }
            while(list.head){
                number=pop(&list);
                printf("%d ",number);
            }
        }
        printf("\n");
    }
}
void disk(T1*T){
    int min,v,i,j;
    int imprise;
    while(1){
        min=10000;
        imprise=0;
        for(i=0;i<T->n;i++){
            if(T->collect[i]==0){
                imprise=1;
                printf("i=%d ",i);
                if(T->dist[i]<min){
                    min=T->dist[i];
                    v=i;
                }
            }
        }
        if(imprise==0)break;
         printf("v=%d ",v);
        T->collect[v]=1;
        for(i=0;i<T->n;i++){
            if(T->collect[i]==0&&T->a[v][i]>0){
                if(T->dist[v]+T->a[v][i]<T->dist[i]){
                    printf("%d",i);
                    T->dist[i]=T->dist[v]+T->a[v][i];
                    T->path[i]=v;
                }
            }
        }
    }
}
void creat(T1*T){
    int i,j;
    int c1,c2,q;
    for(i=0;i<T->n;i++){
        T->collect[i]=0;
        T->dist[i]=1000;
        for(j=0;j<T->n;j++){
              T->a[i][j]=-1;
        }
    }
    for(i=0;i<T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
    }
    T->dist[T->k]=0;
    T->collect[T->k]=1;
    for(i=0;i<T->n;i++){
        if(T->a[T->k][i]>0){
            T->dist[i]=T->a[T->k][i];
            T->path[i]=T->k;
        }
    }
}