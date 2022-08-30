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
	int number;
	List list;
	 list.head=NULL;
	 int choice;
	 int ret;
	void add(List *plist,int number);
	int  delect(List *plist);
	void print(List *plist);
	while(1){
		printf("ÊäÈëÑ¡Ôñ£º1-¶ÑÕ»²åÈë£¬2-¶ÑÕ»É¾³ý,3-¶ÑÕ»µÄÊä³ö\n")
		scanf("%d",&choice)
		switch(choice){
			case 1:printf("²åÈëÊý×Öµ½¶ÑÕ»£º\n")scanf("%d",&number);add(&list,number);
			case 2:ret=delect(&list);if()printf("%d\n",ret);
			case 3:print(&list);
		}
	}
	return 0;
} 
 add(List *plist,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	p->next=number;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		p->next=plist->head->next;
		plist->head=p;
	}
}
int  delect(List *plist){
	int number;
	Node *p;
	if(plist->head==NULL)return NUll;
	else {
		p=plist->head;
		plist->head=plist->head->next;
		number=p->value;
		free(p);
		return number;	
		}
}
void print(List*plist){
	Node *p;
	Node*p=plist->head;
	for(;p;p=p->next){
		printf("%d ",p->value);
	}
}
