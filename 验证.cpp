#include <stdio.h>

struct student{
	int num;
	char name[10];
	int score;
	struct student *next;
}; 
	
int main()
{
	int n,i;
	struct student s[10];
	
	struct student *head,*p;

	printf("请输入学生的人数:");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("请输入学生信息:");
		scanf("%d%s%d",&s[i].num,&s[i].name,&s[i].score);

		if(i==n-1)
		{
			s[i].next=NULL;
		}

		else
		{
			s[i].next =&s[i+1];
		}
	}

	head=&s[0];

	for(p=head;p!=NULL;p=p->next)
	{
		printf("%d  %s  %d\n",p->num,p->name,p->score);
	}

	return 0;

}
