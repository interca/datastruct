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
	int n,number;
	int max; 
	int i;
	
	printf("�������max,��ǰ����Ԫ��N��\n");
	scanf("%d%d",&n,&max);
	creat(max);
	for(i=0;i<max;i++){
		scanf("%d",&number);
		insert(number);
	}
	int choice;
	while(1){
		printf("�������ѡ��1-����ѣ�2-ɾ���Ѷ�Ԫ�أ�3-����Ԫ��\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:print();printf("\n");break;
			case 2:printf("ɾ��Ԫ����%d\n",delect());break;
			case 3:printf("�������Ԫ�أ�\n");scanf("%d",&number);insert(number);
		} 
	}
	return 0;
}
void print(){
	for(int i=1;i<=T1->size;i++){
		printf("%d ",T1->a[i]);
	}
}
int delect(){
	int maxsize=T1->a[1];
	int temp=T1->a[T1->size--];
	int parent=1;
	int chid;
	for(;parent*2<=T1->size;parent=chid){
		chid=parent*2;
		if((chid!=T1->size)&&T1->a[chid+1]>T1->a[chid]){
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
void insert(int number){
	int i=++T1->size;
	for(;T1->a[i/2]<number;i=i/2){
		T1->a[i]=T1->a[i/2];
	}
	T1->a[i]=number;
}
void creat(int max){
	T1=(T*)malloc(sizeof(T));
	T1->a=(int*)malloc((max+1)*sizeof(int));
	T1->size=0;
	T1->max=max;
	T1->a[0]=10000;
}
