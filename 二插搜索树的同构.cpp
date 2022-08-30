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
int comp(Tree*head1,Tree*head2);
int main(){
	int number,n;
	Root root;
	root.head=NULL;
	Root root1;
	root1.head=NULL;
	printf("输入数字N：\n");
	scanf("%d",&n);
	printf("输入数字：\n");
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		add(&root,number);
	}
	printf("输入数字N：\n");
	scanf("%d",&n);
	printf("输入第二课树：\n");
	for(int i=0;i<n;i++){
		scanf("%d",&number);
		add(&root1,number);
	}
	int imprise=comp(root.head,root1.head);
	if(imprise==1)printf("两颗搜索树同构\n");
	else printf("不同构\n");
	return 0;
} 
int comp(Tree*head1,Tree*head2){
	int imprise=1;
	if(head1==NULL&&head2||head1&&head2==NULL)return 0;
	else if(head1&&head2){
	imprise=comp(head1->left,head2->left);
	if(imprise==0)return imprise;
	if(head1->value!=head2->value){
		imprise=0;return imprise;
	}
	imprise=comp(head1->right,head2->right);
	if(imprise==0)return imprise;
    }
    return imprise;
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
