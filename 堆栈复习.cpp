#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int value;
}Node;
typedef struct list{
	Node *head;
}List;
int main(){
	List list;
	list.head=NULL;
	int number;
	int dnumber;
	void add(List*pist,int number);
	int delect(List*plist,int dnumber);
	void print(List*plist);
	int  imprise;
	int choice;
	while(1){
		printf("ÊäÈëÈçÄãµÄÑ¡Ôñ£º1-Ñ¹Èë¶ÑÕ»£¬2-³ö¶ÑÕ»£¬3-´òÓ¡¶ÑÕ»\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("ÊäÈëÊý×Ö£º\n");
			scanf("%d",&number);add(&list,number);break;
			case 2:printf("ÊäÈëÉ¾³ýÊý×Ö£º\n");scanf("%d",&dnumber);imprise=delect(&list,dnumber);printf("%d",imprise);break;
			case 3:print(&list);break;
		}
	}
	return 0;
} 
void add(List*plist,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	p->value=number;
	if(plist->head==NULL){
		plist->head=p;
	} 
	else{
		p->next=plist->head;
		plist->head=p;
	}
	
}
void print(List *plist){
	Node *p;
	p=plist->head;
	for(;p;p=p->next){
		printf("%d" ,p->value);
	}
}
int delect(List*plist,int dnumber){
	Node*q=NULL;
	Node*p=plist->head;
	int number;
	int imprise=0;
	for(;p;q=p,p=p->next){
		if(p->value==dnumber){
			if(q==NULL){
				plist->head=p->next;
			}
			else {
				q->next=p->next;
			}
			imprise=1;
			number=p->value;
			free(p);
			return number;
			break;
		}
	}
} 
