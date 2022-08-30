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
void print(int road[][100],int data[],int n,int k);
void push(List*plist,int n);
int pop(List*plist);
    List  list;

int main(){
	list.head=NULL;
	list.last=NULL;
	int n,i,j;
	printf("输入N:\n");
	scanf("%d",&n);
	int road[n][100];
	int data[n];
	for(i=0;i<n;i++){
		data[i]=0;
		for(j=0;j<n;j++){
			scanf("%d",&road[i][j]);
		}
	}
     for(i=0;i<n;i++){
     	if(data[i]==0){
     		printf("这组集合有：\n"); 
          	print(road,data,n,i);
        	printf("\n");
		 };
     }
	return 0;
} 
int pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->value;
}
void push(List*plist,int n){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=n;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
void print(int road[][100],int data[],int n,int k){
	int i,j;
	push(&list,k);
	while(list.head){
		i=pop(&list);
		printf("%d ",i);
		data[i]=1;
		for(j=0;j<n;j++){
			if(road[i][j]==1&&data[j]==0){
			     push(&list,j);
			}
		}
	}
	
}
