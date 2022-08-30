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
void add(Root*plist,int number);  //������ 
	void print(Tree*head);            //��ӡ�� 
	void push(list*plist,Tree**p);    //�����ѹ���ջ 
	 Tree*pop(List*plist);             //����㷵��(��������� 
	 Tree*ret(Tree*head,int number);  //���Һ���  
	 Tree*findmax(Tree*head);  //Ѱ�����Ԫ�� 
	 Tree *charu(Tree*head,int number);  //������ 
	 Tree *delect(Tree*head,int number);
int main(){
	int n,dnumber,number;
	int choice;
	 
	 Root root;
	 root.head=NULL;
	 printf("����N��\n");
	 scanf("%d",&n);
	 for(int i=0;i<n;i++){
	 	printf("�������֣�\n");
	 	scanf("%d",&number);
	 	add(&root,number);
	 }
	 while(1){
	 	printf("�������ѡ��1-�����㣬2-ɾ����㣬3-�������4-��������5-�������Ԫ��\n");
	 	scanf("%d",&choice);
	 	switch(choice){
	 		case 1:printf("��������ֵ:\n");scanf("%d",&number);printf("�������ǣ�%d\n",charu(root.head,number)->value);break;
	 		case 2:printf("����ɾ����ֵ��\n");scanf("%d",&number);delect(root.head,number);break;
	 		case 3:print(root.head);break;
	 		case 4:printf("������ҵ����֣�");scanf("%d",&number);printf("���ؽ����%d\n",(ret(root.head,number))->value);break;
	 		case 5:printf("���ֵ��%d\n",findmax(root.head)->value);break;
	 	}
	 }
	 return 0;
}
Tree*delect(Tree*head,int number){
	Tree*temp;
	printf("1");
	if(head==NULL){
		printf("û���ҵ�\n");
	}
	else if(number<head->value){               //�������ݹ� 
		head->left=delect(head->left,number);
	}
	else if(number>head->value){             //�������ݹ� 
		head->right=delect(head->right,number);
	}
	else    //�ҵ���� 
		if(head->left&&head->right){        //����˽������������ 
			temp=findmax(head->left);
			head->value=temp->value;
			head->left=delect(head->left,head->value);
		}
		else{         //����һ������һ����û�� 
			temp=head;
			if(head->left==NULL){     //��ɾ�����û������� 
				head=head->right;
			}
			else if(head->right==NULL){
				head=head->left;
			}
			free(temp);
		}
	return head;
}
Tree*charu(Tree*head,int number){            //������ 
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
Tree*findmax(Tree*head){  //Ѱ�����ֵ
	if(head->right==NULL){
		return(head);
	} 
	else return findmax(head->right);
}
Tree *ret(Tree*head,int number){   //���ҷ��ؽ�� 
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
void push(List*plist,Tree**p){           //�ѽ��ѹ���ջ 
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
Tree*pop(List*plist){     //�ѽ��POP���� 
	Node*temp;
	temp=plist->head;
	plist->head=plist->head->next;
	return temp->jie;
}
void print(Tree*head){        //��ӡ�� 
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
void add(Root*plist,int number){         //������ 
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
			printf("����ѡ��1-��������2-��������\n");
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
