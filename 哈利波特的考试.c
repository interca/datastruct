#include<stdio.h>
#include<stdlib.h>
int a[100][100];
void creat(int n);
void floyd(int n);
void print(int n);
void findmin(int n);
int findmax(int i,int n);
int main(){
    int n,l,c1,c2,q;
    printf("input n and l:\n");
    scanf("%d%d",&n,&l);
    creat(n);
    int i;

    for(i=0;i<l;i++){
        scanf("%d%d%d",&c1,&c2,&q);
        a[c1][c2]=q;
        a[c2][c1]=q;
    }
    floyd(n);
    print(n);
    printf("\n");
    findmin(n);
    

    return 0;
}
int findmax(int i,int n){
     int max=-1000;
     for(int j=1;j<=n;j++){
         if(a[i][j]>max&&i!=j){
             max=a[i][j];
         }
     }
     return max;
}
void findmin(int n){
     int mindist=10000,maxdist,index=0;
     for(int i=1;i<=n;i++){
          maxdist=findmax(i,n);
          if(maxdist==1000){
              printf("no root");
              return ;
            }
          if(maxdist<mindist){
              mindist=maxdist;
              index=i;
          }
     }
     printf("THe animal is %d ,dist is %d\n",index,mindist);
}
void floyd(int n){
    int k,i,j;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(a[i][k]+a[k][j]<a[i][j]&&i!=j){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
}
void creat(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=1000;
        }
    }
}
void print(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}