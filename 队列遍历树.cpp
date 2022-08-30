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
 	Node*last;
 }List;
 int main(){
 	int i,n,number;
 	Root root;
 	root.head=NULL;
 	void add(Root *plist,int number);
 	void print(Tree *head1);
 	void pop(List*plist,Tree**p);
 	Tree *delect(List*plist);
 	printf("输入数字n：\n");
 	scanf("%d",&n);
 	for(i=1;i<=n;i++){
 		printf("输入数字：\n");
 		scanf("%d",&number);
 		add(&root,number);
 	}
 	print(root.head);
 	return 0;
 }
 void pop(List *plist,Tree**p){
 	Node *q=(Node*)malloc(sizeof(Node));
 	q->jie=*p;
 	q->next=NULL;
 	
 	if(plist->head==NULL){
 		plist->head=q;
 		plist->last=plist->head; 
 	}
 	else {
 		plist->last->next=q;
 		plist->last=q;
 	}
 }
 Tree*delect(List*plist){
 	Node*p=plist->head;
 	plist->head=plist->head->next;
 	return p->jie;
 }
 void print(Tree *head1){
 	List list;
 	list.head=NULL;
 	list.last=NULL;
 	Tree*T;
 	Tree*head=head1;
 	pop(&list,&head);
 	while(list.head!=NULL){
 		T=delect(&list);
 		printf("%d ",T->value);
 		if(T->left){
 			pop(&list,&(T->left));
 		}
 		if(T->right){
 			pop(&list,&(T->right));
 		}
 	}
 }
 void add(Root*plist,int number){
 	Tree*p=(Tree*)malloc(sizeof(Tree));
 	p->left=NULL;
 	p->right=NULL;
 	p->value=number;
 	int choice;
 	if(plist->head==NULL){
 		plist->head=p;
 	}
 	else {
 		Tree*temp=plist->head;
 		while(temp!=NULL){
 			printf("输入选择：1-左儿子，2-右儿子\n");
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
