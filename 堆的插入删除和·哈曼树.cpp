#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int *a;
	int size;
	int max;
}T;
T*T1;
void creat(int n);
void insert(int number);
int  delect();
void change();
void print();
int main(){
	int n,i,number;
	printf("输入数组下标N:\n"); 
	scanf("%d",&n);
	printf("创建树：\n");
	creat(n);
	int choice;
	while(1){
		printf("输入你的选择：1-插入树，2-打印树，3删除树，4-生成哈密树：\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入插入数字：\n");scanf("%d",&number);insert(number);break;
			case 2:print();printf("\n");break;
			case 3:printf("删除的结点是：%d\n",delect());break;
			case 4:break;
		}
	}
	return 0;
}
void change(){
	int i;
	for(i=1;i<T1->size;i++){
		T2=(T*)malloc(sizeof(T));
		T
	}
}
int delect(){
	int maxsize=T1->a[1];
	int temp=T1->a[T1->size--];
	int parent=1;
	int chid;
	for(;parent*2<=T1->size;parent=chid){
		chid=parent*2;
		if((chid!=T1->size)&&(T1->a[chid+1]<T1->a[chid])){
			chid++;
		}
		if(T1->a[chid]>temp)break;
		else {
			T1->a[parent]=T1->a[chid];
		}
	}
	T1->a[parent]=temp;
	return maxsize;
}
void print(){
	for(int i=1;i<=T1->size;i++){
		printf("%d ",T1->a[i]);
	}
}
void insert(int number){
	int i;
	if(T1->size==T1->max){
	printf("堆满\n");
    }
	else {
		i=++T1->size;
		for(;T1->a[i/2]>number;i=i/2){
			
			T1->a[i]=T1->a[i/2];
		}
		T1->a[i]=number;
	} 
}
void creat(int n){
	T1=(T*)malloc(sizeof(T));
	T1->a=(int*)malloc((n+1)*sizeof(int));
	T1->size=0;
	T1->max=n;
	T1->a[0]=-1000;
} 
