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
int main(){
	int number;
	Tree tree;
	tree.head=NULL;
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
void show(Node *head){
	if(head!=NULL){
		show(head->left);
		printf("%d ", head->value);
		show(head->right);
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

