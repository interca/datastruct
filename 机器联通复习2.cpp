#include<stdio.h>
#include<math.h>
void input(int a[]);//������������
void check(int a[]);//������������ǲ�����ͨ��
void  connect(int a[],int n);
void creat(int a[],int n);//���ɻ������ҳ�ʼ��
int findroot(int a[],int x);//���Ҳ����ظ�
void unio(int a[],int r1,int r2);//������������ͨ
int main(){
	int n;
	char in;
	printf("���������������\n");
	scanf("%d",&n);
	int a[n];
	creat(a,n);
	while(in!='s'){
		scanf("%c",&in);
		switch(in){
			case 'i':input(a);break;
			case 'c':check(a);break;
			case 's':connect(a,n);break;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("%d",findroot(a,4));
	printf("%d",findroot(a,0));
	return 0; 
} 
void unio(int a[],int r1,int r2){
	a[r1]=r2;
}
int findroot(int a[],int x){
	for(;a[x]>=0;x=a[x]);
	return x;
}
void connect(int a[],int n){
	int count=0;
	for(int i=0;i<n;i++){
		if(a[i]==-1)count++;
	}
	if(count==1)printf("All machines are connected\n");
	else printf("There are %d machines connection\n",count);
}
void check(int a[]){
	int u,v;
	scanf("%d%d",&u,&v);
	int r1=findroot(a,u);
	int r2=findroot(a,v);
	printf("%d%d\n",r1,r2);
	if(r1!=r2)printf("NO\n");
	else printf("YES\n");
}
void input(int a[]){
	int u,v;
	scanf("%d%d",&u,&v);
	int r1=findroot(a,u);
	int r2=findroot(a,v);
	if(r1!=r2){
		unio(a,r1,r2);
	}
}
void creat(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		a[i]=-1;
	}
}
