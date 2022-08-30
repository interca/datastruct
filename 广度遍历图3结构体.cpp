#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
typedef struct t{
	int a[100][100];
	int data[100];//记录结点有没有访问过 
	int m,n;//结点和边数 
}T;
void creat(T*plist,int m,int n);
void print(T*plist,int k);
void push(List*plist,int k);
int pop(List*plist);
int main(){
	int m,n,i;
	printf("输入结点和边数：\n");
	scanf("%d%d",&m,&n);
	T T1;
	int w,x;
	creat(&T1,m,n);
	printf("输入边：\n");
	for(int i=0;i<n;i++){
		scanf("%d%d",&w,&x);
		T1.a[w][x]=1;
	}
	for(int i=0;i<m;i++){
		if(T1.data[i]==0){
			print(&T1,i);
		}
	}
	printf("\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(T1.a[i][j]==1)
			printf("%d %d\n",i,j);
		}
	}
	return 0;
}
int pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->value;
}
void push(List*plist,int k){
	Node*p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	p->value=k;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
	//printf("末尾是%d ",plist->last->value);
}
void print(T*plist,int k){
	List list;
	list.head=NULL;
	list.last=NULL;
	push(&list,k);
	int i; 
	while(list.head){
		k=pop(&list);
		printf("%d ",k);
		plist->data[k]=1;
	for(i=0;i<plist->m;i++){
		if(plist->a[k][i]==1&&plist->data[i]==0){
			//printf("压入有%d ",i);
			push(&list,i);
		}
	}
  }
}
void creat(T*plist,int m,int n){
	plist->m=m;
	plist->n=n;
	for(int i=0;i<m;i++){
		plist->data[i]=0;
		for(int j=0;j<m;j++){
			plist->a[i][j]=0;
		}
	}
}

