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
	printf("���������\n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		printf("�������ֵ����У�\n");
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
	if(plist->head==NULL){//�ж�ͷ�ǲ��ǿ� 
		plist->head=p;
	}
	else{
		Node*temp=plist->head;
		while(temp!=NULL){
			printf("�������ѡ��1-����ӣ�2-�Ҷ���\n");
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

