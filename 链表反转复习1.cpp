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
void insert(List*plist,int number);
void print(Node*head);
void change(List*plist,int n);
int main(){
	int k,n;
	List list;
	int number; 
	list.head=NULL;
	list.last=NULL;
	
	printf("输入链表元素N和反转数：\n");
	scanf("%d%d",&n,&k);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&list,number);
	}
	print(list.head);printf("\n");
	change(&list,k);
	print(list.head);
	return 0;
} 
void print(Node*head){
	for(;head;head=head->next){
		printf("%d ",head->value);
	}
}
void change(List*plist,int n){
	int i;
	Node*old=plist->head;
	Node*ne=old->next;
	Node*temp=ne->next;
	for(i=1;i<n;i++){
		ne->next=old;
		old=ne;
		ne=temp;
		ne=temp;
		if(temp!=NULL){
			temp=temp->next;
		}
	}
	plist->head->next=ne;
	plist->head=old;
	
}
void insert(List*plist,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(plist->head==NULL){
		plist->last=plist->head=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
