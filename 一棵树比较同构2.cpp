#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	int value;
	struct tree*left;
	struct tree*right;
	int flag;
}Tree;
typedef struct root{
	Tree*head;
}Root;
void insert(Root*plist,int number);
int judge(Tree*head,int n);
void re(Tree*head);
int check(Tree*head,int number);
int main(){
	int n,m;
	int i;
	Root root;
	root.head=NULL;
	int number;
	int imprise;
	
	printf("输入结点n和数据数量M：\n");
	scanf("%d%d",&n,&m);
	printf("构造一棵树:\n");
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root,number);
	}
	for(i=0;i<m;i++) {
		 imprise=judge(root.head,n);
		 if(imprise==1)printf("同构\n");
		 else printf("不同构\n");
		 re(root.head);
	}
	return 0;
}
int check(Tree*head,int number){
	if(head==NULL)return 0;
	if(head->flag==1){
		if(number>head->value)return check(head->right,number);
		else if(number<head->value)return check(head->left,number);
		else return 0;
	}
	else {
		if(number==head->value){
			head->flag=1;
			return 1;
		}
		else return 0;
	}
}  
int judge(Tree*head,int n){
	int number;
	int flag=1;
	scanf("%d",&number);
	if(number!=head->value) {
		flag=0;
	}
	else head->flag=1;
	for(int i=0;i<n-1;i++){
		scanf("%d",&number);
		if(check(head,number)==0)flag=0;
	}
	if(flag==1)return 1;
	else return 0;
}
void re(Tree*head){
	if(head!=NULL){
		re(head->left);
		head->flag=0;
		re(head->right);
	}
}
void insert(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->value=number;
	p->flag=0;
	p->left=p->right=NULL;
	if(plist->head==NULL){
		plist->head=p;
	}
	else{
		Tree*temp=plist->head;
		while(1){
			if(number>temp->value){
				if(temp->right==NULL){
					temp->right=p;break;
				}
				else temp=temp->right;
			}
			else{
				if(temp->left==NULL){
					temp->left=p;break;
				}
				else temp=temp->left;
			}
		}
	}
}
