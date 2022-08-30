#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree*left;
	struct tree*right;
	int value;
	int flag;
}Tree;
typedef struct root{
	Tree*head;
}Root;
void add(Root*plist,int number);
int judge(Tree*head,int n);
int  check(Tree*head,int number);
int main(){
	int n,l;
	Root root;
	int i;
	int number;
	root.head=NULL;
	printf("输入结点数和序列数：\n");
	scanf("%d%d",&n,&l);
	printf("输入树：\n");
	for(i=0;i<n;i++){
		scanf("%d",&number);
		add(&root,number);
	}
	printf("输入序列：\n");
	for(i=0;i<l;i++){
		if(judge(root.head,n))printf("同构\n");
		else printf("不同构\n");
	}
	return 0;
}
int check(Tree*head,int number){
	if(head==NULL)return 0;
	else {
		if(head->flag==1){
			if(number>head->value)return check(head->right,number);
			else if(number<head->value)return check(head->left,number);
			else return 0;
		}
		else {
			if(number==head->value){
				head->flag=1;return 1;
			}
			else return 0;
		}
	}
}
int judge(Tree*head,int n){
	int i;
	int number;
	int flag=0;//代表全一样；
	scanf("%d",&number);
	if(head->value!=number)flag=1;
	head->flag=1;
	for(i=1;i<n;i++){
		scanf("%d",&number);
		if(check(head,number)==0)flag=1;
	} 
	if(flag==0)return 1;
	else return 0;
}
void add(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->flag=0;
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
