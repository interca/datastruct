#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	struct node*next;
	int salary;
	char name[10];
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
void insert(List*plist,int salary,char name[10]);
void del_list(List*plist,int ave);
void printflist(Node*head);
int main(){
	int salary;
	char name[10];
	List list;
	list.head=list.last=NULL;
	int ave;   //�������� 
	int count=0;
	
	printf("����Ա����Ϣ��������Ϊ0ʹ�������������\n");
	scanf("%d%s",&salary,name);
	while(salary!=0){
		insert(&list,salary,name);
		count++;
		scanf("%d",&salary);
		scanf("%s",name);
		getchar();
	}
	printflist(list.head);
	printf("\n");
	printf("����������ʣ�\n");
	scanf("%d",&ave);
    for(int i=0;i<count;i++)del_list(&list,ave);
    printflist(list.head);
	return 0;
}
void del_list(List*plist,int ave){
	Node*p=plist->head;
	Node*q=NULL;
	for(;p;q=p,p=p->next) {
		if(p->salary==ave){
			if(q==NULL){
				plist->head=p->next;
			}
			else {
				q->next=p->next;
			}
			free(p);break;
		}
	}
	
}
void printflist(Node*head){
	for(;head;head=head->next){
		printf("������%s,���ʣ�%d\n",head->name,head->salary);
	}
}
void insert(List*plist,int salary,char name[10]){     //������ 
	Node*temp=(Node*)malloc(sizeof(Node));
	temp->salary=salary;
	temp->next=NULL;
	strcpy(temp->name,name);
	if(plist->head==NULL){
		plist->head=plist->last=temp;
	}
	else {
		plist->last->next=temp;
		plist->last=temp;
	}
}
