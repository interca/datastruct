#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	struct node*next;
	int salary;
	char name[10];
}Node; //������ṹΪNode 
typedef struct list{
	Node*head;
	Node*last;
}List;   //��ͷָ���βָ��ŵ��ṹ���ﲢ������ΪList; 
void insert(List*plist,int salary,char name[10]);  //������������ 
Node*max_list(Node*head);
void printflist(Node*head);
int main(){
	int i,salary;
	char name[10];
	List list;
	list.head=list.last=NULL;
	
	printf("��������Ա����Ϣ��\n");
	scanf("%d%s",&salary,name);
	while(salary!=0){
		insert(&list,salary,name);
		scanf("%d",&salary);
		scanf("%s",name);
		getchar();
	} 
	printflist(list.head);
	printf("\n");
	Node*max=max_list(list.head);
    printf("��߹���Ա����Ϣ�ǣ�������%s,���ʣ�%d",max->name,max->salary);
	return 0;
} 
void printflist(Node*head){
	for(;head;head=head->next){
		printf("����:%s,���ʣ�%d\n",head->name,head->salary);
	}
}
Node*max_list(Node*head){
	Node*temp=head;
	for(;head;head=head->next){
		if(head->salary>temp->salary){
			temp=head;
		}
	}
	return temp;
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
