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
}List;
void insert(Root*plist,int number);
Tree*findmax(Tree*head);
Tree*findmin(Tree*head);
Tree*delect(Tree*head,int number);
void print(Tree*head);
void push(List*plist,Tree*p);
Tree*pop(List*plist);
int main(){
	int n,i,number;
	int choice;
	Root root;
	root.head=NULL;
	printf("输入N：\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root,number);
	}
	while(1){
		printf("输入选择：1-插入，2-删除，3-最大值，4-最小值，5-打印：\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("输入插入的数字：\n");scanf("%d",&number);insert(&root,number);break;
			case 2:printf("输入删除的数：\n");scanf("%d",&number);delect(root.head,number);break;
			case 3:printf("最大值是；%d\n",findmax(root.head)->value);break;
			case 4:printf("最小值是：%d\n",findmin(root.head)->value);break;
			case 5:print(root.head);printf("\n");break;
		}
	}
	return 0;
} 
Tree*delect(Tree*head,int number){
	Tree*temp;
	if(head==NULL)printf("没有找到\n");
	else{
		if(number>head->value){
			head->right=delect(head->right,number);
		}
		else if(number<head->value){
			head->left=delect(head->left,number);
		}
		else{
			if(head->right&&head->left){
				temp=findmax(head->left);
				head->value=temp->value;
				head->left=delect(head->left,temp->value);
			}
			else{
				temp=head;
				if(head->right==NULL){
					head=head->left;
				}
				else{
					head=head->right;
				}
				free(temp);
			}
		}
	}
	return head;
}
Tree*findmin(Tree*head){
	while(head->left){
		head=head->left;
	}
	return head;
}
Tree*findmax(Tree*head){
	while(head->right){
		head=head->right;
	}
	return head;
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
		plist->head=temp;
	}
	else{
		temp->next=plist->head;
		plist->head=temp;
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
	p->value=number;
	p->left=NULL;
	p->right=NULL;
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
					else{
						temp=temp->right;
					}
				
			}
			else if(number<temp->value) {
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
