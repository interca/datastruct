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

	printf("������ѧ���ĸ���:");
	scanf("%d",&n);

	p=input(n);

	

	while(p!=NULL)//��for���Ͳ�������p++��Ҫ��ѭ�����е����
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
