#include<stdio.h>
#include<stdlib.h>
int findmax(int a, int b){
    if(a > b)return a;
    return b;
}
int sum,n,m;
void cout(int num1[n][3],int num2[m][3],int num3[sum][3]){
  int index1 =  0;
    int index2 = 0;
    int index3 = 0;
     int a,b,c;
    while(index1 < n || index2 < m){
        if(index1 >= n){
          a = num2[index2][0];
          b = num2[index2][1];
          c  = num2[index2][2];
        index2 ++;
        }else if(index2 >= m){
            a = num1[index1][0];
            b = num1[index1][1];
            c  = num1[index1][2];
           index1 ++;
        }else {
             if(num1[index1][0] < num2[index2][0] || num1[index1][1] < num2[index2][1]){
                a = num1[index1][0];
                b = num1[index1][1];
                c = num1[index1][2];
                index1 ++;
            }else if(num1[index1][0] > num2[index2][0] || num1[index1][1] > num2[index2][1]){
                 a = num2[index2][0];
                b = num2[index2][1];
                c = num2[index2][2];
                index2 ++;
            }else {
                a = num1[index1][0];
                b = num2[index1][1];
                c = num1[index1][2] + num2[index2][2];
                index1 ++;
                index2 ++;
            }
        }
        num3[index3][0] = a;
        num3[index3][1] = b;
        num3[index3][2] = c;
        index3 ++;
    }
      for(int i = 0 ;i < sum ; i++){
       printf("%d %d %d\n",num3[i][0],num3[i][1],num3[i][2]);
    }

}

void reverse(int num1[n][3],int a,int b){
   int num[a][b];
   int num4[n][3];
   for(int i = 0 ; i <= a ; i ++){
       for(int j = 0 ; j <= b ; j ++){
           num[i][j] = 0;
       }
   }
   //求出a的转置矩阵
   for(int i = 0 ; i < n ; i ++){
      // printf("%d %d %dsss",num1[i][0],num1[i][1],num1[i][2]);
       num[num1[i][1]][num1[i][0]] = num1[i][2];
   }
   int index = 0;
   for(int i = 0 ;i <= a ; i++){
       for(int j = 0 ;j <= b ; j++){
           if(num[i][j] > 0){
               num4[index][0] = i;
               num4[index][1] = j;
               num4[index][2] = num[i][j];
               index ++;
           }
       }
   }
   printf("矩阵D:\n");
   for(int i = 0 ; i < n ; i++){
       printf("%d %d %d\n",num4[i][0],num4[i][1],num4[i][2]);
   }
}
int main(){
    int a,b,c;
    printf("输入两个矩阵的行数\n");
    scanf("%d%d",&n,&m);
    int num1[n][3];
    int num2[m][3];
    int h[100][100];
    for(int i = 0 ;i < 100 ; i ++){
        for(int j = 0 ; j  < 100 ; j ++){
            h[i][j] = 0;
        }
    }
    int linemax = 0;
    int rowmax = 0;
    printf("输入第一个稀疏矩阵\n");
    for(int i = 0 ;i < n ; i ++){
        scanf("%d%d%d",&a,&b,&c);
        h[a][b] ++;
        num1[i][0] = a;
        num1[i][1] = b;
        num1[i][2] = c;
        linemax = findmax(a,linemax + 1);
        rowmax = findmax(b,rowmax + 1);
    }

    printf("输入第二个稀疏矩阵\n");
    for(int i = 0; i < m ; i ++){
        scanf("%d%d%d",&a,&b,&c);
        h[a][b] ++;
        num2[i][0] = a;
        num2[i][1] = b;
        num2[i][2] = c;
    }
    printf("-----------------\n");
     sum = 0;
    for(int i = 0 ; i < 100 ; i ++){
       for(int j = 0 ;j < 100 ; j ++){
           if(h[i][j] > 0){
               sum ++;
               h[i][j] = 0;
           }
       }
    }   
    int num3[sum][3];
    for(int i  = 0 ; i < sum ; i ++){
        num3[i][0] = num3[i][1] = num3[i][2] = 0;
    }
    //计算矩阵三
    cout(num1,num2,num3);
    
    //求a的倒置矩阵
    reverse(num1,linemax,rowmax);
    return 0;
}