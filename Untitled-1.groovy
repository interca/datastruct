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
       head->next=node;
       return head;
   }
   //保存头结点
   list*help=head;
   while(head->next!=NULL){
       //如果指数重复出现就合并
       if(head->exp=exp){
          head->value=head->value+value;
          return help;
       }
       head=head->next;
   }
   //最后一个结点要判断是不是有重复的指数
   if(head->exp=exp){
       head->value=head->value+value;
       return help;
   }
   //否则就把结点加入链表的末尾
   head->next=node;
   return help;
}

//输出链表
void printList(list*head){
    while(head!=NULL){
        printf("%dx%d",head->value,head->exp);
    }
    printf("\n");
}

int main(){
    list*head1 = NULL;
    list*head2 = NULL;
    int choice = -1;

    //输入链表1
    printf("生成链表1:/n");
    int value=-1;
    int exp=-1;
    scanf("%d%d",&value,&exp);
    while(value!=0&&exp!=-1){
       head1 = creatList(head1,value,exp);
       scanf("%d%d",&value,&exp);
    }

    //输入链表2
    printf("生成链表2:/n");
      scanf("%d%d",&value,&exp);
    while(value!=0){
       head2 = creatList(head2,value,exp);
       scanf("%d%d",&value,&exp);
    }

    while(choice != 3){
        printf("1-多项式相加,2-多项式相减,3-输出链表1,4-输出链表2,5-链表1排序,6-链表2排序,7-退出");
        scanf("%d",&choice);
        switch(choice){
            case 1:
               break;
            case 2:
               break;
            case 3:
              printList(head1);
              break;
            case 4:printList(head2);
                 break;   
        }
    }
}