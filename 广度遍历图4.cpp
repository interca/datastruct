#include<stdio.h>
typedef struct t{
	int a[100][100];
	int data[100];
}T1;
T1 T;
int n;
void creat();
void dfs(int k);
int main(){
	int m,i,number;
	int c1,c2;
	
	printf("输入结点数和边数：\n");
	scanf("%d%d",&n,&m);
	creat();
	printf("输入边\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	}
	for(i=0;i<n;i++){
		if(T.data[i]==0){
			printf("集合有：\n");
			dfs(i);
			printf("\n");
		}
	} 
	return 0;
}
void dfs(int k){
	T.data[k]=1;
	printf("%d ",k);
	int i;
	for(i=0;i<n;i++){
		if(T.data[i]==0&&T.a[k][i]==1){
			dfs(i);
		}
	}
}
void creat(){
	int i,j;
	for(i=0;i<n;i++){
		T.data[i]=0;
		for(j=0;j<n;j++){
			T.a[i][j]=-1;
		}
	}
}
