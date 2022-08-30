#include<stdio.h>
#include<stdlib.h> 
typedef struct tree{
	struct tree*left;
	struct tree*right;
	int value;
}Tree;
typedef struct root{
	struct tree *head;
}Root;
typedef struct node{
	Tree*jie;
	struct node *next;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
int main(){
	int number,n;
	void add(Root*plist,int number);
	void print(Tree *head);
	void push(List*plist,Tree**p);
	Tree * pop(List*plist);
	
	Root root;
	root.head=NULL;
	printf("输入N：\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("输入数字：\n");
		scanf("%d",&number);
		add(&root,number); 
	}
	print(root.head);
}
void push(List*plist,Tree **p){
	Node*q=(Node*)malloc(sizeof(Node));
	q->jie=*p;
	q->next=NULL;
	if(plist->head==NULL){
		plist->head=q;
		plist->last=q;
	}
	else{
		plist->last->next=q;
		plist->last=q;
	}
}
Tree * pop(List*plist){
	Node*p;
	p=plist->head;
	plist->head=plist->head->next;
	return p->jie; 
}
void print(Tree*head){
	List list;
	Tree*temp;
	list.head=NULL;
	list.last=NULL;
	push(&list,&head);
	while(list.head){
		temp=pop(&list);
		printf("%d ",temp->value);
		if(temp->left){
		    push(&list,&temp->left);
		}
		if(temp->right){
			push(&list,&temp->right);
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
			printf("输入选择：1-左子树，2-右子树\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:if(temp->left==NULL){
					temp->left=p;temp=NULL;
				}
				else temp=temp->left;break;
				case 2:if(temp->right==NULL){
					temp->right=p;temp=NULL;
				}
				else {
					temp=temp->right;
				}break; 
			}
		}
	}
}
