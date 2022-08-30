#include<stdio.h>
#include<stdlib.h>
void Bubsort(int*a,int n);
int main(){
    int n,i;
    printf("input n:\n");
    scanf("%d",&n);
    int *a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Bubsort(a,n);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}
void Bubsort(int *a,int n){
    int i,j;
    int flag;
    int temp;
    for(int i=n-1;i>=0;i--){
        flag=0;
        for(j=0;j<n;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)break;
    }
}