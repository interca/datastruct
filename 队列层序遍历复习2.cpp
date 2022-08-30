#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree*right;
	struct tree*left;
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
	Node*last;
}List;
void add(Root*plist,int number);
void print(Tree*head);
void push(List*plist,Tree*p);
Tree* pop(List*plist); 
int main(){
	int number,n;
	Root root;
	root.head=NULL;
	printf("输入数字N：\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("输入数字：\n");
		scanf("%d",&number);
		add(&root,number);
	}
	print(root.head);
	return 0;
}
void push(List*plist,Tree*p){
	Node*q=(Node*)malloc(sizeof(Node));
	q->jie=p;
	q->next=NULL;
	if(plist->head==NULL){
		plist->head=q;
		plist->last=q;
	} 
	else {
		plist->last->next=q;
		plist->last=q;
	}
}
Tree *pop(List*plist){
	Node*p=plist->head;
	plist->head=plist->head->next;
	return p->jie;
}
void print(Tree*head){
	List list;
	list.head=NULL;
	list.last=NULL;
	push(&list,head);
	while(list.head){
		head=pop(&list);
		printf("%d ",head->value);
		if(head->left){
			push(&list,head->left);
		}
		if(head->right){
			push(&list,head->right);
		}
	}
}
void add(Root*plist,int number){
	int choice;
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		Tree*temp=plist->head;
		while(temp){
			printf("输入你的选择：\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:if(temp->left==NULL){
					temp->left=p;temp=NULL;
				}
				else temp=temp->left;break;
				case 2:if(temp->right==NULL){
					temp->right=p;temp=NULL;
				}
				else temp=temp->right;break;
			}
		}
	}
}
