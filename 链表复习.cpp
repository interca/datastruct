#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	 Node *head;
	 Node *lastof;
}List;
int main(){
	int number,delectnumber;
	void add(List *plist,int number);//������� 
	int  delect(List *plist,int delectnumber);//ɾ������
	void print(List*plist);
	List list;
	list.head =NULL;
	list.lastof=NULL;
	
	printf("��������\n");
	do{
		scanf("%d",&number);
		if(number!=-1){
			add(&list,number);
		}
	}while(number!=-1);
	print(&list);
	printf("����ɾ�������֣�\n");
	scanf("%d",&delectnumber);
	int imprise=delect(&list,delectnumber);
	if(imprise==1)printf("û���ҵ�\n");
	else printf("\n");
	print(&list);
	return 0;
} 
void add(List *plist,int number){
	Node *p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=p;
		plist->lastof=plist->head;
	}
	else{
		plist->lastof->next=p;
		plist->lastof=p;
	}
}
void print(List *plist){
	Node *p;
	for(p=plist->head;p;p=p->next){
		printf("%d ",p->value);
	}
}

int delect(List *plist ,int delectnumber){
	Node *p=plist->head;
	Node *q=NULL;
	int imprise=1;
	for(;p;q=p,p=p->next){
		if(p->value==delectnumber){
			imprise=0;
			if(q==NULL){
				plist->head=p->next;
			}
			else{
				q->next=p->next;
			}
			free(p);break;	
		}
	}
	return imprise;
}
