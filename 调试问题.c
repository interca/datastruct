#include<stdio.h>
#include<stdlib.h>

typedef struct worker{
	int wages;
	char name[10];
	struct worker *next;
}Node;

typedef struct list{
	Node *head;
	Node *last;
}List;

int main()
{
	List k;
	k.head=k.last=NULL;
	int avg=0,n=0;

	void income(List *plist);
	void count_list(Node *head,int *pavg,int *pn);

	printf("input\n");
	income(&k);
	count_list(k.head,&avg,&n);
	printf("answer:%d %d\n",n,avg);
	return 0;
}

void income(List *plist)
{
	int i=1;
	do
	 {
	  Node *p=(Node *)malloc(sizeof(Node));
	  
	  plist->head=NULL;
	  scanf("%s%d",p->name ,&p->wages );
		  if(i==1)
		   plist->head=plist->last=p;
		  else
		  {
			  plist->last->next =p;
			  plist->last=p;
		  }
	  
	  i++;

	 }while(p->wages!=0);
}

void count_list(Node *head,int *pavg,int *pn)
{
	int i=0,sum=0;
	for(p=plist.head;p;p=p->next)
	{
		sum+=p->wages;
		i++;
	}
	*pavg=sum/i;
	for(p=plist.head;p;p=p->next)
	{
		if(p->wages>*pavg)
			*pn++;
	}
}