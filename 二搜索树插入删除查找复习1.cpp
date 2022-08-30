#include<stdio.h>
# include<stdlib.h>
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
void add(Root*plist,int number);//生成树
void print(Tree*head);   //打印树
void push(List*plist,Tree*p);  //将结点压入堆栈
Tree*pop(List*plist);  //将结点压出堆栈
Tree*findjie(Tree*head,int number); //查找结点 
Tree*findmax(Tree*head);  //找最大值 
Tree*findmin(Tree*head);   //找最小值 
Tree*delect(Tree*head,int number) ; //删除结点 
Tree*addjie(Tree*head ,int number); //插入结点 
 int main(){
 	int number,n;
 	Root root;
 	int i;
 	int choice;
 	root.head=NULL;
 	
 	printf("输入N：\n");
 	scanf("%d",&n);
 	for(i=0;i<n;i++){
 		printf("输入数字：\n");
 		scanf("%d",&number);
 		add(&root,number);
 	}
 	while(1){
 		printf("输入选择：1-输出树，2-插入结点，3-删除结点，4-查找结点，5-返回最大值，6-返回最小值\n");
 		scanf("%d",&choice);
 		switch(choice){
 			case 1:print(root.head);printf("\n");break;
 			case 2:printf("输入插入的结点数值：\n");scanf("%d",&number);addjie(root.head,number);break;
 			case 3:printf("输入删除数字：\n");scanf("%d",&number);delect(root.head,number);break;
 			case 4:printf("输入查找值：\n");scanf("%d",&number);printf("结点是：%d\n",findjie(root.head,number)->value);break;
 			case 5:printf("最大值是%d\n",findmax(root.head)->value);break;
 			case 6:printf("最小值是%d\n",findmin(root.head)->value);break;
 		}
 	}
 	return 0;
 } 
 Tree*delect(Tree*head,int number){
 	Tree*temp;
 	if(head==NULL){
 		printf("没有找到\n");
 	}
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
 			else{
 				temp=head;
 				if(head->right==NULL){
 				head=head->left;
 				}
 				else if(head->left==NULL){
 					head=head->right;
 				}
 				free(temp);
 			}
 		}
 	}
 	return head;
 }
 Tree* addjie(Tree*head,int number){
 	if(head==NULL){
 		head=(Tree*)malloc(sizeof(Tree));
 		head->value=number;
 		head->right=NULL;
 		head->left=NULL;
 	}
 	else {
 		if(number>head->value){
 			head->right=addjie(head->right,number);
 		}
 		else if(number<head->value){
 			head->left=addjie(head->left,number);
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
 Tree*findjie(Tree*head,int number){ //查找结点
 while(head){
 	if(number>head->value){
 		head=head->right;
 	}
 	else if(number<head->value){
 		head=head->left;
 	}
 	else  {
 		return head;
 	}
 }
 printf("没有找到\n");
}
 Tree *pop(List*plist){ //压入堆栈
      Node*temp=plist->head;
	  plist->head=plist->head->next;
	  return temp->jie;	
 }
 void push(List*plist,Tree*p){  //抛出堆栈
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
 void print(Tree*head){    //打印树
 	List list;
 	list.head=NULL;
 	while(head||list.head){
 		while(head){
 			push(&list,head);
 			head=head->left;
 		}
 		head=pop(&list);
 		printf("%d ",head->value);
 		head=head->right;
 	}
 }
 void add(Root*plist,int number){    //生成树
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
 			printf("输入你的选择：1-左子树，2-右子树\n");
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
