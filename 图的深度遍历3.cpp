#include<stdio.h>
typedef struct t{
	int a[100][100];
	int data[100];
}T1;
void creat(T1*plist);
void dfs(T1*plist,int k);
int n;
int main(){
	int m,i,number,c1,c2;
	printf("输入结点N和边M：\n");
	scanf("%d%d",&n,&m);
	T1 T;
	creat(&T);
	printf("输入边数M：\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	}
	for(i=0;i<n;i++){
		if(T.data[i]==0){
			printf("集合有：\n");
			dfs(&T,i);
			printf("\n");
		}
	}
	return 0;
} 
void dfs(T1*plist,int k){
	plist->data[k]=1;
	printf("%d ",k);
	int i;
	for(i=0;i<n;i++){
		if(plist->data[i]==0&&plist->a[k][i]==1){
			dfs(plist,i);
		}
	}
}
void creat(T1*plist){
	int i,j;
	for(i=0;i<n;i++){
		plist->data[i]=0;
		for(j=0;j<n;j++){
			plist->a[i][j]=-1;
		}
	}
}
