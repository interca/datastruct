#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *a;
int *b;
void insert(int left,int right,int root);
int findnumber(int n);
void print(int n);
int main(){
    int n,i,j,number;

    printf("input the N:");
    scanf("%d",&n);
    a=(int*)malloc((n)*sizeof(int));
    b=(int*)malloc((n)*sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int temp;
    int min=0;

    for(i=0;i<n;i++){
        min=i;
        for(j=i;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;;
    }
    
    insert(0,n-1,0);
        print(n);
        return 0;
}
void print(int n){
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
}
void insert(int left,int right,int root){
    int n=right-left+1;
    int leftroot,rightroot,l;
    if(n==0)return ;
    l=findnumber(n);
    printf("L=%d\n",l);
    leftroot=root*2+1;
    rightroot=root*2+2;
    b[root]=a[left+l];
    insert(left,left+l-1,leftroot);
    insert(left+l+1,right,rightroot);
}
int findnumber(int n){
    int h=log(n+1)/log(2);
    int a=pow(2,h-1);
    int x=n-pow(2,h)+1;
    int min;
    if(a>x)min=x;
    else min=a;
    int l=pow(2,h-1)-1+min;
    return l;
}
