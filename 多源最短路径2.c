#include<stdio.h>
typedef struct t{
    int a[100][100];
    int path[100][100];
    int n,l;
}T1;
void print(T1*T);
void printroot(T1*T,int i,int j);
void creat(T1*T);
void floyd(T1*T);
int main(){
    int i,j,n,l;
    printf("input n l:\n");
    scanf("%d%d",&n,&l);
    T1 T;
    T.n=n;
    T.l=l;
    creat(&T);
    floyd(&T);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j){
                T.a[i][j]=0;
            }
        }
    }
    print(&T);
    return 0;
}
void printroot(T1*T,int i,int j){
    if(T->path[i][j]>=0){
        printroot(T,i,T->path[i][j]);
        printf("%d ",T->path[i][j]);
        printroot(T,T->path[i][j],j);
    }

}
void print(T1*T){
    int i,j;
    while(1){
        printf("input i and j:\n");
        scanf("%d%d",&i,&j);
        printf("THE %d distant %d is %d\n",i,j,T->a[i][j]);
        printf("The root is %d ",i);
        printroot(T,i,j);
        printf("%d",j);
    }
}
void floyd(T1*T){
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
    int c1,c2,n,i,j,q;
    n=T->n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           
            T->a[i][j]=1000;
            T->path[i][j]=-1;
        }
    }
    for(i=0;i<T->l;i++){
     
        scanf("%d%d%d",&c1,&c2,&q);
        T->a[c1][c2]=q;
    }
}
