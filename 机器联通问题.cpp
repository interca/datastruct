#include<stdio.h>
void creat(int a[],int n);//��������ͳ�ʼ����ͨ����
int findroot (int a[],int x);
 void unio(int r1,int r2,int a[]);
 void check(int a[]);//������������ǲ��� ��ͨ ��
 void input(int a[]);//����̨����������һ�� 
 void network(int a[],int n); //�жϼ������� 
int main(){
	int n;
	printf("�������������\n");
	scanf("%d",&n);
	char in;
	int a[n];
	creat(a,n);
	getchar();
	do{
		//printf("������ѡ��i-��ͨ����������c-�������������s-�жϼ�����ͨͨ·\n");
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
	printf("����������������ţ�\n");
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
	printf("������ͨ�Ļ���:\n");
	scanf("%d%d",&u,&v);
	int r1=findroot(a,u-1);
	int r2=findroot(a,v-1);
	if(r1!=r2){
		unio(r1,r2,a);
	}
}
