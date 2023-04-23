#include<stdio.h>
int size = 0;
char queue[5];//循环队列
int left = 0;
int right = 0;
int max = 8;//设置队列最大元素为 8 个
int nextindex(int index){
if(index+1<max)
return index+1;
return 0;
}
   //入队
void push(char x){
   if(size>=max)printf("队列满了\n");
   else {
  size++;
  queue[right] = x;
   right=nextindex(right);
 }
}
//出队
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
   printf("序列是:\n");
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
   printf("1-判断队列是否为空,2-入队，3-出队，4-输出队列元素个数，5-队列序列\n");
   scanf("%d",&choice);
   getchar();
   int a=0;
   char b='0';
   switch(choice){
     case 1:
       a = isEmpty();
      if(a == 1)printf("队列为空\n");
      else printf("不为空\n");
      break;
    case 2:
       b ='0';
       printf("输入要入队的元素\n");
       scanf("%c",&b);
       push(b);
       break;
    case 3 :
       b = pop();
      if(b == '0')printf("队列为空\n");
      else printf("出队元素为%c\n",b);
      break;
    case 4:
      printf("队列元素个数%d\n",sizeOfQueue());
      break;
    case 5:
       printQueue();
       break;
   }
}
return 0;
}
