#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node*next;
	int value;
}Node;
typedef struct list{
	Node*head;
	Node*last;
}List;
typedef struct t{
	int a[100][100];
	int flag[100];
}T1;
T1 T;
int n;
void creat();
int wfs(int k);
void push(List*plist,int k);
int pop(List*plist);
int main(){
	int i,m;
	int c1,c2;
	
	printf("输入结点N和边数M：\n");
	scanf("%d%d",&n,&m);
	creat();
	for(i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		T.a[c1][c2]=1;
	}
	int count=wfs(0);
//	printf("%d",count);
	printf("百分比是%f",1.0*count/n);
	return 0;
}
int wfs(int k){
	T.flag[k]=1;
	List list;
	list.head=list.last=NULL;
	int last=k,tail,count=1,leve=0;
	push(&list,k);
	while(list.head){
		k=pop(&list);
		for(int i=0;i<n;i++){
			if(T.flag[i]==0&&T.a[k][i]==1){
				T.flag[i]=1;
				push(&list,i);count++;
				tail=i;
				if(k==last){
				leve++;last=tail;
			} 
			}
		}
       printf("leve=%d\n",leve);
		if(leve==3)break;
	}
	return count;
}
int pop(List*plist){
	Node*p=plist->head;
	plist->head=plist->head->next;
	return p->value;
}
void push(List*plist,int k){
	Node*p=(Node*)malloc(sizeof(Node));
	p->value=k;
	p->next=NULL;
	if(plist->head==NULL){
		plist->head=plist->last=p;
	}
	else {
		plist->last->next=p;
		plist->last=p;
	}
}
void creat(){
	int i,j;
	for(i=0;i<n;i++){
		T.flag[i]=0;
		for(j=0;j<n;j++){
			T.a[i][j]=-1;
		}
	}
}
