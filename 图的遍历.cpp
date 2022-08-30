#include<stdio.h>
void dfs(int road[][100],int a[],int i,int n);
int main(){
	int i,j,n;
	printf("输入点个数：\n");
	scanf("%d",&n);
	int road[n][100];
	int data[n];
	for(i=0;i<n;i++){
		data[i]=0;
		for(j=0;j<n;j++){
			scanf("%d",&road[i][j]);
		}
	}
	for(i=0;i<n;i++){
		if(data[i]==0){
			printf("这一组数字有：\n");
			dfs(road,data,i,n);
		}
	}
	return 0;
}
void dfs(int road[][100],int a[],int i,int n){
	printf("%d\n",i);
      a[i]=1;
      for(int j=0;j<n;j++){
      	if(road[i][j]==1&&j!=i&&a[j]==0)dfs(road,a,j,n);
      }
}

