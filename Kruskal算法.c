#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];//图本身
    int tree[100][100];//最终得到的最小生成树
    int*flag;//并查集
    int*vist;//判断是否被访问过
    int *stack;//最小堆
    int k,l,n;
    int size;
}T1;
int findroot(T1*T,int number);
void creat(T1*T);
void kruskal(T1*T);
void wfs(T1*T,int k);
void insert(T1*,int number);//插入最小堆
int delect(T1*T);//删除最小堆
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
int main(){
    int n,k,l;
    int i,j;
    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    T1 T;
    T.n=n;
    T.l=l;
    T.k=k;
    T.flag=(int*)malloc(sizeof(int)*n);
    T.vist=(int*)malloc(sizeof(int)*n);
    T.stack=(int*)malloc(sizeof(int)*(l+1));
    creat(&T);
    
    kruskal(&T);
    for(i=0;i<n;i++){
        printf("%d ",findroot(&T,i));
    }
    printf("-------------------------------------\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",T.tree[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    wfs(&T,T.k);
    return 0;
}
int findroot(T1*T,int number){
    int n=T->n;
    int i;
   
    for(;T->flag[number]>=0;number=T->flag[number]){

    };
    
    return number;
}
void wfs(T1*T,int k){
    int i,j,n;
    n=T->n;
    List list;
    list.head=list.last=NULL;
    push(&list,k);
    while(list.head){
        k=pop(&list);
        T->vist[k]=1;
        printf("%d ",k);
        for(i=0;i<n;i++){
            if(T->tree[k][i]>0&&T->vist[i]==0){
                T->vist[i]=1;
                push(&list,i);
            }
        }
    }
}
void kruskal(T1*T){
    int count=0;
    int line;
    int i,j;
    int n=T->n;
    int imprise;
    int root1,root2;
    while(count<T->n-1){
        imprise=0;
        line=delect(T);
        printf("line=%d\n",line);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(T->a[i][j]==line){
                    imprise=1;
                    root1=findroot(T,i);
                    root2=findroot(T,j);
                    printf("i=%d,j=%d ",i,j);
                    printf("root1=%d,roo2=%d",root1,root2);
                    if(root1==root2){
                       T->a[i][j]=T->a[j][i]=-1;
                       break;
                    }else{
                        if(root1==T->k)T->flag[root2]=i;
                        else T->flag[findroot(T,i)]=j;
                        T->a[i][j]=T->a[j][i]=-1;
                        T->tree[i][j]=T->tree[j][i]=line;
                        count++;
                        break;
                    }
                }
            }
            
            if(imprise==1)break;
        }
        printf("\n");
    }  
}
int delect(T1*T){     //删除最小堆
    int maxsize=T->stack[1];
    int temp=T->stack[T->size--];
    int parent=1;
    int chid;
    for(;parent*2<=T->size;parent=chid){
        chid=parent*2;
        if((chid!=T->size)&&T->stack[chid+1]<T->stack[chid]){
            chid++;
        }
        if(T->stack[parent]>temp)break;
        else{
            T->stack[parent]=T->stack[chid];
        }
    }
    T->stack[parent]=temp;
    return maxsize;
}
void insert(T1*T,int number){//插入最小堆
    int i=++T->size;
    for(;T->stack[i/2]>number;i=i/2){
        T->stack[i]=T->stack[i/2];
    }
    T->stack[i]=number;
}
void creat(T1*T){//初始化最小堆和图
    int i,j,c1,c2,q;
    int n=T->n;
    for(i=0;i<n;i++){
        T->vist[i]=0;
        T->flag[i]=-1;
        for(j=0;j<n;j++){
           
            T->a[i][j]=-1;
            T->tree[i][j]=-1;
        }
    }
    T->vist[T->k]=1;
    T->stack[0]=-10000;
    T->size=0;
    //T->flag[T->k]=-;//将根结点设为-1；
    for(i=0;i<T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);  
        T->a[c1][c2]=q;
        T->a[c2][c1]=q;
        insert(T,q);
    }
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
int pop(List*plist){
    Node*p=plist->head;
    plist->head=plist->head->next;
    return p->value;
}