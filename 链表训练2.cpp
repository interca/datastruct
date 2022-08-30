#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct node{
	struct node *next;
	int value;
}Node;
typedef struct list{
	Node *head;
	Node *lastof;
}List; 
int main(){
	int number;
	int dnumber;
	List list;
	list.head=NULL;
	list.lastof=NULL;
	 void add(List *plist,int number);
	 void print(List*plist);
	 int delect(List *plist,int dnumber);
	 printf("输入链表\n");
	 do{
	 	scanf("%d",&number);
	 	if(number!=-1){
	 		add(&list,number);
	 	}
	 }while(number!=-1);
	 print(&list);
	 printf("输入删除数字：\n");
	 scanf("%d",&dnumber);
	 int imprise=0;
	 imprise=delect(&list,dnumber);
	 printf("%d\n",imprise);
	 if(imprise==1){
	 	print(&list);
	 }
	 else {
	 	printf("没找到\n");
	 	print(&list);
	 }
	 return 0;
}
void add(List*plist,int number){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(plist->lastof==NULL){
		plist->head=p;
		plist->lastof=plist->head;
	}
	else {
		plist->lastof->next=p;
		plist->lastof=p;
	}
}
void print(List *plist){
	Node *p=plist->head;
	for(;p;p=p->next){
		printf("%d  ",p->value);
	} 
}
int delect(List*plist,int dnumber){
	int imprise=0;
	Node *q=NULL;
	Node*p=plist->head;
	for(;p;q=p,p=p->next){
		if(p->value==dnumber){
			imprise=1;
			if(q==NULL){
				plist->head=p->next; 
			}
			else {
				q->next=p->next;
			}
			free(p);
			break;
		}
	}
	return imprise;
}

