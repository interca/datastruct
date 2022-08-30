#include<stdio.h>
typedef struct student{
	char left;
	char right;
	char value;
}T;
T T1[10],T2[10];
int main(){
	int n;
	int R1,R2;
	int root(int n,T T3[10]);
	int istance(int R1,int R2);
	
	printf("输入树中元素个数：\n");
	scanf("%d",&n);
	getchar();
	printf("输入树：\n");
	R1=root(n,T1);
	printf("%d\n",R1);
	printf("输入树中元素个数：\n");
	scanf("%d",&n);
	getchar();
	printf("输入树：\n");
	R2=root(n,T2);
	printf("%d\n",R2);
	int imprise=istance(R1,R2);
	if(imprise==1)printf("两棵树同构\n");
	else printf("两棵树不同构\n");
	return 0;
} 
int root(int n,T T3[10]){
	int  check[20];
	int i;
	int impris;
	char c1,c2;
	for(i=0;i<n;i++){
		check[i]=0;
	}
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
			check[T3[i].right]=1;
		}
		else T3[i].right=-1;

	}
	for(i=0;i<n;i++){
		printf("%c ",T3[i].value);
	} 
	for(i=0;i<n;i++){
		printf("%d ",check[i]);
		if(check[i]==0){
		    impris=i;	break;
		}
	}
	return impris;
}
int istance(int R1,int R2){
	printf("1");
	if(R1==-1&&R2==-1)return 1;
	if(R1==-1&&R2!=-1||R1!=-1&&R2==-1)return 0;
	if(T1[R1].value!=T2[R2].value)return 0;
	if(T1[R1].left==-1&&T2[R2].left==-1){
		return istance(T1[R1].right,T2[R2].right);
	}
	if(T1[R1].right==-1&&T2[R2].right==-1){
		return istance(T1[R1].left,T2[R2].left);
	}
	if((T1[R1].left!=-1&&T2[R2].left!=-1)&&(T1[T1[R1].left].value==T2[T2[R2].left].value)){
		return (istance(T1[R1].left,T2[R2].left)&&istance(T1[R1].right,T2[R2].right));
	}
	else {
		printf("1");
		return istance(T1[R1].left,T2[R2].right)&&istance(T1[R1].right,T2[R2].left);
	}
}

