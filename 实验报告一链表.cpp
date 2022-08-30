#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	struct node*next;
	int salary;
	char name[10];
}Node; //定义结点结构为Node 
typedef struct list{
	Node*head;
	Node*last;
}List;   //将头指针和尾指针放到结构体里并且命名为List; 
void insert(List*plist,int salary,char name[10]);  //插入结点中数据 
Node*max_list(Node*head);
void printflist(Node*head);
int main(){
	int i,salary;
	char name[10];
	List list;
	list.head=list.last=NULL;
	
	printf("依次输入员工信息：\n");
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
    printf("最高工资员工信息是：姓名：%s,工资：%d",max->name,max->salary);
	return 0;
} 
void printflist(Node*head){
	for(;head;head=head->next){
		printf("姓名:%s,工资：%d\n",head->name,head->salary);
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
void insert(List*plist,int salary,char name[10]){     //插入结点 
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
