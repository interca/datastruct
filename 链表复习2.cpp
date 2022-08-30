#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node*next;
	int value;
}Node;
int main(){
   int number;
   int n;
   Node*head=NULL;
   void print(Node*head);
   void change(Node*head);
    void add(Node*head,int number);
    Node*temp=(Node*)malloc(sizeof(Node));
    temp->value=1;
    temp->next=NULL;
    head=temp;
    printf(" ‰»ÎN:\n");
    scanf("%d",&n);
    printf(" ‰»Î¡¥±Ì£∫\n");
    for(int i=0;i<n-1;i++){
    	scanf("%d",&number);
    	add(head,number);
    }
    print(head);
    printf("\n");
    change(head);
    print(head);
    return 0;
} 
void add(Node*head,int number){
	Node*p=(Node*)malloc(sizeof(Node));
	p->next=NULL;
	p->value=number;
	for(;head->next!=NULL;head=head->next){
		
	}
	head->next=p;
}
void print(Node*head){
	for(;head;head=head->next){
		printf("%d ",head->value);
	}
}
void change(Node*head){
	head->value=10;
}
