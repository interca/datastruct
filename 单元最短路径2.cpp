#include<stdio.h>
#include<stdlib.h>
int *path;//存放路径
int *dist;//存放距离
int a[100][100];
void insert(int k,int n);//计算路径
void print(int k,int n);//打印最短路径
void creat(int k,int n);//初始化数组
typedef struct node{
    struct node *next;
    int value;
}Node;
typedef struct list{
    Node*head;
    Node*last;
}List;
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
    while(1){
        printf("1");
        printf("input a number:\n");
        scanf("%d",&number);
        printf("The %d to the %d nearest is %d\n",&k,&number,dist[number]);
        while(1){
            if(number==k)break;
            printf("%d ",path[number]);
            number=path[number];
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
         plist->head=plist->last;
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
        printf("3");
        k=pop(&list);
        for(i=0;i<n;i++){
            if(a[k][i]=1&&dist[i]<0){
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
