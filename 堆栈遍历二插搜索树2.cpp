#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree*left;
	struct tree*right;
	int value;
}Tree;
typedef struct root{
	Tree*head;
}Root;
typedef struct node{
	Tree*jie;
	struct node*next;
}Node;
typedef struct list{
	Node*head;
}List;
void print(Tree*head);
void push(List*plist,Tree*p);
Tree*pop(List*plist);
void insert(Root*plist,int number);
Tree*findmax(Tree*head);
Tree*findmin(Tree*head);
Tree*delect(Tree*head ,int number);
int main(){
	int n,number;
	int choice;
	int i;
	printf("输入N：\n");
	scanf("%d",&n);
	Root root;
	root.head=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root,number);
	}
	while(1){
		printf("输入选择：1-插入，2-删除，3-打印，4-最大值，5-最小值：\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入数字：\n");scanf("%d",&number);insert(&root,number);break;
			case 2:printf("输入删除数字：\n");scanf("%d",&number);delect(root.head,number);break;
			case 3:print(root.head);printf("\n");break;
			case 4:printf("最大值是%d\n",findmax(root.head)->value);break;
			case 5:printf("最小值是%d\n",findmin(root.head)->value);break;
		}
	}
	return 0;
}
Tree*delect(Tree*head,int number){
	Tree*temp;
	if(head==NULL)printf("没有找到\n");
	else if(number>head->value){
			head->right=delect(head->right,number);	
		}
		else if(number<head->value){
			head->left=delect(head->left,number);
		}
		else {
			if(head->left&&head->right){
			temp=findmax(head->left);
			head->value=temp->value;
			head->left=delect(head->left,temp->value);
		}
		else {
			temp=head;
			if(head->left==NULL){
				head=head->right;
			}
			else {
				head=head->left;
			}
			free(temp);
		}
		}
	return head; 
}
Tree*findmin(Tree*head){
	while(head->left){
		head=head->left;
	}
	return head;
}
Tree*findmax(Tree*head){
	while(head->right){
		head=head->right;
	}
	return head;
}
Tree*pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->jie;
}
void push(List*plist,Tree*p){
	Node*temp=(Node*)malloc(sizeof(Node));
	temp->jie=p;
	temp->next=NULL;
	if(plist->head==NULL){
		plist->head=temp;
	}
	else {
		temp->next=plist->head;
		plist->head=temp;
	}
}
void print(Tree*head){
	List list;
	list.head=NULL;
	while(head||list.head){
		while(head){
			push(&list,head);
			head=head->left;
		}
		if(list.head){
			head=pop(&list);
			printf("%d ",head->value);
			head=head->right;
		} 
	}
}
void insert(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->value=number;
	p->left=p->right=NULL;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		Tree*temp=plist->head;
		while(temp){
			if(number>temp->value){
				if(temp->right==NULL){
					temp->right=p;break;
				}
				else {
					temp=temp->right;
				}
			}
			else {
				if(temp->left==NULL){
					temp->left=p;break;
				}
				else {
					temp=temp->left;
				}
			}
		}
	}
}
