#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int num[1000];
//移动次数
int countMove = 0;
//比较次数
int countCompare = 0;

//初始化
void init(){
    countMove = 0;
    countCompare = 0;
    //随机数
    srand((unsigned)time(NULL));
    for(int i = 0 ; i < 1000 ; i ++){
        num[i] = (rand()%18000)+ 2000;
    }
}

//快速排序
void quickSort(int l,int r){
    if(l>=r)return;
        int left=l-1;
        int right=r+1;
        long mid=num[(l+r)/2];
        while(left<right){
            while(num[++left]<mid){
                countCompare++;
            }
            countCompare++;
            while(num[--right]>mid){
                countCompare++;
            }
            countCompare ++;
            if(left<right){
                long temp=num[left];
                num[left]=num[right];
                num[right]=temp;
                countMove = countMove + 2;
            }
        }
        quickSort(l,right);
        quickSort(right+1,r);
}
int main(){
  init();
  quickSort(0,999);
 
   printf("快速排序的比较操作次数为%d\n",countCompare);
   printf("快速排序的移动操作次数为%d\n",countMove);
}