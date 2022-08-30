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
typedef struct t{
	int a[100][100];
	int flag[100];
	
}T1;
int n;
void creat(T1*plist);
void nfs(T1*plist,int k);
int main(){
	int i,m;
	int c1,c2;
	
	printf("输入结点数N和边数M：\n");
	scanf("%d%d",&n,&m);
	T1 T;
	creat(&T);
	printf("输入边：\n");
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	}
	for(i=0;i<n;i++){
		if(T.flag[i]==0){
			printf("集合有：\n");
			nfs(&T,i);
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
	else{
		plist->last->next=p;
		plist->last=p;
	}
}
void nfs(T1*plist,int k){
	int i;
	plist->flag[k]=1;
	List list;
	list.head=list.last=NULL;
	push(&list,k);
	while(list.head){
		k=pop(&list);
		printf("%d ",k);
		for(i=0;i<n;i++){
			if(plist->flag[i]==0&&plist->a[k][i]==1){
				plist->flag[i]=1;
				push(&list,i);
			}
		}
	}
}
void creat(T1*plist){
	int i,j;
	for(i=0;i<n;i++){
		plist->flag[i]=0;
		for(j=0;j<n;j++){
			plist->a[i][j]=-1;
		}
	}
}
