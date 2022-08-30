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
    void print(List *pList);
	void add(List *pList,int number);
	int  delect(List*pList,int number); 
	int number;
	int delectnumber;

	List list;
	list.head=NULL;                //结构体里面两个指针分别指向NULL，一个头，一个尾// 
	list.lastof=NULL;
	do{
		scanf("%d",&number);
		if(number!=-1) add(&list,number);
	}while(number!=-1);
	print(&list);
	printf("\n");
	printf("输入删除数字");
	scanf("%d",&delectnumber);
    int result=delect(&list,delectnumber);

	if(result==1){
		print(&list);
	}
	else {
     	printf("没有找到这个数字");
     	print(&list);
   }  
	return 0;
}
//输出函数 
void print(List *pList){
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
if(pList->head==NULL){
	pList->head=p;
	pList->lastof=pList->head;
}
	if(pList->lastof){
		pList->lastof->next=p;
		pList->lastof=p;
	}
}
//删除函数
int  delect(List*pList,int number){
	Node*p=pList->head;
	Node*q=NULL;
	int imprise=0;
	for(;p;q=p,p=p->next){
		if(p->value==number){
			imprise=1;
			if(q==NULL){
				pList->head=p->next;
			}
			else {
				q->next=p->next;
			}
			free(p);break;
		}
	}
	return imprise;
}



 

