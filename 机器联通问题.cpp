#include<stdio.h>
void creat(int a[],int n);//构造机器和初始化联通集合
int findroot (int a[],int x);
 void unio(int r1,int r2,int a[]);
 void check(int a[]);//检查两个机器是不是 联通 ；
 void input(int a[]);//将两台机器连接在一起 
 void network(int a[],int n); //判断几个集合 
int main(){
	int n;
	printf("输入机器个数：\n");
	scanf("%d",&n);
	char in;
	int a[n];
	creat(a,n);
	getchar();
	do{
		//printf("输入你选择，i-联通两个机器，c-检查两个机器，s-判断几个联通通路\n");
		scanf("%c",&in);
		switch(in){
			case 'i':input(a);break;
			case 'c':check(a);break;
			case 's':network(a,n);break;
		}
	}while(in!='s');
	return 0;
}
int findroot(int a[],int x){
	for(;a[x]>0;x=a[x]);
	return x;
}
void network(int a[],int n){
	int count=0;
	int i;
	for(i=0;i<n;i++){
		if(a[i]==-1)count++;
	}
	if(count==1)printf("all machines are connect\n");
	else printf("There are %d machines in conncetion\n",count);
}
void unio(int r1,int r2,int a[]){
	a[r1]=r2;
}
void check(int a[]){
	int u,v;
	printf("输入检查两个机器编号：\n");
	scanf("%d%d",&u,&v);
	int r1=findroot(a,u-1);
	int r2=findroot(a,v-1);
	if(r1!=r2)printf("NO\n");
	else printf("YES\n");
}
void creat(int a[],int n){
	for(int i=0;i<n;i++){
		a[i]=-1;
	}
}
void input(int a[]){
	int u,v;
	printf("输入联通的机器:\n");
	scanf("%d%d",&u,&v);
	int r1=findroot(a,u-1);
	int r2=findroot(a,v-1);
	if(r1!=r2){
		unio(r1,r2,a);
	}
}
