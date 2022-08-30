#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
	struct tree*right;
	struct tree*left;
	int value;
}Tree;
typedef struct root{
	Tree*head;
}Root;
void insert(Root*plist,int number);
int com(Tree*head1,Tree*head2);
int main(){
	int n,number,i;
	Root root1;
	Root root2;
	root1.head=NULL;
	root2.head=NULL;
	
	printf("输入\n");
	scanf("%d",&n);
	printf("输入第一棵树：\n");
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root1,number);
	}
	printf("输入第二棵树：\n");
	for(i=0;i<n;i++){
		scanf("%d",&number);
		insert(&root2,number);
	}
	int imprise=com(root1.head,root2.head);
	if(imprise==1)printf("同构\n");
	else printf("不同构\n");
	return 0;
} 
int com(Tree*head1,Tree*head2){
	if(head1==NULL&&head2==NULL)return 1;
	if((head1==NULL&&head2!=NULL)||head1!=NULL&&head2==NULL)return 0;
	if(head1->value!=head2->value)return 0;
	if(head1->left&&head2->left&&head1->right==NULL&&head2->right==NULL)return com(head1->left,head2->left);
	if(head1->right&&head2->right&&head1->left==NULL&&head2->left==NULL)return com(head1->right,head2->right);
	else return com(head1->left,head2->left)&&com(head1->right,head2->right); 
}
void insert(Root*plist,int number){
	Tree*p=(Tree*)malloc(sizeof(Tree));
	p->value=number;
	p->left=p->right=NULL;
	if(plist->head==NULL){
		plist->head=p;
	}
	else {
		Tree*temp=plist->head;
		while(1){
			if(number>temp->value){
				if(temp->right==NULL){
					temp->right=p;break;
				}
				else {
					temp=temp->right;
				}
			}
			else{
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
