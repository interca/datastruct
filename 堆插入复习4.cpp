#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int *a;
	int size;
	int max;
}T1;
T1 *T;
void creat(int max);
void insert(int number);
int delect();
 void print();
 int main(){
 	int max,n;
 	int number;
 	int i;
 	
 	printf("输入数组最大值和当前堆中元素：\n");
 	scanf("%d%d",&max,&n);
 	creat(max);
 	for(i=0;i<n;i++){
 		scanf("%d",&number);
 		insert(number);
 	}
 	int choice;
 	while(1){
 		printf("输入选择：1-插入，2-删除，3-输出\n");
 		scanf("%d",&choice);
 		switch(choice){
 			case 1:printf("输入数：\n");scanf("%d",&number);insert(number);break;
 			case 2:printf("删除的堆顶是：%d\n",delect());break;
 			case 3:print();printf("\n");break;
 		}
 	}
 	return 0;
 }
 void print(){
 	int i;
 	for(i=1;i<=T->size;i++){
 		printf("%d ",T->a[i]);
 	}
 }
 int delect(){
 	int maxsize=T->a[1];
 	int temp=T->a[T->size--];
 	int p=1;
 	int c;
 	for(;p*2<T->size;p=c){
 		c=p*2;
 		if((c!=T->size)&&T->a[c+1]>T->a[c]){
 			c++;
 		}
 		if(temp>T->a[c])break;
 		else{
 			T->a[p]=T->a[c];
 		}
 	}
 	T->a[p]=temp;
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
 	T->size=0;
 	T->a[0]=1000;
 	T->max=max;
 }
