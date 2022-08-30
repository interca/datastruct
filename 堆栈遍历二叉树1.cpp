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
	struct node *next;
}Node;
typedef struct list{
	Node *head;
}List;
int main(){
	int n,number;
	void add(Root*plist,int number);
	void print(Tree*head1);
	void push(List*plist,Tree**p);
	Tree*pop(List*plist);
	Root root;
	root.head=NULL;
	printf("输入个数：\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("输入数字：\n");
		scanf("%d",&number);
		add(&root,number);
	}
	print(root.head);
	return 0;
}
void push(List *plist,Tree**p){
	Node *q=(Node*)malloc(sizeof(Node));
	q->jie=*p;
	q->next=NULL;
	if(plist->head==NULL){
		plist->head=q;
	}
	else {
		q->next=plist->head;
		plist->head=q;
	}
}
Tree *pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	 return temp->jie;
}
void print(Tree*head1){
	Tree*head=head1;
	List list;
	list.head=NULL;
	while(head!=NULL||list.head!=NULL){
		while(head){
			push(&list,&head);
			head=head->left;
		}
		if(list.head){
			head=pop(&list);
			printf("%d ",head->value);
			head=head->right;
		}
	}
}
void add(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	int choice;
	Tree*temp=plist->head;
	if(plist->head==NULL){
		plist->head=p;
	}
	else{
		temp=plist->head;
		while(temp){
			printf("输入选择：1-左子树，2-右子树：\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:if(temp->left==NULL){
					temp->left=p;temp=NULL;
				}
				else {
					temp=temp->left;
				}break;
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
