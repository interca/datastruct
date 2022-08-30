#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int value;
}Node;
typedef struct list{
	Node *head;
	Node *last;
}List;
int main(){
	int number,dnumber;
	void add(List*plist,int number);
	void delect(List*plist,int dnumber);
	void print(List*plist);
	int choice;
	
	List list;
	list.head=NULL;
	list.last=NULL;
	while(1){
		printf("输入你的选择：1-输入，2-删除，3-输出\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:printf("输入数字：\n");scanf("%d",&number);add(&list,number);break;
				case 2:printf("删除数字：\n");scanf("%d",&dnumber);delect(&list,dnumber);break;
				case 3:print(&list);printf("\n");break; 
			}
		}
	return 0;
}
void add(List *plist,int number){
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
void print(List*plist){
	Node*p=plist->head;
		for(;p;p=p->next){
			printf("%d ",p->value);
		}
	}

void delect(List*plist,int dnumber){
	Node*p=plist->head;
	Node*q=NULL;
	for(;p;q=p,p=p->next){
		if(p->value==dnumber){
			if(q==NULL){
				plist->head=plist->head->next;
		 }
		 else {
		 	q->next=p->next;
		 }
		 free(p);break;
		}
	}
}
