#include<stdio.h>
#include<stdlib.h>
//������
typedef struct List{
    //ϵ��
    int value;
    //ָ����һ������ָ��
    struct List*next;
    //ָ���Ĵ�С
    int exp;
}list;

//����������
list* creatList(list*head,int value,int exp){
   list*node=(list*)malloc(sizeof(list));
   node->next=NULL;
   node->value=value;
   node->exp=exp;
   //ͷ���Ϊ�գ������������ͷ�����棬Ȼ�󷵻�
   if(head==NULL){
       head=node;
       return head;
   }
 
   //����ͷ���
   list*help=head;
   while(head->next!=NULL){
       //���ָ���ظ����־ͺϲ�
       if(head->exp==exp){
          // printf("%d %d",head->exp,exp);
          head->value=head->value+value;
          return help;
       }
       head=head->next;
   }
   //���һ�����Ҫ�ж��ǲ������ظ���ָ��
   if(head->exp==exp){
       head->value=head->value+value;
       return help;
   }
   //����Ͱѽ����������ĩβ
   head->next=node;
   return help;
}

//�������
void printList(list*head){
    int flag=0;
    while(head!=NULL){
        if(head->value!=0){
            if(head->value>0&&flag!=0)printf("+");
            printf("%d",head->value);
            if(head->exp!=0)
            printf("x%d",head->exp);
            flag++;
        }
        head=head->next;
    }
    printf("\n");
}

//����
list* sort(list*head){
   int count=0;
   list*help2=head;
   while(help2!=NULL){
       help2=help2->next;
       count++;
   }
 
   for(int i=0;i<count-1;i++){
       list*node=head;
       while(node->next!=NULL){
           if(node->exp>node->next->exp){
               int temp1=node->value;
               int temp2=node->exp;
               node->value=node->next->value;
               node->exp=node->next->exp;
               node->next->value=temp1;
               node->next->exp=temp2;
           }
           node=node->next;
       }
   }
   return head;
}

//�ϲ�
list*add(list*head1,list*head2){
    //�ϲ��������ͷ����β���
    list*head=NULL;
    list*last=NULL;

    while(head1!=NULL&&head2!=NULL){
      list*node=(list*)malloc(sizeof(list));
      node->next=NULL;
      //�����һ�������ָ��С�ڵڶ��������ָ�� ��ô��һ���������ϲ��������
      if(head1->exp<head2->exp){
         node->value=head1->value;
         node->exp=head1->exp;
         head1=head1->next;
      }else if(head1->exp>head2->exp){
          node->value=head2->value;
          node->exp=head2->exp;
          head2=head2->next;
      }else {
           node->value=head2->value+head1->value;
          node->exp=head2->exp;
          head1=head1->next;
          head2=head2->next;
      }
      if(head==NULL){
          head=node;
          last=node;
      }
      else {
        last->next=node;
        last=node;
      }
    }
    //���Ҫ�ֱ��ж����������Ƿ��ߵ�β
    while(head1!=NULL){
       list*node=(list*)malloc(sizeof(list));
       node->next=NULL;
        node->value=head1->value;
        node->exp=head1->exp;
        head1=head1->next;

     if(head==NULL){
          head=node;
          last=node;
      }
      else {
        last->next=node;
        last=node;
      }
    }

    while(head2!=NULL){
       list*node=(list*)malloc(sizeof(list));
       node->next=NULL;
        node->value=head2->value;
        node->exp=head2->exp;
        head2=head2->next;

      if(head==NULL){
          head=node;
          last=node;
      }
      else {
        last->next=node;
        last=node;
      }
    }

    return head;
}

//���
list*minus(list*head1,list*head2){
    //�ϲ��������ͷ����β���
    list*head=NULL;
    list*last=NULL;

    while(head1!=NULL&&head2!=NULL){
      list*node=(list*)malloc(sizeof(list));
      node->next=NULL;
      //�����һ�������ָ��С�ڵڶ��������ָ�� ��ô��һ���������ϲ��������
      if(head1->exp<head2->exp){
         node->value=head1->value;
         node->exp=head1->exp;
         head1=head1->next;
      }else if(head1->exp>head2->exp){
          node->value=head2->value;
          node->exp=head2->exp;
          head2=head2->next;
      }else {
           node->value=head1->value-head2->value;
          node->exp=head2->exp;
          head1=head1->next;
          head2=head2->next;
      }
      if(head==NULL){
          head=node;
          last=node;
      }
      else {
        last->next=node;
        last=node;
      }
    }
    //���Ҫ�ֱ��ж����������Ƿ��ߵ�β
    while(head1!=NULL){
       list*node=(list*)malloc(sizeof(list));
       node->next=NULL;
        node->value=head1->value;
        node->exp=head1->exp;
        head1=head1->next;

     if(head==NULL){
          head=node;
          last=node;
      }
      else {
        last->next=node;
        last=node;
      }
    }

    while(head2!=NULL){
       list*node=(list*)malloc(sizeof(list));
        node->next=NULL;
        node->value=-head2->value;
        node->exp=head2->exp;
        head2=head2->next;

      if(head==NULL){
          head=node;
          last=node;
      }
      else {
        last->next=node;
        last=node;
      }
    }

    return head;
}

int main(){
    list*head1 = NULL;
    list*head2 = NULL;
    int choice = -1;

    //��������1
    printf("��������1:\n");
    int value=-1;
    int exp=-1;
    scanf("%d%d",&value,&exp);
    while(value!=0&&exp!=0){
       head1 = creatList(head1,value,exp);
       scanf("%d%d",&value,&exp);
    }

    //��������2
    printf("��������2:\n");
      scanf("%d%d",&value,&exp);
    while(value!=0){
       head2 = creatList(head2,value,exp);
       scanf("%d%d",&value,&exp);
    }
    list*help;
    while(choice != 7){
        printf("1-����ʽ���,2-����ʽ���,3-�������1,4-�������2,5-����1����,6-����2����,7-�˳�");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               help=add(head1,head2);
               printList(help);
               break;
            case 2:
              help=minus(head1,head2);
               printList(help);
               break;
            case 3:
              printList(head1);
              break;
            case 4:printList(head2);
                 break;  
            case 5:
              head1=sort(head1);
              break;
            case 6:
               head2=sort(head2);
               break;
            case 7:break;            
        }
    }
}

