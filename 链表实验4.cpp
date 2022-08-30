#include <stdio.h>
#include <stdlib.h>

struct student{
	int num;
	int score;
	struct student *next;
};

struct student *input(int n);

int main()
{
	struct student *p;
	int n;

	printf("请输入学生的个数:");
	scanf("%d",&n);

	p=input(n);

	

	while(p!=NULL)//用for语句就不可以用p++，要用循环体中的语句
	{
		printf("%d  %d\n",p->num,p->score);
		p=p->next;
	}

	
	return 0;
}

struct  student* input(int n)
{
	int i;
	struct student *head=NULL,*p1,*p2=NULL;

	for(i=1;i<=n;i++)
	{
		if((p1=(struct student *)malloc(sizeof(struct student)))==NULL)
		{
			printf("分配失败");
			exit(0);
		}
		p1->next=NULL;
		printf("请输入学生的信息");
		scanf("%d%d",&p1->num,&p1->score);
		if(i==1) head=p1;
		else p2->next=p1;
		p2=p1;
	}

	return head;
}
