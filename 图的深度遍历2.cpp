#include<stdio.h>
typedef struct T{
	int a[100][100];
	int flag[100];
}T1;
void creat(T1*plist);
void dfs(T1*plist,int k);
int n;

int main(){
	int i,j;
	int m;
	int c1,c2;
	T1 T; 
	
	printf("输入N和边数M：\n");
	scanf("%d%d",&n,&m);
	creat(&T);
	printf("输入边\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	}
	for(i=0;i<n;i++){
		if(T.flag[i]==0){
			printf("这个集合有:\n");
			dfs(&T,i);
			printf("\n");
		}
	}
	return 0;
} 
void dfs(T1*plist,int k){
	plist->flag[k]=1;
	printf("%d ",k);
	for(int i=0;i<n;i++){
		if(plist->flag[i]==0&&plist->a[k][i]==1){
			dfs(plist,i);
		}
	}
}
void creat(T1*plist){
	int i;
	int j;
	for(i=0;i<n;i++){
		plist->flag[i]=0;
		for(j=0;j<n;j++){
			plist->a[i][j]=-1;
		}
	}
}
