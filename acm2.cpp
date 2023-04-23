#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//定义树
typedef struct node{
	struct node *left;
	struct node*right;
	int value;
}Tree;

//定义堆栈结点
typedef struct Stacknode{
	Tree*value;
	struct Stacknode* next;
}stacknode;

//定义队列结点
typedef struct Queuenode{
	Tree*value;
    struct Queuenode * next;
}queuenode;

//定义堆栈头
typedef struct Stack{
	stacknode*head;
}stack;

//定义队列头
typedef struct Queue{
	queuenode*head;
	queuenode*last;
}queue;

//插入队列
void  pushqueue(queue*q,Tree* tree){
	queuenode*node = (queuenode*)malloc(sizeof(queuenode));
	node->value = tree;
	node->next = NULL;
    if(q->head == NULL){
		q->head  = q->last = node;
	}else {
		q->last->next = node;
		q->last = node;
	}
}
//抛出
Tree* popqueue(queue*q){
	 Tree * node  = q->head->value;
	 q->head = q->head->next;
	 return node;
}

//层序遍历
void  printlayer (Tree*head){
	queue qe;
	qe.head = NULL;
	qe.last = NULL;
	pushqueue(&qe,head);
	while(qe.head!=NULL){
		head = popqueue(&qe);
		printf("%d ",head->value);
		if(head ->left !=NULL)pushqueue(&qe,head->left);
		if(head ->right != NULL)pushqueue(&qe,head->right);
	}
	printf("\n");
}
//压入堆栈
void pushstack(stack*s,Tree*tree){
    stacknode * node = (stacknode*)malloc(sizeof(stacknode));
	node->value= tree;
	node->next = s->head;
	s->head = node;
}
//抛出
Tree*popstack(stack*s){
  Tree*node  = s->head->value;
   s ->head = s->head->next;
   return node;
}

//堆栈先序遍历
void printbystack(Tree*head){
	stack st;
	st.head =NULL;
	while(st.head !=NULL || head != NULL){
		while(head !=NULL){
			pushstack(&st,head);
			printf("%d ",head->value);
			head = head->left;
		}
		if(st.head!=NULL){
			head = popstack(&st);
			head= head->right;
		}
	}
	printf("\n");
}

//构建树
Tree * dfs(int n,int i,int *a){
	if(i >= n || a[i] == 0)return NULL;
	Tree*node = (Tree*)malloc(sizeof(Tree));
	node->left = dfs(n,i*2+1,a);
	node->right = dfs(n,i*2+2,a);
	node->value = a[i];
	return node;
}
//中序
void printmid(Tree*head){
	if(head == NULL)return;
	printmid(head->left);
	printf("%d ",head->value);
	printmid(head->right);
}
//后序
void printback(Tree*head){
	if(head == NULL)return;
	printback(head->left);
	printback(head->right);
	printf("%d ",head->value);
}

//查找数字
Tree*find(Tree*head,int x){
	if(head == NULL)return NULL;
	if(head ->value == x)return head;
	Tree*l = find(head->left,x);
	Tree*r = find(head->right,x);
	if( l != NULL && l->value == x)return l;
	if( r != NULL && r->value == x)return r;
	return NULL;
}

//打印叶子
void printleaf(Tree*head){
   if(head ==NULL)return ;
   if(head->left==NULL&&head->right ==NULL){
	   printf("%d ",head->value);
   }
   printleaf(head->left);
   printleaf(head->right);
}

//打印非叶子
void printnoleaf(Tree*head){
   if(head ==NULL)return ;
   if(!(head->left==NULL&&head->right ==NULL)){
	   printf("%d ",head->value);
   }
   printnoleaf(head->left);
   printnoleaf(head->right);
}

//深度
int deep(Tree * head){
    if(head ==NULL)return 0;
	int left   = deep(head->left);
	int right = deep(head->right);
	if(left > right)return left + 1;
	return right + 1;
}

//判断完全二叉树
int judge(Tree * head){
	Tree*node = head;
	queue qe;
	qe.head = NULL;
	qe.last = NULL;
	pushqueue(&qe,head);
	int flag = 0;
	while(qe.head!=NULL){
		head = popqueue(&qe);
		if(head == NULL){
			flag = 1;
			continue;
		}
		else {
			if(flag == 1)return 0; 
           pushqueue(&qe,head->left);
		   pushqueue(&qe,head->right);
		}
	}
  return true;
}
void printfreverse(Tree * head,int n){
	if(head == NULL)return;
	printfreverse(head->right,n + 4);
	for(int  i = 0 ; i < n  ;  i ++)printf(" ");
	printf("----");
	printf("%d",head->value);
	printf("\n");
	printfreverse(head->left,n + 4);
}
int main(){
  int n;
  printf("输入数的数量\n"); 
  scanf("%d",&n);
   //头指针
  Tree *head;
  printf("建立树,输入%d个数\n",n);
  int a[n];
  for(int i = 0 ;i  < n ; i ++){
       scanf("%d",&a[i]);
  }
  //构造树
  Tree*node = (Tree*)malloc(sizeof(Tree));
  node ->value = a[0];
  head = node;
  head->left  = dfs(n,1,a);
  head->right = dfs(n,2,a); 
  while(1){
	  printf("输入选择:1-查找数,2-打印翻转 3-非递归打印 4-中序  5 -后序 6- 层序  7-输出叶子  8 输出非叶子  9-树的深度  10 -完全二叉树\n");
	  int choice;
	  scanf("%d",&choice);
	  Tree * c;
	  switch(choice){
		  case 1:
		    printf("输入要找的数\n");
			int x;
			scanf("%d",&x);
		    c = find(head,x);
			if(c == NULL)printf("没有找的\n");
			else printf("这个数是%d\n",c->value);
			break;
		  case 2:
		     printfreverse(head,0);
		    break;
		  case 3:	
		     printbystack(head); 
			 break;
		  case 4:
		     printmid(head);
			 printf("\n");
			 break;
		  case 5:
		     printback(head);
			 printf("\n");
			 break;
		  case 6:
		    printlayer(head);
			break;
		  case 7:
		    printleaf(head);
			printf("\n");
			break;
		  case 8:
		    printnoleaf(head);
			printf("\n");
		    break;	
		  case 9:
		   printf("深度是%d\n",deep(head));
		   break;
		  case 10:
		    if(judge(head) ==1){
				printf("是完全二叉树\n");
			}else {
				printf("不是完全二叉树\n");
			}			 	 	 	
	  }
    }
}