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
void insert(Root*list,int number);
void print(Tree*head);
void push(List*plist,Tree*p);
Tree*pop (List*plist);
void print(Tree*head);
Tree*find(Tree*head,int number);
Tree*findmax(Tree*head);
Tree*findmin(Tree*head);
Tree*delect(Tree*head,int number);
int main(){
	int n,number;
	printf("输入N:\n");
	scanf("%d",&n);
	int i;
	Root root;
	root.head=NULL;
	
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root,number);
	}
	int choice;
	while(1){
		printf("1-insert,2-delect,3-find,4-findmax,5-findmin,6-print\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("插入结点：\n");scanf("%d",&number);insert(&root,number);break;
			case 2:printf("输入删除结点：\n");scanf("%d",&number);delect(root.head,number);break;
			case 3:printf("输入查找结点：\n");scanf("%d",&number);printf("The root is%d\n",find(root.head,number)->value);break;
			case 4:printf("The max is %d\n",findmax(root.head)->value);break;
			case 5:printf("The min is %d\n",findmin(root.head)->value);break;
			case 6:print(root.head);printf("\n");break;
		}
	}
	return 0;
}
Tree* delect(Tree*head,int number){
	Tree*temp;
	if(head==NULL)printf("NO find\n");
	else {
		if(number>head->value){
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
				else head=head->left;
				free(temp);
			}
			} 
		}
	return head;
}
Tree*findmax(Tree*head){
	while(head->right){
		head=head->right;
	}
	return head; 
}
Tree*findmin(Tree*head){
	while(head->left){
		head=head->left;
	}
	return head;
}
Tree*find(Tree*head,int number){
	while(head){
	if(number>head->value){
		head=head->right; 
	}
	else  if(number<head->value){
		head=head->left;
	}
	else return head;
   }
   return head;
}
Tree *pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->jie;
}
void push(List*plist,Tree*p){
	node*q=(Node*)malloc(sizeof(Node));
	q->jie=p;
	q->next=NULL;
	if(plist->head==NULL){
		plist->head=q;
	}
	else {
		q->next=plist->head;
		plist->head=q;
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
	p->left=p->right=NULL;
	p->value=number;
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
				else temp=temp->right;
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
