#include<stdio.h>
#include<stdlib.h>
//链表结点
typedef struct List{
    //系数
    int value;
    //指向下一个结点的指针
    struct List*next;
    //指数的大小
    int exp;
}list;

//生成链表函数
list* creatList(list*head,int value,int exp){
   list*node=(list*)malloc(sizeof(list));
   node->next=NULL;
   node->value=value;
   node->exp=exp;
   //头结点为空，吧这个结点插入头结点后面，然后返回
   if(head==NULL){
       head=node;
       return head;
   }
 
   //保存头结点
   list*help=head;
   while(head->next!=NULL){
       //如果指数重复出现就合并
       if(head->exp==exp){
          // printf("%d %d",head->exp,exp);
          head->value=head->value+value;
          return help;
       }
       head=head->next;
   }
   //最后一个结点要判断是不是有重复的指数
   if(head->exp==exp){
       head->value=head->value+value;
       return help;
   }
   //否则就把结点加入链表的末尾
   head->next=node;
   return help;
}

//输出链表
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

//排序
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

//合并
list*add(list*head1,list*head2){
    //合并后链表的头结点和尾结点
    list*head=NULL;
    list*last=NULL;

    while(head1!=NULL&&head2!=NULL){
      list*node=(list*)malloc(sizeof(list));
      node->next=NULL;
      //如果第一个链表的指数小于第二个链表的指数 那么第一个链表加入合并后的链表
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
    //最后还要分别判断两个链表是否走到尾
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

//相减
list*minus(list*head1,list*head2){
    //合并后链表的头结点和尾结点
    list*head=NULL;
    list*last=NULL;

    while(head1!=NULL&&head2!=NULL){
      list*node=(list*)malloc(sizeof(list));
      node->next=NULL;
      //如果第一个链表的指数小于第二个链表的指数 那么第一个链表加入合并后的链表
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
    //最后还要分别判断两个链表是否走到尾
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

    //输入链表1
    printf("生成链表1:\n");
    int value=-1;
    int exp=-1;
    scanf("%d%d",&value,&exp);
    while(value!=0&&exp!=0){
       head1 = creatList(head1,value,exp);
       scanf("%d%d",&value,&exp);
    }

    //输入链表2
    printf("生成链表2:\n");
      scanf("%d%d",&value,&exp);
    while(value!=0){
       head2 = creatList(head2,value,exp);
       scanf("%d%d",&value,&exp);
    }
    list*help;
    while(choice != 7){
        printf("1-多项式相加,2-多项式相减,3-输出链表1,4-输出链表2,5-链表1排序,6-链表2排序,7-退出");
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

