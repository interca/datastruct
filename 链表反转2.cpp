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
int n;
void print(Node*head);
void add(List*plist,int number);
void change(List*head,int n);
int main(){
	int number;
	printf("输入N：\n");
	scanf("%d",&n);
	int k;
	
	printf("输入反转数：\n");
	scanf("%d",&k);
	List list;
	list.head=NULL;
	list.last=NULL;
	for(int i=1;i<=n;i++){
		scanf("%d",&number);
		add(&list,number);
	}
	print(list.head);
	printf("\n");
	change(&list,k);
	print(list.head);
	return 0;
} 
void change(List*plist,int k){
	Node*old=plist->head;;
	Node*ne=old->next;
	Node*flag=ne->next;
	for(int i=1;i<k;i++){
		ne->next=old;
		old=ne;
		if(flag!=NULL)ne=flag;
		if(flag!=NULL)flag=flag->next; 
	}
	if(k!=n){
		plist->head->next=ne;
		plist->head=old;
	}
     else {
     	plist->head->next=NULL;
     	plist->head=old;
     }
}
void print(Node*head){
	for(;head;head=head->next){
		printf("%d ",head->value);
	}
}
void add(List*plist,int number){
	Node*p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	p->value=number;
	if(plist->head==NULL){
		plist->head=p;
		plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p; 
	}
} 
