#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
void push(List*plist,int number);
void print(Node*head);
void change(List*plist,int k,int n);
int main(){
	int n,k,i,number;
	List list;
	list.head=NULL;
	list.last=NULL;
	printf("输入链表数字和反转数：\n");
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		push(&list,number);
	}
	print(list.head);
	printf("\n");
	change(&list,k,n);
	print(list.head);
}
void change(List*plist,int k,int n){
	Node*old=plist->head;
	Node*ne=old->next;
	Node*flag=ne->next;
	for(int i=1;i<k;i++){
		ne->next=old;
		old=ne;
		ne=flag;
		if(flag->next){
			flag=flag->next;
		}
	}
	if(k==n){
		plist->head->next=NULL;
		plist->head=old;
	}
	else {
		plist->head->next=ne;
		plist->head=old;
	}
}
void print(Node*head){
	for(;head;head=head->next){
		printf("%d ",head->value);
	}
}
void push(List*plist,int number){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
