#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int value;
}Node;
typedef struct list{
	Node *last;
	Node *head;
}List;
int main(){
	int number;
	List list;
	list.head=NULL;
	list.last=NULL;
	void add(List *plist,int number);
	int delect(List*plist);
	void print(List*plist);
	int choice;
	int ret; 
	while(1){
		printf("�������ѡ��1-������У�2-ɾ�����У�3-�������\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("��������:\n");scanf("%d",&number);add(&list,number);break;
			case 2:ret=delect(&list);printf("����������%d\n",ret);break;
			case 3:print(&list);break;
		}
	}
	return 0;
} 
void add(List *plist ,int number){
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
void print(List *plist){
	Node *p=plist->head;
	for(;p;p=p->next){
		printf("%d  ",p->value);
	}
}
int delect(List *plist){
	Node *p=plist->head;
	plist->head=plist->head->next;
	int number=p->value;
	free(p);
	return number;
}
