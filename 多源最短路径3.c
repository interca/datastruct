#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int **a;
    int **path;
    int n,l;
}T1;
void creat(T1*T);
void floyed(T1*T);
void print(T1*T);
void findroot(T1*T,int i,int j);
int main(){
    int n,l;
    printf("input n,l:\n");
    scanf("%d%d",&n,&l);
    T1 T;
    T.n=n;
    T.l=l;
    T.a=(int**)malloc(sizeof(int*)*n);
    T.path=(int**)malloc(sizeof(int*)*n);

     for(int i=0;i<n;i++){
         T.a[i]=(int*)malloc(sizeof(int)*n);
         T.path[i]=(int*)malloc(sizeof(int)*n);
     }

     creat(&T);
     floyed(&T);
     printf("\n");

     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             printf("%d ",T.a[i][j]);
         }
         printf("\n");
     }

     print(&T);
     return 0;
}
void findroot(T1*T,int i,int j){
    if(T->path[i][j]>=0){
        findroot(T,i,T->path[i][j]);
        printf("%d ",T->path[i][j]);
        findroot(T,T->path[i][j],j);
    }
}
void print(T1*T){
    int i,j;
    while(1){
        printf("input i,j\n");
        scanf("%d%d",&i,&j);
        int number=T->a[i][j];
        if(number!=1000){
        printf("The %d distant %d is %d\n",i,j,T->a[i][j]);
        printf("The root is %d ",i);
       findroot(T,i,j);
       printf("%d \n",j);
        }else {
            printf("错误");
        }
    }
}
void floyed(T1*T){
    int i,j,k;
    int n=T->n;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(T->a[i][k]+T->a[k][j]<T->a[i][j]){
                    T->a[i][j]=T->a[i][k]+T->a[k][j];
                    T->path[i][j]=k;
                }
            }
        }
    }
}
void creat(T1*T){
    int c1,c2,q;
    int n=T->n;
    int l=T->l;
    int i,j;
    printf("1");
    for(i=0;i<n;i++){
        printf("2");
        for(j=0;j<n;j++){
        T->a[i][j]=1000;
        T->path[i][j]=-1;
        }
    }
    for(i=0;i<l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
    }
}