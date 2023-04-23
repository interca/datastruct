#include <stdio.h>
#include <math.h>
int factorsum(int a){
    int i,sum=0; 
 for(i=1;i<=sqrt(a);i++){
  float b;
     b=a*1.0/i;
     if(b-(int)b==0&&i!=1)
        sum=sum+i+b;
 }
 return sum;
}
int main()
{
 int m,n,i;
 printf("输入两个正整数m和n(1<=m<=n<=10000):");
 scanf("%d %d",&m,&n);
 printf("%d到%d之间的所有完数是:\n",m,n);
    for(i=m;i<=n;i++){
     if(factorsum(i)==i)
        printf("%d  ",i);
 }
    return 0;
}
 