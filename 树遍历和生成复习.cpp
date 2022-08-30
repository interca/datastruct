#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree*left;
	struct tree*right;
	int value;
}Tree;
typedef struct root{
	Tree *head;
}Root;
int main(){
	int number;
	int n;
	void add(Root*plist,int number);
	void print(Tree *head);
	printf("输入结点数：\n");
	scanf("%d",&n);
	Root root;
	root.head=NULL;
	for(int i=1;i<=n;i++){
		printf("输入数字：\n");
		scanf("%d",&number);
		add(&root,number);
	}
	print(root.head);
}
void print(Tree *head){
	if(head!=NULL){
		print(head->left);
		printf("%d ",head->value);
		print(head->right);
	}
}
void add(Root*plist,int number){
	Tree *p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	int choice;
	if(plist->head==NULL){
		plist->head=p;
	}
	else{
		Tree *temp=plist->head;
		while(temp!=NULL){
		printf("输入你的选择，1-左二子，2-右儿子\n");
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

