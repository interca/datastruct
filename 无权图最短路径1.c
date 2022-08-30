#include<stdio.h>
#include<stdlib.h>
int *path;//存放路径
int *dist;//存放距离
int a[100][100];
void insert(int k,int n);//计算路径
void print(int k,int n);//打印最短路径
void creat(int k,int n);//初始化数组
typedef struct node{      //队列生成路径
    struct node *next;
    int value;
}Node;
typedef struct list{
    Node*head;
    Node*last;
}List;
typedef struct node2{   //输出路径的堆栈
    struct node2*next;
    int value;
}Node2;
typedef struct list2{
    Node2*head;
    }List2;
void push2(List2*plist,int number);
int  pop2(List2*plist);
void push(List*plist,int number);
int pop(List*plist);
int main(){
    int n,k,l;   //n:当前结点数，l有通路的边，k出发点
    int c1,c2;

    printf("input:\n");
    scanf("%d%d%d",&n,&k,&l);
    path=(int*)malloc((n)*sizeof(int));
    dist=(int*)malloc((n)*sizeof(int));
    creat(k,n);
    for(int i=0;i<l;i++){
        scanf("%d%d",&c1,&c2);
        a[c1][c2]=1;
    }
    insert(k,n);
    
    print(k,n);
    return 0;
}
void print(int k,int n){
    int i;
    int number;
    List2 list;
    list.head=NULL;
    while(1){
        printf("1");
        printf("input a number:\n");
        scanf("%d",&number);
        printf("The %d to the %d nearest is %d\n",k,number,dist[number]);
    
        while(1){
            push2(&list,number);
            if(number==k)break;
            number=path[number];
            
        }
        while(list.head){
            number=pop2(&list);
            printf("%d ",number);
        }
        printf("\n");
    }
}
int pop2(List2*plist){
    Node2*p=plist->head;
    plist->head=plist->head->next;
    return p->value;
}
void push2(List2*plist,int number){
     Node2*p=(Node2*)malloc(sizeof(Node));
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
     else {
         plist->last->next=p;
         plist->last=p;
     }
}
void insert(int k,int n){
    int i;
    List list;
    list.head=list.last=NULL;
    push(&list,k);
    while(list.head){
        k=pop(&list);
        for(i=0;i<n;i++){
            if(a[k][i]==1&&dist[i]==-1){
                dist[i]=dist[k]+1;
                path[i]=k;
                push(&list,i);
            }
        }
    }
}
void creat(int k,int n){
    int i,j;
    dist[k]=0;
    for(i=0;i<n;i++){
        if(i!=k){
            dist[i]=-1;//判断有没有被访问过
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            a[i][j]=-1;
        }
    }
}