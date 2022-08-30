#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree*left;
	struct tree*right;
	int value;
}Tree;
typedef struct root{
	Tree *head;
}Root;
typedef struct node{
	Tree*root;
	struct node *next;
}Node;
typedef struct list{
	Node *head;
}List;
int main(){
	void push(List*plist,Tree**head);
	Tree* pop(List*plist);
	int number;
	int n;
	void add(Root*plist,int number);
	void print(Tree *head);
	printf("输入结点数：\n");
	scanf("%d",&n);
	Root root;
	root.head=NULL;
	for(int i=1;i<=n;i++){
		printf("输入数字：\n");
		scanf("%d",&number);
		add(&root,number);
	}
	print(root.head);
}
void push(List*plist,Tree**head){
	Node *p=(Node*)malloc(sizeof(Node));
	p->root=*head;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=p;
	}
	else{
		p->next=plist->head;
		plist->head=p;
	}
}
Tree *pop(List*plist){
	Node*p=plist->head;
	plist->head=plist->head->next;
	return p->root;
}
void print(Tree *head){
	Tree*head1=head;
	List list;
	list.head=NULL;
	while(list.head!=NULL||head1!=0){
		while(head1!=NULL){
			push(&list,&head1);
			head1=head1->left;
		}
		if(list.head!=NULL){
			head1=pop(&list);
			printf("%d ",head1->value);
			head1=head1->right;
		}
	}
}
void add(Root*plist,int number){
	Tree *p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	int choice;
	if(plist->head==NULL){
		plist->head=p;
	}
	else{
		Tree *temp=plist->head;
		while(temp!=NULL){
		printf("输入你的选择，1-左儿子，2-右儿子\n");
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
