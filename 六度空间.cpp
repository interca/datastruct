#include<stdio.h>
#include<stdlib.h>
typedef struct t{
	int a[100][100];
	int data[100];
	int m,n;
}T1;
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last; 
}List;
int DFS(T1*plist,int k);
void push(List*plist,int k);
int pop(List*plist);
void creat(T1*plist,int m,int n);
int main(){
	int m,n,number;
	printf("输入结点和边数：\n");
	scanf("%d%d",&m,&n);
	T1 T;
	int i,j;
	int row,line;
	creat(&T,m,n);
	for(i=0;i<n;i++){
		scanf("%d%d",&row,&line);
		T.a[row][line]=1;
	}
	for(i=0;i<m;i++){
		if(T.data[i]==0){
			printf("占比是%f ",1.0*DFS(&T,i)/m);
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
int DFS(T1*plist,int k){
	int count=0;
	int leve=0,last=k,tail; 
	List list;
	list.head=NULL;
	list.last=NULL;
	push(&list,k);
	while(list.head){
		k=pop(&list);
		if(leve==6)break;
		printf("%d ",k);
		plist->data[k]=1;
		for(int i=0;i<plist->m;i++){
			if(plist->a[k][i]==1&&plist->data[i]==0){
				push(&list,i);
				count++;
				tail=i;
			}
		} 
		if(k==last){
			leve++,last=tail;
		} 
	}
	return count;
}
void creat(T1*plist,int m, int n){
	plist->m=m;
	plist->n=n;
	for(int i=0;i<m;i++){
		plist->data[i]=0;
	} 
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			plist->a[i][j]=0;
		}
	}
}
