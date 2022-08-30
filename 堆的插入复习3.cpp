#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int *a;
	int size;
	int max;
}T;
T*T1;
void creat(int n);
void creattree(int number);
void insert(int number);
int delect();
void print();
int main(){
	int n,number;
	int max=20;
	printf("�������Ԫ�ظ�����\n");
	scanf("%d",&n);
	creat(max);
	printf("���ɶ�\n");
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		creattree(number);
	}
	int choice;
	while(1){
		printf("�������ѡ��1-����ѣ�2-ɾ���Ѷ���3-��ӡ�ѣ�\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("�����������֣�\n");scanf("%d",&number);insert(number);break;
			case 2:printf("ɾ������ֵ��%d\n",delect());break;
			case 3:print();printf("\n");break;
		} 
	}
	return 0;
}
int delect(){
	int maxsize=T1->a[1];
	int temp=T1->a[T1->size--];
	int parent=1;
	int chid;
	for(;parent*2<=T1->size;parent=chid){
		chid=parent*2;
		if((chid!=T1->size)&&(T1->a[chid+1]>T1->a[chid])){
			chid++;
		}
		if(T1->a[chid]<temp)break;
		else {
			T1->a[parent]=T1->a[chid];
		}	
	}
	T1->a[parent]=temp;
	return maxsize ;
}
void insert(int number){
	if(T1->size==T1->max)printf("���Ѿ�����\n");
    else {
    	int i=++T1->size;
    	for(;T1->a[i/2]<number;i=i/2){
    		T1->a[i]=T1->a[i/2];
    	}
    	T1->a[i]=number;
    }
}
void print(){
	for(int i=1;i<=T1->size;i++){
		printf("%d ",T1->a[i]);
	}
}
void creat(int n){
	T1=(T*)malloc(sizeof(T));
	T1->a=(int*)malloc((n+1)*sizeof(int));
	T1->max=n;
	T1->size=0;
	T1->a[0]=1000;
}
void creattree(int number){
	int i;
	i=++T1->size;
	for(;T1->a[i/2]<number;i=i/2){
		T1->a[i]=T1->a[i/2];
	}
	T1->a[i]=number;
}

