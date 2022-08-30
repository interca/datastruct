#include<stdio.h>
int main(){
	int n,i,j;
	printf(" ‰»ÎN£∫\n");
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
		for(j=0;j<n;j++){
			if(road[i][j]==1&&data[j]==0){
				printf("%d",j);
				data[j]=1;
			}
		}
		printf("\n");
	}
	return 0;
} 
