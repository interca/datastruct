#include<stdio.h> 
#include<stdlib.h>
typedef struct t{
	int *a;
	int size;
	int max;
}T1;
T1*T;
void insert(int number);
int delect();
void print();
void creat(int max);
int main(){
	int max,number;
	int n; 
	printf("输入数组最大容量和当前数组数量：\n");
	scanf("%d%d",&max,&n);
	creat(number);
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		insert(number);
	}
	int choice;
	while(1){
		printf("1-插入，2-删除，3-打印\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入数：\n");scanf("%d",&number);insert(number);break;
			case 2:printf("删除的数字是：%d\n",delect());break;
			case 3:print();break;
		}
	} 
	return 0;
}
int delect(){
	int maxsize=T->a[1];
	int temp=T->a[T->size--];
	int parent=1;
	int chid;
	for(;parent*2<=T->size;parent=chid){
		chid=parent*2;
		if((chid*2!=T->size)&&T->a[chid+1]>T->a[chid]){
			chid++;
		}
		if(temp>T->a[chid])break;
		else {
			T->a[parent]=T->a[chid]; 
		}
	}
	T->a[parent]=temp;
	return maxsize;
}
void insert(int number){
	int i;
	if(T->max==T->size){
		printf("堆满\n");
	}
	else {
		i=++T->size;
		for(;T->a[i/2]<number;i=i/2){
			T->a[i]=T->a[i/2];
		}
		T->a[i]=number;
	}
}
void print(){
	int i;
	for(i=1;i<=T->size;i++){
		printf("%d ",T->a[i]);
	} 
}
void creat(int max){
	T=(T1*)malloc(sizeof(T1));
	T->a=(int*)malloc((max+1)*sizeof(int));
	T->a[0]=10000;
	T->size=0;
	T->max=max;
}

