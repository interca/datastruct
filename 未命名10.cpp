include<stdio.h>
# include<stdlib.h>
typedef struct tree{
	struct tree*left;
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
void add(Root*plist,int number);//������
void print(Tree*head);   //��ӡ��
void push(List*plist,Tree*p);  //�����ѹ���ջ
Tree*pop(List*plist);  //�����ѹ����ջ
Tree*findjie(Tree*head,int number); //���ҽ�� 
Tree*findmax(Tree*head);  //�����ֵ 
Tree*findmin(Tree*head);   //����Сֵ 
Tree*delect(Tree*head,int number) ; //ɾ����� 
Tree*addjie(Tree*head ,int number); //������ 
 int main(){
 	int number,n;
 	Root root;
 	int i;
 	int choice;
 	root.head=NULL;
 	
 	printf("����N��\n");
 	scanf("%d",&n);
 	for(i=0;i<n;i++){
 		printf("�������֣�\n");
 		scanf("%d",&number);
 		add(&root,number);
 	}
 	while(1){
 		printf("����ѡ��1-�������2-�����㣬3-ɾ����㣬4-���ҽ�㣬5-�������ֵ��6-������Сֵ\n");
 		scanf("%d",&choice);
 		switch(choice){
 			case 1:print(root.head);printf("\n");break;
 			case 2:printf("�������Ľ����ֵ��\n");scanf("%d",&number);addjie(root.head,number);break;
 			case 3:printf("����ɾ�����֣�\n");scanf("%d",&number);delect(root.head,number);break;
 			case 4:printf("�������ֵ��\n");scanf("%d",&number);printf("����ǣ�%d\n",findjie(root.head,number)->value);break;
 			case 5:printf("���ֵ��%d\n",findmax(root.head)->value);break;
 			case 6:printf("��Сֵ��%d\n",findmin(root.head)->value);break;
 		}
 	}
 	return 0;
 } 
 Tree*delect(Tree*head,int number){
 	Tree*temp;
 	if(head==NULL){
 		printf("û���ҵ�\n");
 	}
 	else {
 		if(number>head->value){
 			head->right=delect(head->right,number);
 		}
 		else if(number<head->value){
 			head->left=delect(head->left,number);
 		}
 		else {
 			if(head->left&&head->right){
 				temp=findmax(head->left);
 				head->value=temp->value;
 			    head->left=delect(head->left,head->value);
 			}
 			else{
 				temp=head;
 				if(head->right==NULL){
 				head=head->left;
 				}
 				else if(head->left==NULL){
 					head=head->right;
 				}
 				free(temp);
 			}
 		}
 	}
 	return head;
 }
 Tree* addjie(Tree*head,
