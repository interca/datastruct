#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree *left;
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
void add(Root*plist,int number);  //生成树 
	void print(Tree*head);            //打印树 
	void push(list*plist,Tree**p);    //将结点压入堆栈 
	 Tree*pop(List*plist);             //将结点返回(中序遍历） 
	 Tree*ret(Tree*head,int number);  //查找函数  
	 Tree*findmax(Tree*head);  //寻找最大元素 
	 Tree *charu(Tree*head,int number);  //插入结点 
	 Tree *delect(Tree*head,int number);
int main(){
	int n,dnumber,number;
	int choice;
	 
	 Root root;
	 root.head=NULL;
	 printf("输入N：\n");
	 scanf("%d",&n);
	 for(int i=0;i<n;i++){
	 	printf("输入数字：\n");
	 	scanf("%d",&number);
	 	add(&root,number);
	 }
	 while(1){
	 	printf("输入你的选择：1-插入结点，2-删除结点，3-输出树，4-查找树，5-查找最大元素\n");
	 	scanf("%d",&choice);
	 	switch(choice){
	 		case 1:printf("输入结点数值:\n");scanf("%d",&number);printf("插入结点是：%d\n",charu(root.head,number)->value);break;
	 		case 2:printf("输入删除数值：\n");scanf("%d",&number);delect(root.head,number);break;
	 		case 3:print(root.head);break;
	 		case 4:printf("输入查找的数字：");scanf("%d",&number);printf("返回结果是%d\n",(ret(root.head,number))->value);break;
	 		case 5:printf("最大值是%d\n",findmax(root.head)->value);break;
	 	}
	 }
	 return 0;
}
Tree*delect(Tree*head,int number){
	Tree*temp;
	printf("1");
	if(head==NULL){
		printf("没有找到\n");
	}
	else if(number<head->value){               //左子树递归 
		head->left=delect(head->left,number);
	}
	else if(number>head->value){             //右子树递归 
		head->right=delect(head->right,number);
	}
	else    //找到结点 
		if(head->left&&head->right){        //如果此结点右两个子树 
			temp=findmax(head->left);
			head->value=temp->value;
			head->left=delect(head->left,head->value);
		}
		else{         //否则一个或者一个都没有 
			temp=head;
			if(head->left==NULL){     //被删除结点没有左儿子 
				head=head->right;
			}
			else if(head->right==NULL){
				head=head->left;
			}
			free(temp);
		}
	return head;
}
Tree*charu(Tree*head,int number){            //结点插入 
	if(head==NULL){
		head=(Tree*)malloc(sizeof(Tree));
		head->left=NULL;
		head->right=NULL;
		head->value=number;
	}
	else {
		if(number<head->value)head->left=charu(head->left,number);
		else if(number>head->value)head->right=charu(head->right,number);
	}
	return head;
}
Tree*findmax(Tree*head){  //寻找最大值
	if(head->right==NULL){
		return(head);
	} 
	else return findmax(head->right);
}
Tree *ret(Tree*head,int number){   //查找返回结点 
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
void push(List*plist,Tree**p){           //把结点压入堆栈 
	Node*q=(Node*)malloc(sizeof(Node));
	q->next=NULL;
	q->jie=*p;
	if(plist->head==NULL){
		plist->head=q;
	}
	else {
		q->next=plist->head;
		plist->head=q;
	}
}
Tree*pop(List*plist){     //把结点POP出来 
	Node*temp;
	temp=plist->head;
	plist->head=plist->head->next;
	return temp->jie;
}
void print(Tree*head){        //打印树 
	List list;
	list.head=NULL;
	while(list.head||head){
		while(head){
		push(&list,&head);
		head=head->left;
	  }
	    if(list.head){
	    	head=pop(&list);
	         printf("%d ",head->value);
	         head=head->right;
	    }
	}
	printf("\n");
}
void add(Root*plist,int number){         //生成树 
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->value=number;
	p->left=NULL;
	p->right=NULL;
	int choice;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		Tree*temp=plist->head;
		while(temp){
			printf("输入选择：1-左子树，2-右子树，\n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					if(temp->left==NULL){
						temp->left=p;temp=NULL;
					}
					else {
						temp=temp->left;
					}break;
				case 2:
				     if(temp->right==NULL){
				     	temp->right=p;temp=NULL;	
				     }
					 else {
					 	temp=temp->right;
					 }break;	
			}
		}
	}
	
}
