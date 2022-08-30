#include<stdio.h>
#include<math.h>
int findroot(int a[],int x);
void check(int a[]);
void unio(int a[],int r1,int r2);
void are(int a[],int n);
void input(int a[]);
void creat(int a[],int n);
int main(){
	int n;
	char choice;
	printf("输入机器数量N：\n");
	scanf("%d",&n);
	int a[n];
	
	creat(a,n);
	printf("输入指令：\n");
	do{
		scanf("%c",&choice);
		switch(choice){
			case 'c':check(a);break;
			case 'i':input(a);break;
			case 's':are(a,n);break;
		}
	}while(choice!='s');
	return 0;
} 
int findroot(int a[],int x){
	for(;a[x]>=0;x=a[x]);
	return x;
}
void are(int a[],int n){
	int i;
	int count=0;
	for(i=0;i<n;i++){
		if(a[i]==-1)count++;
	}
	if(count==1)printf("所有机器联通\n");
	else printf("共有%d个联通区域\n",count);
}
void unio(int a[],int r1,int r2){
	a[r1]=r2;
}
void input(int a[]){
	int c1,c2;
	scanf("%d%d",&c1,&c2);
	int r1=findroot(a,c1);
	int r2=findroot(a,c2);
	if(r1!=r2){
		unio(a,r1,r2);
	} 
}
void check(int a[]){
	int c1,c2;
	scanf("%d%d",&c1,&c2);
	int r1=findroot(a,c1);
	int r2=findroot(a,c2);
	if(r1==r2)printf("YES\n");
	else printf("NO\n");
}
void creat(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		a[i]=-1;
	}
}
