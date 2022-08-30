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
int count_list(Node*head,int average);
int main(){
	int salary;
	char name[10];
	List list;
	list.head=list.last=NULL;
	int count=0;
	int sum=0;
	int average;
	
	printf("输入员工数据，当工资为0时候结束：\n");
	scanf("%d%s",&salary,name);
	while(salary!=0){
		insert(&list,salary,name);
		count++;
		sum=sum+salary;
		scanf("%d%s",&salary,name);
	}
	average=sum/count;
	int count2=count_list(list.head,average);
	printf("超过平均工资的人有：%d，平均工资是%d\n",count2,average);
	return 0;
}
int count_list(Node*head,int average){
	int count=0;
	for(;head;head=head->next){
		if(head->salary>=average){
			count++;
		}
	}
	return count;
}
void insert(List*plist,int salary,char name[10]){
	Node*p=(Node*)malloc(sizeof(Node));
	p->salary=salary;
	p->next=NULL;
	strcpy(p->name,name);

	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
