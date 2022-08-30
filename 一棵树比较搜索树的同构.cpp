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
int check(Tree*head,int v);
int judge(Root*plist,int n);
void add(Root*plist,int number);

int main(){
	int n,l;
	int number;
	int i;
	Root root;
	root.head=NULL;
	printf("输入N和L：\n");
	scanf("%d%d",&n,&l);
	printf("构造树：\n");
	for(i=0;i<n;i++){
		scanf("%d",&number);
		add(&root,number);
	} 
	printf("输入序列\n");
	for(i=0;i<l;i++){
		if(judge(&root,n))printf("两棵树同构\n");
		else printf("两棵树不同构\n");
	}
	return 0;
}
int check(Tree*head,int v){
	if(head==NULL)return 0;
	if(head->flag==1){
		if(v>head->value)return check(head->right,v);
		else if(v<head->value)return check(head->left,v);
		else return 0;
	}
	else {
		if(v==head->value){
			head->flag=1;
			return 1;
		}
		else return 0;
	}
}
int judge(Root*plist,int n){
	int number;
	int flag=0 ;//0代表一致
	scanf("%d",&number);
	if(plist->head->value!=number)flag=1;
	else plist->head->flag=1;
	for(int i=1;i<n;i++){
		scanf("%d",&number);
		if(check(plist->head,number)==0)flag=1;
	} 
	if(flag==0)return 1;
	else return 0;
}
void add(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->left=NULL;
	p->right=NULL;
	p->value=number;
	p->flag=0;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		Tree*temp=plist->head;
		while(temp){
			if(number<temp->value){
				if(temp->left==NULL){
					temp->left=p;break;
				}
				else temp=temp->left;
			}
			if(number>temp->value){
				if(temp->right==NULL){
					temp->right=p;break;
				}
			   else temp=temp->right;	
			} 
		}
	}
}
