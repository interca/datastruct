#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct yuan{
	char name[10];
	int salary;
	struct yuan *next;
};

struct yuan *delct(struct yuan *list,int x);

int main()
{
	int a=0,n=0;
	struct yuan *list,*list1,*p,*tail=NULL,*q;
	int salary=0;
	char name[10];

//	printf("请输入要删除的数据:");
//	scanf("%d",&a);
	printf("请输入员工的信息:");
	scanf("%s%d",name,&salary);

	list=NULL;
	while(salary!=0)
	{
		n++;
		p=(struct yuan *)malloc(sizeof(struct yuan));
		p->next=NULL;
        p->salary=salary;
		if(n==1)
		{
			list=p;
		}
		else 
		{
			tail->next=p;
		}
		tail=p;
		scanf("%s%d",name,&salary);
	}


//	list1=delct(list,a);
     
	for(q=list;q!=NULL;q=q->next)
	{
		printf("%s  %d\n",q->name,q->salary);
	}

	return 0;
}

struct yuan *delct(struct yuan *list,int x )
{
	struct yuan *q=NULL,*p=NULL;
	q=(struct yuan *)malloc(sizeof(struct yuan));
	p=(struct yuan *)malloc(sizeof(struct yuan));
	q=list->next;
	p=list;

	for(;q!=NULL;q=q->next,p=p->next)
	{
		if(q->salary==x)
		{
			p->next=q->next;
		}
	}

	

	return list;
}

			


		
		
