#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int**a;
    int n,l;
}T1;
void creat(T1*T);
void floyed(T1*T);
void sort(T1*T);
int findmax(T1*T,int k);
int main(){
    int n,l,i,j;
    T1 T;

    printf("inpur n,l\n");
    scanf("%d%d",&n,&l);
    T.n=n;
    T.l=l;
    T.a=(int**)malloc(sizeof(int*)*(n+1));
    for(i=1;i<=n;i++){
        T.a[i]=(int*)malloc(sizeof(int)*n);
    }
    creat(&T);
    floyed(&T);
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
       int max=-1;
       for(i=1;i<=n;i++){
           if(T->a[k][i]>max&&k!=i){
               max=T->a[k][i];
           }
       }
       return max;
   }
   void sort(T1*T){
       int i,j;
       int n=T->n;
       int max;
       int min=1000;
       int index;
       for(i=1;i<=n;i++){
         max=findmax(T,i);
         if(max<min){
             min=max;
             index=i;
         }
       }
       printf("He should take %d and the max is %d\n",index,min);
   }
   void floyed(T1*T){
       int k,i,j;
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
       int i,j,c1,c2,q;
       int n=T->n;
       for(i=1;i<=n;i++){
           for(j=1;j<=n;j++){
               T->a[i][j]=1000;
           }
       }
       for(i=0;i<T->l;i++){
           scanf("%d%d%d",&c1,&c2,&q);
           T->a[c1][c2]=T->a[c2][c1]=q;
       }
   }