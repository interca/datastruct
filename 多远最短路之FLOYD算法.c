#include<stdio.h>
#include<stdlib.h>
typedef struct T{
    int d[100][100];//最短距离图
    int g[100][100];//图本身
    int path[100][100];//打印路径

}T1;

void floyed(T1*T,int n);
void creat(T1*T,int n);
void print();
void printroot(T1*T,int i,int j);
int main(){
    int n,i,c1,c2,q,l;
    printf("input n,l:\n",&n,&l);
    scanf("%d%d",&n,&l);
    T1 T;
    creat(&T,n);
    printf("input line:\n");
    for(i=0;i<l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        T.g[c1][c2]=q;
        T.d[c1][c2]=q;
    }
    floyed(&T,n);
    print(&T);
    return 0;
}
void print(T1*T){
    int i,j,number;
    while(1){
        printf("input i and j:\n");
        scanf("%d%d",&i,&j);
        number=T->d[i][j];
        if(number!=1000){
        printf("The %d is distant %d is %d\n",i,j,number);
        printf("The root is: %d ",i);
        printroot(T,i,j);
        printf(" %d",j);
        printf("\n");
        }else{
            printf("no root\n");
        }
    }
}
void printroot(T1*T,int i,int j){
   // printf("path=%d",T->path[i][j]);
    if(T->path[i][j]>=0){
        printroot(T,i,T->path[i][j]);
        printf("%d ",T->path[i][j]);
        printroot(T,T->path[i][j],j);
    }

}
void floyed(T1*T,int n){

    int k,i,j;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(T->d[i][k]+T->d[k][j]<T->d[i][j]){
                    T->d[i][j]=T->d[i][k]+T->d[k][j];
                    T->path[i][j]=k;
                }
            }
        }
    }
}
void creat(T1*T,int n){
    int i,j;
    int c1,c2,q;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            T->d[i][j]=1000;
            T->g[i][j]=1000;
            T->path[i][j]=-1;
        }
    }
   
}