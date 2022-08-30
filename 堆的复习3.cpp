#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int *a;
	int max;
	int size;
}T1;
T1*T;
void creat(int max);
void insert(int number);
int delect();
void  print();
int main(){
	int max,n;
	printf("输入数组最大值和当前值：\n");
	scanf("%d%d",&max,&n);
	creat(max);
	int i;
	int number;
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(number);
	} 
	int choice;
	while(1){
		printf("输入选择：1-插入结点，2-删除结点，3-打印堆\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入插入数字：\n");scanf("%d",&number);insert(number);break;
			case 2:printf("删除数字是:%d\f",delect());break;
			case 3:print();printf("\n");break;
		}
	}
	return 0;
} 
void print(){
	for(int i=1;i<=T->size;i++){
		printf("%d ",T->a[i]);
	}
}
int delect(){
	int maxsize=T->a[1];
	int temp=T->a[T->size--];
	int parent=1;
	int chid;
	for(;parent*2<=T->size;parent=chid){
		chid=parent*2;
		if((chid!=T->size)&&T->a[chid+1]>T->a[chid]){
			chid++;
		}
		if(T->a[chid]<temp)break;
		else{
			T->a[parent]=T->a[chid];
		} 
	}
	T->a[parent]=temp;
	return maxsize;
}
void insert(int number){
	int i=++T->size;
	for(;T->a[i/2]<number;i=i/2){
		T->a[i]=T->a[i/2];
	}
	T->a[i]=number;
}
void creat(int max){
T=(T1*)malloc(sizeof(T1));
T->a=(int*)malloc((max+1)*sizeof(int));
T->max=max;
T->size=0;
T->a[0]=1000;
}
