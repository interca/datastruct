#include<stdio.h>
#include<stdlib.h>
 typedef struct _node{
       int value;
       struct _node *next;
	   }Node;
	   	typedef struct _list{
        Node *head;	
        Node *lastof;
	}List;
int main(){
	int i,j;
    void printf(List *pList);
	void add(List *pList,int number);
	int number;
	void printf(List *pList);
	List list;
	list.head=NULL;                //结构体里面两个指针分别指向NULL，一个头，一个尾// 
	list.lastof=NULL;
	do{
		scanf("%d",&number);
		if(number!=-1) add(&list,number);
	}while(number!=-1);
	printf(&list);
	return 0;
}
//输出函数 
void printf(List *pList){
	Node*p;
	for(p=pList->head;p;p=p->next){
		printf("%d ",p->value);
	}
}
//输入函数 
void add(List*pList,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
//	Node *last=pList->head;
if(pList->head==NULL){
	pList->head=p;
	pList->lastof=pList->head;
}
	if(pList->lastof){
		pList->lastof->next=p;
		pList->lastof=p;
	}
}

