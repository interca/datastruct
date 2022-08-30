#include<stdio.h>
#include<stdlib.h>
void insertsort(int*a,int n);
int main(){
    int n;
    printf("input n:\n");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertsort(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void insertsort(int *a,int n){
    int i,j;
    int temp;
    for(i=1;i<n;i++){
         temp=a[i];
        for(j=i;j>0&&a[j-1]>temp;j--){
            a[j]=a[j-1];
        }
        a[j]=temp;
    }
}