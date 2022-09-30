#include<stdio.h>
#include<stdlib.h>
int stack[100];
int index;
void creat(int flag,int number){
    while(number>0){
        stack[index++]=number%flag;
        number=number/flag;
    }
}
int main(){
   while(1){
       printf("输入进制和数\n");
       int number;
       int flag;
       index=0;
       scanf("%d%d",&flag,&number);
       creat(flag,number);
       for(int i=index-1;i>=0;i--){
           printf("%d",stack[i]);
       }
       printf("\n");
   }
   return 0;
}