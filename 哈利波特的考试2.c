#include<stdio.h>
#include<stdio.h>
typedef struct t{
    int a[100][100];
    int path[100][100];
    int n,l;
}T1;
void floyd(T1*T);
int findmax(T1*T,int k);
void sort(T1*T);
void creat(T1*T);
int main(){
    int i,j,n,l;
    T1 T;

    printf("input n and l:\n");
    scanf("%d%d",&n,&l);
    T.l=l;
    T.n=n;
    creat(&T);
    floyd(&T);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                T.a[i][j]=1000;
            }
        }
    }
    printf("\n");

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",T.a[i][j]);
        }
        printf("\n");
    }

   sort(&T);
    return 0;
}
int findmax(T1*T,int k){
    int i;
    int n=T->n;
    int max=-1000;
    for(i=1;i<=n;i++){
        if(T->a[k][i]>max&&k!=i){
            max=T->a[k][i];
        }
    }
    return max;
}
void sort(T1*T){
    int i,j;
    int min=10000;
    int v;
    int index;
    for(i=1;i<=T->n;i++){
         v=findmax(T,i);
           if(v<min){
               min=v;
               index=i;
           }
    }
    printf("he should take %d,is %d\n",index,min);
}
void floyd(T1*T){
    int i,j,k;
    int n=T->n;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(T->a[i][k]+T->a[k][j]<T->a[i][j]){
                    T->a[i][j]=T->a[i][k]+T->a[k][j];
                   
                }
            }
        }
    }
}
void creat(T1*T){
    int c1,c2,q;
    int i,j;
    for(i=1;i<=T->n;i++){
        for(j=1;j<=T->n;j++){
            T->a[i][j]=1000;
        }
    }
    for(i=1;i<=T->l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
        T->a[c2][c1]=q;
    }
}