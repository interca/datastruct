#include<stdio.h>
#include<stdlib.h>
typedef  struct t{
    int a[100][100];//记录图
    int *dist;   //记录总路数
    int *path;  //记录路径
    int n;
    int l;
    int k;
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
int pop(List*plist);
void push2(List*plist,int number);
int main(){
    int n,k,l;
    printf("input  n,k,l:\n");
    scanf("%d%d%d",&n,&k,&l);
    T1 T;
    T.n=n;
    T.l=l;
    T.k=k;
    T.dist=(int*)malloc(n*sizeof(int));
    T.path=(int*)malloc(n*sizeof(int));
    creat(&T);
    find(&T);
    printf("\n");
    print(&T);
    return 0;
    }
    void push2(List*plist,int number){
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
    void print(T1*T){
        int number;
        List list;
        list.head=NULL;
        while(1){
            printf("input a number:\n");
            scanf("%d",&number);
            printf("The %d distant %d is %d\n",T->k,number,T->dist[number]);
            if(number==T->k)printf("ERROR\n");
            else {
                while(1){
                     push2(&list,number);
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
               plist->head=plist->last=p;
           }
           else {
               plist->last->next=p;
               plist->last=p;
           }
    }
    void find(T1*T){
        int k;
        int i,j;
        List list;
        list.head=list.last=NULL;
        push1(&list,T->k);
        while(list.head){
            k=pop(&list);
            for(i=0;i<T->n;i++){
                if(T->dist[i]==-1&&T->a[k][i]==1){
                    T->dist[i]=T->dist[k]+1;
                    T->path[i]=k;
                    push1(&list,i);
                }
            }
        }
    }
    void creat(T1*T){
        int c1,c2;
        int i,j;
        for(i=0;i<T->n;i++){
            T->dist[i]=-1;//标记是否被访问过
             for(j=0;j<T->n;j++){
                T->a[i][j]=-1;//初始化图相连
             }
        }
        for(i=0;i<T->l;i++){
            scanf("%d%d",&c1,&c2);
            T->a[c1][c2]=1;
        }
        T->dist[T->k]=0;
    }

