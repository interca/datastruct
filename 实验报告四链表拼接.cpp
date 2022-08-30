#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
void insert(List*plist,int number);
void printflist(Node*head);
void link(List*head,int number);
void printflist(Node*head);
int main(){
	int score;
	List list1;
	List list2;
	list1.head=list1.last=list2.last=list2.head=NULL;
	
	printf("输入第一组成绩：\n");
	scanf("%d",&score);
	while(score!=-1){
		insert(&list1,score);
		scanf("%d",&score);
	}
	printf("输入第二组成绩：\n");
	scanf("%d",&score);
	while(score!=-1){
		insert(&list2,score);
		scanf("%d",&score);
	} 
	
	printflist(list1.head);
	printf("\n");
	printflist(list2.head);
	printf("\n");
	Node*head=list2.head;
	for(;head;head=head->next){
		link(&list1,head->value);
	}
	printflist(list1.head);
	return 0;
}
void link(List*plist,int number){
	Node*q=NULL;
	Node*p=plist->head;
	Node*temp=(Node*)malloc(sizeof(Node));
	temp->value=number;
	temp->next=NULL;
	for(;;q=p,p=p->next){
	
		if(q==NULL&&number<=p->value){
			temp->next=plist->head;
			plist->head=temp;break;
		}
		if(p==NULL&&number>=q->value){
			q->next=temp;break;
		}
		if(q!=NULL&&p!=NULL&&number>=q->value&&number<=p->value){
			q->next=temp;
			temp->next=p;break;
		}
	}
}
void printflist(Node*head){
	for(;head;head=head->next){
		printf("%d ",head->value);
	}
}
void insert(List*plist,int number){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=number;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		Node*q=NULL;
	Node*p=plist->head;
	Node*temp=(Node*)malloc(sizeof(Node));
	temp->value=number;
	temp->next=NULL;
	for(;;q=p,p=p->next){
	
		if(q==NULL&&number<=p->value){
			temp->next=plist->head;
			plist->head=temp;break;
		}
		if(p==NULL&&number>=q->value){
			q->next=temp;break;
		}
		if(q!=NULL&&p!=NULL&&number>=q->value&&number<=p->value){
			q->next=temp;
			temp->next=p;break;
		}
	}
	}
} 
