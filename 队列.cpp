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
		printf("输入你的选择：1-插入队列，2-删除队列，3-输出队列\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入数字:\n");scanf("%d",&number);add(&list,number);break;
			case 2:ret=delect(&list);printf("返回数字是%d\n",ret);break;
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
