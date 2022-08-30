#include<stdio.h>
#include<stdlib.h>
typedef struct T{
	int *a;
	int size;
	int max;
}T1;
T1*T;
void creat(int max);
void insert(int number);
void print();
int main(){
	int n,k,number;
	int i;
	
	printf("输入堆数量N和测试组数k：\n");
	scanf("%d%d",&n,&k);
	creat(n);
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(number);
	}
	printf("输入数据：\n");
	getchar();
	for(i=0;i<k;i++){
		scanf("%d",&number);
		printf("%d ",T->a[number]);
		while(number>1){
			number=number/2;
			printf("%d ",T->a[number]);
		}
		printf("\n");
	}
	return 0;
} 
void insert(int number){
	int i=++T->size;
	for(;T->a[i/2]>number;i=i/2){
		T->a[i]=T->a[i/2];
	}
	T->a[i]=number;
}
void creat(int max){
	T=(T1*)malloc(sizeof(T));
	T->a=(int*)malloc((max+1)*sizeof(int));
	T->a[0]=-10000;
	T->size=0;
	T->max=0;
}
