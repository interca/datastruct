#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
void push(List*plist,int k);
int pop(List*plist);
void creat();
void wfs(int k);
typedef struct T{
	int a[100][100];
	int data[100];
}T1;
T1 T;
int n;
int main(){
	int m;
	int c1,c2;
	int i;
	printf("输入结点和边：\n");
	scanf("%d%d",&n,&m);
	creat();
	printf("输入边：\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	} 
	for(i=0;i<n;i++){
		if(T.data[i]==0){
			printf("这个集合有：\n");
			wfs(i);
			printf("\n");
		}
	} 
	return 0;
} 
void wfs(int k){
	T.data[k]=1;
	List list;
	list.head=list.last=NULL;
	push(&list,k);
	while(list.head){
		k=pop(&list);
		printf("%d ",k);
		for(int i=0;i<n;i++){
			if(T.data[i]==0&&T.a[k][i]==1){
				push(&list,i);
				T.data[i]=1;
			}
		}
	}
} 
int pop(List*plist){
	Node*p=plist->head;
	plist->head=plist->head->next;
	return p->value;
}
void push(List*plist,int k){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=k;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else{
		plist->last->next=p;
		plist->last=p;
	}
}
void creat(){
	int i,j;
	for(i=0;i<n;i++){
		T.data[i]=0;
		for(j=0;j<n;j++){
			T.a[i][j]=-1;
		}
	}	 
}
