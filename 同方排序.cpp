#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
int compSum;
int moveSum;
const int n = 2000;
int array[n];

//��ʼ������
void initArray(){
    //��ʼ��
   compSum = moveSum = 0;
   //��ֵ
    srand((int)time(0));
    for(int i = 0 ; i < n ; i ++){
        array[i] = rand()%10000;
    }
}

void quickSort(int left,int right){
    if(left >= right)return;
    int l = left - 1;
    int r = right + 1;
    int mid = array[(l + r)/2];
    while(l < r){
        while(array[++l]<mid)compSum++;
        while(array[--r]>mid)compSum++;
        if(l<r){
            moveSum += 2;
            int flag=array[l];
            array[l]=array[r];
            array[right]=flag;
        }
    }
   quickSort(left,r);
   quickSort(r + 1,right);
}

//���Ĺ���
void mSort(int  left,int right,int mid){
    int help[right - left + 1];
    int index  = 0;
    int l = left;
    int r = mid + 1;
    //˫ָ��
    while(l <= mid && r <= right){
        compSum++;
        if(array[l] < array[r]){
            help[index++] = array[l];
            l++;
        }else {
            help[index++] = array[r];
            r ++;
        }
    }
    while(l <= mid){
        compSum++;
        help[index ++] = array[l];
        l++;
    }
    while(r <= right){
        compSum++;
        help[index++] = array[r];
        r++;
    }
   for(int i = 0 ; i < right - left + 1 ; i ++){
       if(array[i + left] != help[i])moveSum ++;
       array[i + left] = help[i];
   }
}

//�鲢
void memgeSort(int left,int right){
    if(left==right)return;
        int mid=(left+right)/2;
        //����ݹ�
        memgeSort(left,mid);
        //����
        memgeSort(mid+1,right);
        mSort(left,right,mid);
}


int main(){
   int c = 0;
   while(true){
     printf("1-�������� 2 - �鲢����\n");
     scanf("%d",&c);
     switch(c){
         case 1:
           initArray();
           quickSort(0,n-1);
           printf("�Ƚϴ�����%d,�ƶ�������%d\n",compSum,moveSum);
           break;
         case 2:
           initArray();
           memgeSort(0,n - 1);
           printf("�Ƚϴ�����%d,�ƶ�������%d\n",compSum,moveSum);
           break;  
     }
   }
}

