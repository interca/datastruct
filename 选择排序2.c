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
        num[i] = rand()%10000;
    }
}

//插入排序
void insertSort(){
    //初始化
    init();
   for(int i = 1 ; i < 1000 ; i ++){
       int index = i;
       int flag = num[i];
       while(index - 1 >= 0 && num[index - 1]>flag){
           countCompare++;
           countMove ++;
           num[index] = num[index - 1];
           index --;
       }
       countCompare ++;
       num[index] = flag;
       if(index != i)
       countMove ++;
   }
   printf("插入排序的比较操作次数为%d\n",countCompare);
   printf("插入排序的移动操作次数为%d\n",countMove);
}

//选择排序
void selectSort(){
   init();
   for(int i = 0 ; i < 1000 ; i ++){
       int index = i;
       for(int j = i + 1 ; j < 1000 ; j ++){
           if(num[j] < num[index]){
                index = j;
           }
          countCompare++;
       }
       if(index != i){
           int temp = num[i];
           num[i] = num[index];
           num[index] = temp;
           countMove = countMove + 2;
      }
   }

   printf("选择排序的比较操作次数为%d\n",countCompare);
   printf("选择排序的移动操作次数为%d\n",countMove);
}

//往下调整
void down(int index,int size){
    int parent = index;
    int temp = num[index];
    int child = 0;
    for(;parent*2 + 1<size;parent = child){
        child = parent * 2 + 1;
        if(child + 1 < size && num[child + 1] > num[child])child ++;
        countCompare ++;
        if(temp < num[child]){
            num[parent] = num[child];
            countMove ++;
        }else break;
    }
    if(parent != index){
        num[parent] = temp;
        countMove = countMove + 2;
    }
}

//堆排序
void heapSort(){
   init();
   //将数组调整为一个堆
   for(int i = 1000/2 ; i >= 0  ; i --){
       down(i,1000);
   }
   int size = 1000;
  
   for(int i = 0 ; i < 1000 ; i ++){
       int temp = num[0];
       num[0] = num[--size];
       num[size] = temp;
       countMove = countMove + 2;
       down(0,size); 
   }
   printf("\n");
   printf("堆排序的比较操作次数为%d\n",countCompare);
   printf("堆排序的移动操作次数为%d\n",countMove);
}
int main(){
    //插入排序
    insertSort();
    printf("\n");
    //选择排序
    selectSort();
    //堆排序
    heapSort();
}
 for(int i = 0 ; i < 3 ; i ++){
	  if(a % v[i] == 0 && s % v[i] == 0){
		  a = a/v[i];
		  s = s / v[i];
	  }
	   if(b % v[i] == 0 && s % v[i] == 0){
		  b = b/v[i];
		  s = s / v[i];
	  }
	   if(c % v[i] == 0 && s % v[i] == 0){
		  c = c/v[i];
		  s = s / v[i];
	  }
  }
  sum1 = a * b * c / s;
  a = (n - 1);
  b = n;
  c = n + 1;
  s = 3;
  if(a % 3 == 0 && s % 3 == 0){
	  a = a / 3;
	  s = s/3;
  }
   if(b % 3 == 0 && s % 3 == 0){
	  b = b / 3;
	  s = s/3;
  }

   if(c % 3 == 0 && s % 3 == 0){
	  c = c / 3;
	  s = s/3;
  }