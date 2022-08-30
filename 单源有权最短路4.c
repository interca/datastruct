#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int **a;
    int *dist;
    int* collection;
    int k,l,n;
    int *path;
}T1;
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
}List;
void creat(T1*T);
void disk(T1*T);
void print(T1*T);
void push(List*plsit,int number);
int pop(List*plist);
int main(){
    int n,k,l;
    T1 T;
    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    T.n=n;
    T.l=l;
    T.k=k;
    T.a=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        T.a[i]=(int*)malloc(sizeof(int)*n);
    }
    T.dist=(int*)malloc(sizeof(int)*n);
    T.path=(int*)malloc(sizeof(int)*n);
    T.collection=(int*)malloc(sizeof(int)*n);
    
    creat(&T);
    disk(&T);
    print(&T);
    return 0;
}
void print(T1*T){
    int k=T->k;
    int number;
    List list;
    list.head=NULL;
    while(1){
        printf("input number:\n");
        scanf("%d",&number);
        printf("The %d distant %d is %d\n",k,number,T->dist[number]);
        if(number==k)printf("0\n");
        else{
        while(1){
           
            push(&list,number);
            if(number==k)break;
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
    int n=T->n;
    while(1){
        imprise=0;
        min=10000;
        for(i=0;i<n;i++){
           if(T->collection[i]==0&&T->dist[i]<min){
               min=T->dist[i];
               v=i;
               imprise=1;
           }
        }
        if(imprise==0)break;
        T->collection[v]=1;
        for(i=0;i<n;i++){
            if(T->a[v][i]>0&&T->collection[i]==0){
              if(T->a[v][i]+T->dist[v]<T->dist[i]){
                  T->dist[i]=T->a[v][i]+T->dist[v];
                  T->path[i]=v;
              }
            }
        }
    }
}
void creat(T1*T){
    int i,j,c1,c2,q;
    int n=T->n;
    int l=T->l;
    for(i=0;i<n;i++){
        T->collection[i]=0;
        T->path[i]=-1;
        T->dist[i]=1000;
    for(j=0;j<n;j++){
        T->a[i][j]=-1;
    }
    }
  
    for(i=0;i<l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
    }
    T->dist[T->k]=0;
    T->collection[T->k]=1;
    for(i=0;i<n;i++){
        if(T->a[T->k][i]>0){
            T->dist[i]=T->a[T->k][i];
            T->path[i]=T->k;
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
     p->next=NULL;
     p->value=number;
     if(plist->head==NULL){
         plist->head=p;
     }else {
         p->next=plist->head;
         plist->head=p;
     }
}