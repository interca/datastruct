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
void add(Root*plist,int number);
void print(Tree*head); 
int main(){
	int number,n;
	Root root;
	root.head=NULL;
	printf("输入数字N：\n");
	scanf("%d",&n);
	printf("输入数字：\n");
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		add(&root,number);
	}
	print(root.head);
	return 0;
} 
void  print(Tree*head){
	if(head){
		print(head->left);
		printf("%d ",head->value);
		print(head->right);
	}
}
void add(Root*plist,int number){
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
				temp->right=p;break;
			}
				else {
					temp=temp->right;
				}
			}
			else {
				if(temp->left==NULL){
					temp->left=p;break;
				}
				else {
					temp=temp->left;
				}
			}
		}
	}
}
