#include<stdio.h>
int size = 0;
char queue[5];//ѭ������
int left = 0;
int right = 0;
int max = 8;//���ö������Ԫ��Ϊ 8 ��
int nextindex(int index){
if(index+1<max)
return index+1;
return 0;
}
   //���
void push(char x){
   if(size>=max)printf("��������\n");
   else {
  size++;
  queue[right] = x;
   right=nextindex(right);
 }
}
//����
char pop(){
     if(size<=0)
      return '0';
    else {
      size--;
      char k = queue[left];
      left = nextindex(left);
    return k;
  }
}
int isEmpty(){
    return size ==0;
}
int sizeOfQueue(){
   return size;
}
void printQueue(){
   printf("������:\n");
   int k = left;
   for(int i = 0;i<size;i++){
       printf("%c ",queue[k]);
       k = nextindex(k);
    }
    printf("\n");
}
int main(){
while(1){
   int choice=0;
   printf("1-�ж϶����Ƿ�Ϊ��,2-��ӣ�3-���ӣ�4-�������Ԫ�ظ�����5-��������\n");
   scanf("%d",&choice);
   getchar();
   int a=0;
   char b='0';
   switch(choice){
     case 1:
       a = isEmpty();
      if(a == 1)printf("����Ϊ��\n");
      else printf("��Ϊ��\n");
      break;
    case 2:
       b ='0';
       printf("����Ҫ��ӵ�Ԫ��\n");
       scanf("%c",&b);
       push(b);
       break;
    case 3 :
       b = pop();
      if(b == '0')printf("����Ϊ��\n");
      else printf("����Ԫ��Ϊ%c\n",b);
      break;
    case 4:
      printf("����Ԫ�ظ���%d\n",sizeOfQueue());
      break;
    case 5:
       printQueue();
       break;
   }
}
return 0;
}
