#include<stdio.h>
typedef struct T{
	int a[100][100];
	int flag[100];
}T1;
void creat();
void dfs(int k);
int n;
T1 T;
int main(){
	int i,j;
	int m;
	int c1,c2;
	
	printf("输入N和边数M：\n");
	scanf("%d%d",&n,&m);
	creat();
	printf("输入边\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	}
	for(i=0;i<n;i++){
		if(T.flag[i]==0){
			printf("这个集合有:\n");
			dfs(i);
			printf("\n");
		}
	}
	return 0;
} 
void dfs(int k){
	T.flag[k]=1;
	printf("%d ",k);
	for(int i=0;i<n;i++){
		if(T.flag[i]==0&&T.a[k][i]==1){
			dfs(i);
		}
	}
}
void creat(){
	int i;
	int j;
	for(i=0;i<n;i++){
		T.flag[i]=0;
		for(j=0;j<n;j++){
			T.a[i][j]=-1;
		}
	}
}
