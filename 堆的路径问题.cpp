#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int *a;
	int size;
	int max;
}T;
T*T1;
void creat(int n);
void add(int n);
int main(){
	int n,number,k;
	printf("堆中元素个数，路径个数：\n");
	scanf("%d%d",&n,&k);
	creat(n);
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		add(number);
	}
	for(int i=1;i<=T1->size;i++){
			printf("%d\n",T1->a[i]);
	}
	printf("输入路径\n");
	getchar();
	for(int i=0;i<k;i++){
		scanf("%d",&number);
		printf("%d ",T1->a[number]);
		while(number>1){
			number=number/2;
			printf("%d ",T1->a[number]);
		}
		printf("\n");
	} 
	return 0;
} 
void creat(int n){
	T1=(T*)malloc(sizeof(T));
	T1->a=(int *)malloc((n+1)*sizeof(int));
	T1->size=0;
	T1->max=n+1;
	T1->a[0]=-10000;
}
void add(int n){
	int i;
	i=++T1->size;
	for(;T1->a[i/2]>n;i=i/2){
		T1->a[i]=T1->a[i/2];
	}
	T1->a[i]=n;
}

