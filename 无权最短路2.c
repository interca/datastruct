#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int **a;
    int *vist;
    int *dist;
    int*path;
    int n,k,l;

}T1;
void creat(T1*T);
void find(T1*T);
void print(T1*T);
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
    Node*last;
}List;
void push1(List*plist,int number);
void push2(List*plist,int number);
int pop(List*plist);
int main(){
    int n,k,l;
    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    T1 T;
    T.n=n;
    T.l=l;
    T.k=k;
    T.a=(int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
       T.a[i]=(int*)malloc(sizeof(int)*n);
    }
    T.path=(int*)malloc(sizeof(int)*n);
    T.dist=(int*)malloc(sizeof(int)*n);
    T.vist=(int*)malloc(sizeof(int)*n);
    creat(&T);
    find(&T);
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
            push2(&list,number);
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
void find(T1*T){
    int k=T->k;
    int i;
    List list;
    T->dist[k]=0;
    list.head=list.last=NULL;
   
    push1(&list,k);
   
    while(list.head){
       
        k=pop(&list);
        for(i=0;i<T->n;i++){
            if(T->a[k][i]==1&&T->dist[i]==-1){
                push1(&list,i);
                T->dist[i]=T->dist[k]+1;
                T->path[i]=k;
            }
        }
    }
}
void creat(T1*T){
   int n=T->n;
   int i,j;
   int c1,c2;
   for(i=0;i<n;i++){
       T->dist[i]=-1;
       
       for(j=0;j<n;j++){
          T->a[i][j]=-1;
       }
   }
  
   for(i=0;i<T->l;i++){
       scanf("%d%d",&c1,&c2);
       T->a[c1][c2]=1;
   }
  
}
int pop(List*plist){
    Node*p=plist->head;
    plist->head=plist->head->next;
    return p->value;
}
void push2(List*plist,int number){
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
void push1(List*plist,int number ){
    printf("1");
    Node*p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->value=number;
    if(plist->head==NULL){
        plist->head=plist->last=p;
    }else {
        plist->last->next=p;
        plist->last=p;
    }
}
    
