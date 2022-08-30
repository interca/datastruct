#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	Node *head;
}List;
int main(){
	int number,dnumber;
	void add(List *plist,int number);
	void delect(List*plist,int dnumber);
	void print(List*plist);
	
	List list;
	list.head=NULL;
	int choice;
	while(1){
		printf("ÊäÈëÄãµÄÑ¡Ôñ£º1-²åÈë¶ÑÕ»£¬2-É¾³ý¶ÑÕ»£¬3-Êä³ö¶ÑÕ»\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("ÊäÈëÊý×Ö£º\n");
			       scanf("%d",&number);add(&list,number);break; 
			case 2: printf("ÊäÈëÉ¾³ýÊý×Ö£º\n");scanf("%d",&dnumber);delect(&list,dnumber);break;
			case 3: print(&list);printf("\n");break;      
		}
	}
	return 0;
} 
void print(List*plist){
	Node*p=plist->head;
	for(;p;p=p->next){
		printf("%d ",p->value);
	}
}
void add(List*plist,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	p->value=number;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		p->next=plist->head;
		plist->head=p; 
	}
}
void delect(List *plist,int dnumber){
	Node*q=NULL;
	Node*p=plist->head;
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
