#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct T{
	int root[100][100];
	int data[100];
	int jn;//结点数 
	int bn; //边数 
	
}T;

typedef struct node{
	int value;
	struct node*next;
}Node;
typedef struct  list{
	Node*head;
	Node*last;
}List;
void creat(T*plist,int m,int n);
void print(T*plist,int k);
void push(List*plist,int i);
int pop(List*plist);
int main(){
	int m,n;
	int row,line;
	printf("输入图结点数和边数：\n");
	scanf("%d%d",&m,&n);
	T T1;
	creat(&T1,m,n);
	printf("输入边:\n");
	for(int i=0;i<n;i++){
		scanf("%d%d",&row,&line);
		T1.root[row][line]=1;
	}
	for(int i=0;i<m;i++){
		if(T1.data[i]==0){
			print(&T1,i);
		}
	}
	printf("\n");
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(T1.root[i][j]==1){
				printf("%d %d\n",i,j);
			}
		}
	} 
	return 0;
}
int pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->value;
}
void push(List*plist,int i){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=i;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
void print(T*plist,int k){
	List list;
	list.head=NULL;
	list.last=NULL;
	push(&list,k);
	int i,j,v;
	while(list.head){
		k=pop(&list);
		printf("%d ",k);
		plist->data[k]=1;
		for(i=0;i<plist->jn;i++){
			if(plist->root[k][i]==1&&plist->data[i]==0){
				push(&list,i);
			}
		}
	}
}
void creat(T*plist,int m,int n){
	plist->jn=m;
	plist->bn=n;
	int i,j;
	for(i=0;i<m;i++){
		plist->data[i]=0;
		for(j=0;j<m;j++){
			plist->root[i][j]=0;
		}
	}
}
