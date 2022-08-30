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
void add(List*plist,int number);
void print(Node*head);
void change(List*plist,int k);
int main(){
	int n;
	int number;
	int i;
	int k;
	List list;
	list.head=NULL;
	list.last=NULL;
	
	printf("输入N：\n");
	scanf("%d",&n);
	printf("输入反转的个数K：\n");
	scanf("%d",&k);
	printf("输入数字到链表：\n");
	for(i=0;i<n;i++){
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
	Node*old,*ne,*flag;
	old=plist->head;
	ne=plist->head->next;
	flag=plist->head->next->next;
	for(int i=1;i<=k;i++){
		ne->next=old;
		old=old=ne;
		ne=flag;
		flag=flag->next;
	}
	plist->head->next=ne;
	plist->head=old;
	
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
