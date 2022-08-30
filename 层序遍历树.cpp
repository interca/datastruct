#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int value;
	struct tree*left;
	struct tree*right;
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
void insert(Root*plist,int number);
void print(Tree*head);
void push(List*plist,Tree*p);
Tree*pop(List*plist);
int main(){
	int n,i,number;
	printf(" ‰»ÎN£∫\n");
	scanf("%d",&n);
	Root root;
	root.head=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root,number);
	}
	print(root.head);
	return 0;
}
Tree*pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->jie;
}
void push(List*plist,Tree*p){
	Node*temp=(Node*)malloc(sizeof(Node));
	temp->next=NULL;
	temp->jie=p;
	if(plist->head==NULL){
		plist->head=plist->last=temp;
	}
	else{
		plist->last->next=temp;
		plist->last=temp;
	}
}
void print(Tree*head){
	List list;
	list.head=NULL;
	list.last=NULL;
	push(&list,head);
	while(list.head){
		head=pop(&list);
		printf("%d ",head->value);
		if(head->left)push(&list,head->left);
		if(head->right)push(&list,head->right);
	}
}
void insert(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->left=p->right=NULL;
	p->value=number;
	if(plist->head==NULL){
		plist->head=p;
	}
	else{
		Tree*temp=plist->head;
		
		while(temp){
			if(number>temp->value){
				if(temp->right==NULL){
					temp->right=p;break;
				}
				else{
					temp=temp->right;
				}
			}
			else{
				if(temp->left==NULL){
					temp->left=p;break;
				}
				else{
					temp=temp->left;
				}
			}
		}
	}
}

