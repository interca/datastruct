#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int *a;
int *b;
void find(int left,int right,int root);
int number(int n);
void print(int n);
int main(){
	int n;
	int i,j;
	int temp,min;
	
	printf(" ‰»ÎN£∫\n");
	scanf("%d",&n);
	a=(int*)malloc((n)*sizeof(int));
	b=(int*)malloc((n)*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}

	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	
	find(0,n-1,0);
	print(n);
	return 0;
} 
void print(int n){
	for(int i=0;i<n;i++){
		printf("%d ",b[i]);
	}
}
void find(int left,int right,int root){
	int n=right-left+1;
	int leftroot;
	int rightroot;
	int l=number(n);
	printf("L=%d\n",l);
	if(n==0)return ;
	else{
	     b[root]=a[left+l];
		leftroot=root*2+1;
		rightroot=root*2+2;
		find(left,left+l-1,leftroot);
		find(left+l+1,right,rightroot);
	}
}
int number(int n){
	int h=log(n+1)/log(2);
	int a=pow(2,h-1);
	int x=n-pow(2,h)+1;
	int min;
	if(a>x)min=x;
	else min=a;
	int l=pow(2,h-1)-1+min;
	return l;
}

