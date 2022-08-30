#include<stdio.h>
#include<math.h>
int a[20];
void find(int left,int right,int root);
int n;
int roo[20];
void print();
int findleft(int n);
void print1();
int main(){
	printf(" ‰»ÎN£∫\n");
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]); 
	}
	int temp;
	int min=0;
	
	for(i=0;i<n;i++){
		min=i;
		for(j=i;j<n;j++){
			if(a[j]<=a[min]){
				min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	find(0,n-1,0);
	print1();
	return 0;
}
void print1(){
	for(int i=0;i<n;i++){
		printf("%d ",roo[i]);
	}
}
void print(){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
void find(int left,int right,int root){
	printf("1");
	int n;
	int l;
	n=right-left+1;
	printf("n=%d\n",n);
	if(n==0) printf("Œﬁ\n");
	else{
	l=findleft(n);
	printf("l=%d\n",l);
		roo[root]=a[left+l];
	int leftroot=root*2+1;
	int rightroot=leftroot+1;
	find(left,left+l-1,leftroot); 
	find(left+l+1,right,rightroot);	
  }
}
int findleft(int n){
	int h=log(n+1)/log(2);
	int a=pow(2,h-1);
	int x=n-pow(2,h)+1;
	int min;
	if(a>x)min=x;
	else {
		min=a;
	}
	int l=pow(2,h-1)-1+min;
	return l;
} 

