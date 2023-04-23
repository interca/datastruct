#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int num[1000];
//�ƶ�����
int countMove = 0;
//�Ƚϴ���
int countCompare = 0;

//��ʼ��
void init(){
    countMove = 0;
    countCompare = 0;
    //�����
    srand((unsigned)time(NULL));
    for(int i = 0 ; i < 1000 ; i ++){
        num[i] = (rand()%18000)+ 2000;
    }
}

//��������
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
 
   printf("��������ıȽϲ�������Ϊ%d\n",countCompare);
   printf("����������ƶ���������Ϊ%d\n",countMove);
}