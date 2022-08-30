#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int *dist;
int *path;
int *collect;
typedef struct node{
    struct node*next;
    int value;
}Node;
typedef struct list{
    Node*head;
}List;
void creat(int n,int k);
void insert(int n,int k);
void print(int n,int k );
void push(List*plist,int number);
int pop(List*plist);
int main(){
    int n,k,l,c1,c2,q;
    int i;

    printf("input n,k,l\n");
    scanf("%d%d%d",&n,&k,&l);
    dist=(int*)malloc(n*sizeof(int));
    path=(int*)malloc(n*sizeof(int));
    collect=(int*)malloc(n*sizeof(int));
    creat(n,k);
    dist[k]=0;
    collect[k]=1;

    printf("input q\n");
    for(i=0;i<l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        a[c1][c2]=q;
    }
     for(int i=0;i<n;i++){
        if(a[k][i]>0){
            dist[i]=a[k][i];
            path[i]=k;
        }
    }
   
    insert(n,k);
    printf("\n");
    print(n,k);
    return 0;
}
void print(int n,int k){
    int i,number;
    List list;
    list.head=NULL;
    while(1){
       
         printf("input a number:\n");
          scanf("%d",&number);
          printf("The %d is %d to %d\n",k,number,dist[number]);
          while(1){
             printf("number=%d ",number);
              push(&list,number);
              if(number==k)break;
              number=path[number];
          }
          while(list.head){
              number=pop(&list);
              printf("%d " ,number);
          }
          printf("\n");
    }
    
}
void insert(int n,int k){
    int i,imprise=0;
    int v;
    int min;
    while(1){
         imprise=0;
        for(i=0;i<n;i++){
            if(collect[i]==0){
                 min=i;
                imprise=1;
                break;
            }
        }
        if(imprise==0)break;
        for(i=0;i<n;i++){
            if(dist[i]<dist[min]&&collect[i]==0){
                min=i;
            }
        }
        printf("min=%d ",min);
        collect[min]=1;
        for(i=0;i<n;i++){
            if(a[min][i]>0&&collect[i]==0){
                if(dist[min]+a[min][i]<dist[i]){
                    dist[i]=dist[min]+a[min][i];
                    path[i]=min;
                }
            }
        }
    }
}
void creat(int n,int k){
    int i,j;
    for(i=0;i<n;i++){
        dist[i]=1000;
        collect[i]=0;
        for(j=0;j<n;j++){
            a[i][j]=-1;
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