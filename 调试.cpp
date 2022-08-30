#include <stdio.h>

struct yuan{
	char name[10];
	int money;
	struct yuan *next;
};

void maxlist(struct  yuan *s,struct yuan *p);

int main()
{
	int i=0;
	struct yuan a[100];
	struct yuan *list;
	scanf("%s%d",a[i].name,&a[i].money);
	
	do
	{
		
		a[i].next=&a[i+1];
		i++;
		scanf("%s%d",a[i].name,&a[i].money);
	}while(a[i].money!=0);

	a[i].next=NULL;
	list=&a[0];

	maxlist(list,a);

	return 0;
}

void maxlist(struct yuan *s,struct yuan *p)
{
	struct yuan *max;
	int i=0;
	max=s;
	while(p!=NULL)
	{
		if(max->money< p->money )
		{
			max=p;
		}
		p++;
	}

	printf("%s%d\n",max->name,max->money);
}
		
