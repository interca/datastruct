#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree *left;
	struct tree *right;
	int value;
}Node;
typedef struct Root{
	Node *head;
}Tree;
typedef struct node{
	struct tree*jie;
	struct node*next;
}zhan;
typedef struct list{
	zhan*head;
}List;
int main(){
	int number;
	Tree tree;
	tree.head=NULL;
	void push(List*plist,zhan**p);
	Node* pop(List*plist);
	void add(Tree*plist,int number);
	void show(Node*head);
	int n;
	printf("输入个数：\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("输入数字到树中：\n");
		scanf("%d",&number);
		add(&tree,number);
	}
	 show(tree.head);
	return 0;
} 
void push(List*plist,Node**p){
	zhan*q=(zhan*)malloc(sizeof(zhan));
	q->next=NULL;
	q->jie=*p;
	if(plist->head==NULL){
		plist->head=q;
	}
	else{
		q->next=plist->head;
		plist->head=q;
	}
}
Node* pop(List*plist){
	zhan*q;
	q=plist->head;
	plist->head=plist->head->next;
	return q->jie;
}
void show(Node *head){
     Node*head1=head;
     List list;
     list.head=NULL;
     while(head1!=0||list.head!=NULL){
     	while(head1){
     		push(&list,&head1);
     		head1=head1->left;
     	}
     	if(list.head!=NULL){
     		head1=pop(&list);
     		printf("%d  ",head1->value);
     		head1=head1->right;
     	}
     }
}
void add(Tree*plist,int number){
	int choice;
	Node*p=(Node*)malloc(sizeof(Node));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	if(plist->head==NULL){//判断头是不是空 
		plist->head=p;
	}
	else{
		Node*temp=plist->head;
		while(temp!=NULL){
			printf("输入你的选择：1-左儿子，2-右儿子\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:if(temp->left==NULL){
					temp->left=p;
					temp=NULL;
				}else temp=temp->left;break;
				case 2:if(temp->right==NULL){
					temp->right=p;
					temp=NULL;
				}else temp=temp->right;break;
			}
		}
	}
}


