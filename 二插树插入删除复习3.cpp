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
	struct node *next;
	Tree*jie;
}Node;
typedef struct list{
	Node*head;
}List; 
void add(root*plist,int number);//生成树
void print(Tree*head);//打印树
void push(List*plist,Tree*p);//压入堆栈
Tree*pop(List*plist);//抛出堆栈
Tree*find(Tree*head,int number);//查找结点 
Tree*findmax(Tree*head);
Tree*findmin(Tree*head);
Tree*addroot(Tree*head,int number);
Tree*del(Tree*head,int number);
 int main(){
 	int choice;
 	int number,n;
 	Root root;
 	root.head=NULL;
 	printf("输入n:\n");
 	scanf("%d",&n);
 	printf("输入树：\n");
 	for(int i=0;i<n;i++){
 		printf("输入数字：\n");
 		scanf("%d",&number);
 		add(&root,number);
 	}
 	while(1){
 		printf("输入你的选择：1-输出树，2-查找结点，3-输出最大值，4-输出最小值，5-插入结点，6-删除结点\n");
 		scanf("%d",&choice);
 		switch(choice){
 			case 1:print(root.head);printf("\n");break;
 			case 2:printf("输入查找的值：\n");scanf("%d",&number);printf("结点是%d \n",find(root.head,number)->value);break;
 			case 3:printf("最大值是%d\n",findmax(root.head)->value);break;
 			case 4:printf("最小值是%d\n",findmin(root.head)->value);break;
			case 5:printf("输入插入的值：\n");scanf("%d",&number);addroot(root.head,number);break;
			case 6 :printf("输入要删除的结点：\n");scanf("%d",&number);del(root.head,number);break; 
 		}
 	}
 	return 0;
 }
 Tree*del(Tree*head,int number){
 	Tree*temp;
 	if(head==NULL){
 		printf("没有找到\n");
 	}
 	else {
 		if(number>head->value){
 			head->right=del(head->right,number);
 		}
 		else if(number<head->value){
 			head->left=del(head->left,number);
 		}
 		else {
 			if(head->right&&head->left){
 			temp=findmax(head->left);
 			head->value=temp->value;
 			head->left=del(head->left,temp->value);
 			} 
 			else {
 				temp=head;
 				if(head->left==NULL){
 					head=head->right;
 					free(temp);
 				}
 				else{
 					head=head->left;
 					free(temp);
 				}
 			}
 		}
 	}
 	return head;
 }
 Tree*addroot(Tree*head,int number){  //插入结点 
 	if(head==NULL){
 		head=(Tree*)malloc(sizeof(Tree));
 		head->left=NULL;
 		head->right=NULL;
 		head->value=number;
 	}
 	else {
	 if(number<head->value) {
	 	head->left=addroot(head->left,number);
	 }
	 else {
	 	head->right=addroot(head->right,number);
	 }
  }
  return head;
 } 
 Tree*findmax(Tree*head){//查找最大值 
 	while(head->right){
 		head=head->right;
 	}
 	return head;
 }
 Tree*findmin(Tree*head){//查找最小值 
 	while(head->left){
 		head=head->left;
 	}
 	return head;
 }
 Tree*find(Tree*head,int number){//查找结点 
 	while(head){
 		if(number>head->value){
 			head=head->right;
 		}
 		else if(number<head->value){
 			head=head->left;
 		}
 		else return head;
 	} 
 }
 Tree*pop(List*plist){//抛出堆栈
 	Node*q=plist->head;
 	plist->head=plist->head->next;
 	return q->jie;
 }
 void push(List*plist,Tree*p){//压入堆栈
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
 void print(Tree*head){ //打印树 
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
 void add(Root*plist,int number){  //生成树 
 	Tree*p=(Tree*)malloc(sizeof(Tree));
 	p->left=NULL;
 	p->right=NULL;
 	p->value=number;
 	int choice;
 	if(plist->head==NULL){
 		plist->head=p;
 	}
 	else{
 		Tree*temp=plist->head;
 		while(temp){
 			printf("输入你的选择：1-左子树，2-右子树:\n");
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
