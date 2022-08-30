#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int a[100][100];//图本身
    int g[100][100];//最短权重图
    int path[100][100];//打印路径
    int n;
    int l;
}T1;
void creat(T1*T);
void floyd(T1*T);
void print(T1*T);

void printfroot(T1*T,int i,int j);
int main(){
    int n,l,i,j;
    printf("input n,l:\n");
    scanf("%d%d",&n,&l);
    T1 T;
    T.n=n;
    T.l=l;
    creat(&T);
    floyd(&T);

    print(&T);
    return 0;
}
void printfroot(T1*T,int i,int j){
    if(T->path[i][j]>=0){
           printfroot(T,i,T->path[i][j]);
           printf("%d ",T->path[i][j]);
           printfroot(T,T->path[i][j],j);
    }
}
void print(T1*T){
    int i,j;
   while(1){
      printf("input i and j:\n ");
      scanf("%d%d",&i,&j);
      printf("THE %d distant %d is %d\n",i,j,T->g[i][j]);
      printf("The root is %d ",i);
      printfroot(T,i,j);
      printf("%d\n",j);
   }

}
void floyd(T1*T){
      int k,i,j;
      for(k=0;k<T->n;k++){
          for(i=0;i<T->n;i++){
              for(j=0;j<T->n;j++){
                  if(T->g[i][k]+T->g[k][j]<T->g[i][j]){
                      T->g[i][j]=T->g[i][k]+T->g[k][j];
                      T->path[i][j]=k;
                  }
              }
          }
      }
}
void creat(T1*T){
    int i,j;
    int c1,c2,q;
    for(i=0;i<T->n;i++){
        for(j=0;j<T->n;j++){
            T->a[i][j]=-1;
            T->g[i][j]=1000;
            T->path[i][j]=-1;
        }
    }
    for(i=0;i<T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
        T->g[c1][c2]=q;
    }
}
