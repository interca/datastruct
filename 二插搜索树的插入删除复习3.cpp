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
void creat(Root*plist,int number);
void print(Tree*head);
void insert(Tree*head,int number);
Tree*delect(Tree*head,int number);
Tree*find(Tree*head,int number);
Tree*findmax(Tree*head);
Tree*findmin(Tree*head);
void push(List*plist,Tree*p);
Tree*pop(List*head);
int main(){
     int n,number;
	 Root root;
	 root.head=NULL;
	 printf("����N��\n");
	 scanf("%d",&n);
	 for(int i=0;i<n;i++){
	 	scanf("%d",&number);
	 	creat(&root,number);
	 }
	 int choice;
	 while(1){
	 	printf("�������ѡ��1-���룬2-ɾ����3-���ҽ�㣬4-�������ֵ��5-������Сֵ��6-��ӡ��\n");
	 	scanf("%d",&choice);
	 	switch(choice){
	 		case 1:printf("����������\n");scanf("%d",&number);insert(root.head,number);break;
	 		case 2:printf("����Ҫɾ�������֣�\n");scanf("%d",&number);delect(root.head,number);break;
	 		case 3:printf("������Ҷ���\n");scanf("%d",&number);printf("���ҵĽ����%d\n",find(root.head,number)->value);break;
	 		case 4:printf("���ֵ��%d\n",findmax(root.head)->value);break;
			 case 5:printf("��Сֵ��:%d\n",findmin(root.head)->value);break;
			 case 6:print(root.head);printf("\n");break; 
	 	}
	 }
	 return 0;   
} 
Tree*delect(Tree*head,int number){
	Tree*temp;
	if(head==NULL)printf("û���ҵ�\n");
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
			head->left=delect(head->left,head->value);
		}
		else {
			temp=head;
			if(head->left==NULL){
				head=head->right;
			}
			else if(head->right==NULL){
				head=head->left;
			}
			free(temp);
		}
	}
 }
	return head;
}
void insert(Tree*head,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	while(head){
	if(number>head->value){
		if(head->right==NULL){
			head->right=p;break;
		}
		else head=head->right;
	 }
	 else {
	 	if(head->left==NULL){
	 		head->left=p;break;
	 	}
	 	else head=head->left;
	 }
  }
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
Tree *find (Tree*head,int number){
	while(head){
	if(number>head->value){
		head=head->right;
	 }
	 else if(number<head->value) {
	 	head=head->left;
	 }
	 else return head;
   }
}
Tree*pop(List*plist){
	Node*temp=plist->head;
	plist->head=plist->head->next;
	return temp->jie;
}
void push(List*plist,Tree*p){
	Node*q=(Node*)malloc(sizeof(Node));
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
void creat(Root*plist,int number){
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
			if(number>temp->value){
				if(temp->right==NULL){
					temp->right=p;
					break;
				}
				else temp=temp->right;
			}
			else {
				if(temp->left==NULL){
					temp->left=p;break;
				}
				else temp=temp->left;
			}
		}
	}
}
