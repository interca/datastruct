#include<stdio.h>
typedef struct t{
	int data;
	int parent;
}T1;
int n;
void creat(T1 T[],int i,int data,int parent);
int findroot(T1 T[],int x);
 int main(){
 	int data,parent,i;
 	
 	printf("����N������\n");
 	scanf("%d",&n);
 	T1 T[n];
 	int number;
 	
 	printf("��������\n");
 	for(i=0;i<n;i++){
 		scanf("%d%d",&data,&parent);
 		creat(T,i,data,parent);
 	}
 	while(1){
 		printf("������ҵ����֣�\n");
 		scanf("%d",&number);
 		printf("�������%d\n",findroot(T,number));
 	}
 	return 0;
 }
 int findroot(T1 T[],int x){
 	int i;
 	
 	for(i=0;i<n&&T[i].data!=x;i++);
 	if(i>=n)return -1;
 	printf("%d",i);
 	for(;T[i].parent>=0;i=T[i].parent);
 	return i;
 }
 void creat(T1 T[],int i,int data,int parent){
 	T[i].parent=parent;
 	T[i].data=data;
 }
