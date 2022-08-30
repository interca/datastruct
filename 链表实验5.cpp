#include <stdio.h>
#include <stdlib.h>

struct student{
	int num;
	int score;
	struct student *next;
};

struct student *input(int n);
struct student *move(struct student *head,struct student *s);

int main()
{
	struct student *p1,*p2,*p0;
	int n;

	printf("������ѧ���ĸ���:");
	scanf("%d",&n);

	p1=input(n);

	printf("������Ҫ����ѧ������Ϣ:");
    p0=(struct student*)malloc(sizeof(struct student));
    p0->next=NULL;
	scanf("%d%d",&p0->num,&p0->score);

	p2=move(p1,p0);

	

	while(p2!=NULL)//��for���Ͳ�������p++��Ҫ��ѭ�����е����
	{
		printf("%d  %d\n",p2->num,p2->score);
		p2=p2->next;
	}

	
	return 0;
}

struct  student *input(int n)
{
	int i;
	struct student *head=NULL,*p1,*p2=NULL;

	for(i=1;i<=n;i++)
	{
		if((p1=(struct student *)malloc(sizeof(struct student)))==NULL)
		{
			printf("����ʧ��");
			exit(0);
		}
		p1->next=NULL;
		printf("������ѧ������Ϣ");
		scanf("%d%d",&p1->num,&p1->score);
		if(i==1) head=p1;
		else p2->next=p1;
		p2=p1;
	}

	return head;
}
struct student *move(struct student *head,struct student *s)
{
	struct student *p,*p1,*p2;
	p=s;p1=head;
	
	if(head==NULL)
	{
		head=p;
		p->next=NULL;
	}

	else
	{
		while((p->num > p1->num) && (p1->next!=NULL))
		{
			p2=p1;
			p1=p1->next;
		}

		if(p->num >p1->num)
		{
			p1->next=p;
			p->next=NULL;
		}

		else if(head==p1)
		{
			p->next=head;
			head=p;
		}

		else
		{
			p2->next=p;
			p->next=p1;
		}
	}

	return head;
}
