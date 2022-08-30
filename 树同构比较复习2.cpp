#include<stdio.h>
typedef struct node{
	int  left;
	int right;
	char value;
}T;
T T1[10],T2[10];
int add(int n,T T3[10]);
int com(int R1,int R2);
int main(){
	int n;
	int R1,R2;
	
	printf("输入数字n：\n");
	scanf("%d",&n);
	getchar();
	R1=add(n,T1);
	printf("\n");
	printf("输入数字n:\n");
	scanf("%d",&n);
	getchar();
	R2=add(n,T2);
//	printf("%d %d\n",R1,R2);
	int imprise=com(R1,R2);
	printf("\n");
	if(imprise==1)printf("两棵树同构");
	else printf("不同构");
	return 0;
}
int add(int n,T T3[10]){
	char c1,c2;
	int number;
	int check[20];
	int i;
	for(i=0;i<n;i++){
		check[i]=0;
	}
	printf("输入树：\n");
	for(i=0;i<n;i++){
		scanf("%c",&T3[i].value);
		scanf("%c",&c1);
		scanf("%c",&c2);
		if(c1!='-'){
			T3[i].left=c1-'0';
			check[T3[i].left]=1;
		}
		else T3[i].left=-1;
		if(c2!='-'){
			T3[i].right=c2-'0';
			check[T3[i].right]=1;;
		}
		else T3[i].right=-1;
	}
	for(i=0;i<n;i++){
		printf("数值是%c ",T3[i].value);
	}
	for(i=0;i<n;i++){
		if(check[i]==0){
			break;
		}
	}
	return i;
}
int com(int R1,int R2){
	if(R1==-1&&R2==-1)return 1;
	if(R1==-1&&R2!=-1||R1!=-1&&R2==-1)return 0;
	if(T1[R1].value!=T2[R2].value)return 0;
	if(T1[R1].left==-1&&T2[R2].left==-1){
		return com(T1[R1].right,T2[R2].right);
	}
	if(T1[R1].right==-1&&T2[R2].right==-1){
		return com(T1[R1].left,T2[R2].left);
	}
	if(T1[R1].left!=-1&&T2[R2].left!=-1&&T1[T1[R1].left].value==T2[T2[R2].left].value){
		return com(T1[R1].left,T2[R2].left)&&com(T1[R1].right,T2[R2].right);
	}
	else {
		return com(T1[R1].left,T2[R2].right)&&com(T1[R1].right,T2[R2].left);
	}
}
