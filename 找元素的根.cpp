#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int data;
	int parent;
}T;

int n;
int find(T T1[],int x);
void add(T T1[],int i,int data,int parent);
 int main(){
 	int x;
 	int data,parent;
 	printf("输入数组中元素个数n:\n");
 	scanf("%d",&n);
 	T T1[n];
 	for(int i=0;i<n;i++){
 		scanf("%d%d",&data,&parent);
 		add(T1,i,data,parent);
 	}
 	for(int i=0;i<n;i++){
 		printf("%d %d \n",T1[i].data,T1[i].parent);
 	}
 	while(1){
 		printf("输入查找的数字：\n");
 		scanf("%d",&x);
 		printf("数字的根节点坐标是%d\n",find(T1,x));
 	}
 	return 0;
 }

 void add(T T1[],int i,int data,int parent){
 	T1[i].data=data;
 	T1[i].parent=parent;

 }
 int find(T T1[],int x){
 	int i;
 	for(i=0;i<n&&T1[i].data!=x;i++);
 		if(i>=n)return -1;
 		printf("%d\n",i);
 	for(;T1[i].parent>=0;i=T1[i].parent);
 	return i;
 }
