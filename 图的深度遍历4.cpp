#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int a[100][100];
	int data[100];
}T;
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
void creat(T*plist);
void wfs(T*plist,int k);
void push(List*plist,int k);
int pop(List*plist);
int n;
int main(){
	int m,number,i;
	T T1;
	int c1,c2;
	
	printf("输入结点和边：\n");
	scanf("%d%d",&n,&m);
	creat(&T1);
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T1.a[c1][c2]=1;
	}
	for(i=0;i<n;i++){
		if(T1.data[i]==0){
			printf("集合有：\n");
			wfs(&T1,i);
			printf("\n");
		}
	}
	return 0;
} 
int pop(List*plist){
	Node*head=plist->head;
	plist->head=plist->head->next;
	return head->value;
}
void push(List*plist,int k){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=k;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
void wfs(T*plist,int k){
	plist->data[k]=-1;
	List list;
	list.head=list.last=NULL;
	push(&list,k);
	while(list.head){
		k=pop(&list);
		printf("%d ",k);
		for(int i=0;i<n;i++){
			if(plist->data[i]==0&&plist->a[k][i]==1){
				plist->data[i]=1;
				push(&list,i);
			}
		}
	}
}
void creat(T*plist){
	int i,j;
	for(i=0;i<n;i++){
		plist->data[i]=0;
		for(j=0;j<n;j++){
			plist->a[i][j]=-1;
		}
	}
}
