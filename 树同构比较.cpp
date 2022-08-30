#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int left;
	int right;
	char value;
}T;

int findroot(int n,T T3[10]);
int compare(int r1,int r2,T T1[10],T T2[10]);
int main(){
	int n;
	T T1[10];
     T T2[10];
	printf("输入N：\n");
	scanf("%d",&n);
	printf("输入第一棵树：\n");
	getchar();
	int r1=findroot(n,T1);
	printf("输入N：\n");
	scanf("%d",&n);
	printf("输入第二棵树：\n");
	getchar();
	int r2=findroot(n,T2);
	int imprise=compare(r1,r2,T1,T2);
	if(imprise==1)printf("同构\n");
	else{
		printf("不同构\n");
	}
	return 0;
}
int findroot(int n,T T3[10]){
	int i;
	char c1,c2;
	int check[20];
	for(i=0;i<n;i++){
		check[i]=0;
	}
	for(i=0;i<n;i++){
		scanf("%c%c%c",&T3[i].value,&c1,&c2);
		if(c1!='-'){
			T3[i].left=c1-'0';
			check[c1-'0']=1;
		}
		else{
			T3[i].left=-1;
		}
		if(c2!='-'){
			T3[i].right=c2-'0';
			check[c2-'0']=1;
		}
		else{
			T3[i].right=-1;
		}
	}
	for(i=0;i<n;i++){
		if(check[i]==0)break;
	}
	printf("%d\n",i);
	return i;
}
int compare(int r1,int r2,T T1[10],T T2[10]){
	if(r1==-1&&r2==-1)return 1;
	if((r1==-1&&r2!=-1)||r1!=-1&&r2==-1)return 0;
	if(T1[r1].value!=T2[r2].value)return 0;
	if((T1[r1].left==-1)&&(T2[r2].left==-1))return compare(T1[r1].right,T2[r2].right,T1,T2);
	if((T1[r1].right==-1)&&(T2[r2].right==-1))return compare(T1[r1].left,T2[r2].left,T1,T2);
	if((T1[r1].left!=-1&&T2[r2].left!=-1)&&T1[T1[r1].left].value==T2[T2[r2].left].value)return compare(T1[r1].left,T2[r2].left,T1,T2)&&compare(T1[r1].left,T2[r2].left,T1,T2);
	else return compare(T1[r1].left,T2[r2].right,T1,T2)&&compare(T1[r1].right,T2[r2].left,T1,T2);

}
