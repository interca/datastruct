#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int *a;
	int size;
	int max;
}T;
T*T1;
void creat(int max);
void insert(int number);
void print();
int delect();
int main(){
	int max;
	int number;
	int choice;
	printf("输入最大值\n");
	scanf("%d",&max);
	creat(max);
	int i;
	printf("构建堆\n");
	int n;
	printf("输入堆中国数量N：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(number);
	}
	while(1){
		printf("输入你的选择：1-插入，2-删除，3-打印\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入插入的数字：\n");scanf("%d",&number);insert(number);break; 
			case 2:printf("删除的数字是%d\n",delect());break;
			case 3:print();printf("\n");break;
		}
	}
	
} 
int  delect(){
	int maxsize=T1->a[1];
	int parent=1;
	int chid;
	int temp=T1->a[T1->size--];
	for(;parent*2<=T1->size;parent=chid){
		chid=parent*2;
		if(chid!=T1->size&&T1->a[chid]<T1->a[chid+1]){
			chid++;
		}
		if(T1->a[chid]<temp)break;
		else {
			T1->a[parent]=T1->a[chid]; 
		}
	}
	T1->a[parent]=temp;
	return maxsize;
}
void print(){
	int i;
	for(i=1;i<=T1->size;i++){
		printf("%d ",T1->a[i]);
	}
}
void insert(int number){
	int i;
	if(T1->size==T1->max){
		printf("堆已经满了");
	}
	else {
		i=++T1->size;
		for(;T1->a[i/2]<number;i=i/2){
			T1->a[i]=T1->a[i/2];
		}
		T1->a[i]=number;
	}
}
void creat(int max){
	T1=(T*)malloc(sizeof(T));
	T1->a=(int*)malloc((max+1)*sizeof(int));
	T1->max=max;
	T1->size=0;
	T1->a[0]=1000;
}
