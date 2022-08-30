#include<stdio.h>
#include<stdlib.h>
 typedef struct _node{
       int value;
       struct _node *next;
	   }Node;
	   
	   	typedef struct _list{
        Node *head;	
	}List;
int main(){
	int i,j;
    void printf(List *pList);
	void add(List *pList,int number);
	int number;
	void printf(List *pList);
	List list;
	list.head=NULL;
	do{
		scanf("%d",&number);
		if(number!=-1) add(&list,number);
	}while(number!=-1);
	printf(&list);
	return 0;
} 
void printf(List *pList){
	Node*p;
	for(p=pList->head;p;p=p->next){
		printf("%d ",p->value);
	}
}
void add(List*pList,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	Node *last=pList->head;
	if(last){
		while(last->next){
			last=last->next;
		}
		last->next=p;
	}
	else pList->head=p;
}
