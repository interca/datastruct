#include<stdio.h>
#include<stdlib.h>
int *collect;  //收录节点
int a[100][100];//存放边关系
int *path;//存放路径
int*dist;
void creat(int k,int n);
void print(int k,int n);
void disk(int k,int n);
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
    int n,q,l,i,number,k;
    int c1,c2;

    printf("input n,k,l:\n");
    scanf("%d%d%d",&n,&k,&l);
    path=(int*)malloc(n*sizeof(int));
    collect=(int*)malloc(n*sizeof(int));
    dist=(int*)malloc(n*sizeof(int));
    creat(k,n);
    for(i=0;i<l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        a[c1][c2]=q;
    }
    dist[k]=0;
    collect[k]=1;
    for(i=0;i<n;i++){
        if(a[k][i]>0&&collect[i]==0){
               dist[i]=a[k][i];
               path[i]=k;
        }
    }
    disk(k,n);
    for(i=0;i<n;i++){
        printf("path=%d ",path[i]);
    }
    printf("\n");
    print(k,n);
    return 0;
}
void creat(int k,int n){
    int i;
    for(i=0;i<n;i++){
        collect[i]=0;
        dist[i]=1000;
    }
    for(i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=-1;
        }
    }
}
int pop(List*plist){
    Node*p;
    p=plist->head;
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
void print(int k,int n){
    List list;
    list.head=NULL;
    int number;
    while(1){
        printf("input a nmber:\n");
        scanf("%d",&number);
        printf("THE %d near %d is %d\n",k,number,dist[number]);
        while(1){
            push(&list,number);
            if(number==k)break;
            number=path[number];
        }
        while(list.head){
            number=pop(&list);
            printf("%d ",number);
        }
        printf("\n");
    }
}
void disk(int k,int n){
    int i;
    int imprise;
    int v;
    while(1){
        imprise=0;
       for(i=0;i<n;i++){
           if(collect[i]==0){
               v=i;
               imprise=1;break;
           }
       }
       if(imprise==0)break;
       for(i=0;i<n;i++){
           if(collect[i]==0&&dist[i]<dist[v]){
               v=i;
           }
       }
       printf("v=%d\n",v);
       collect[v]=1;
       for(i=0;i<n;i++){
             if(a[v][i]>0&&collect[i]==0){
                 if(dist[v]+a[v][i]<dist[i]){
                     dist[i]=dist[v]+a[v][i];
                     path[i]=v;
                 }
             }  
       }
    }
}

