#include<stdio.h>
#include<stdlib.h>
typedef struct t{
    int *a;
    int size;
    int max;
}T1;
T1*T;
void creat(int max,int n);
void print();
void insert(int number);
int delect();
int main(){
    int n,number,i;
    int max;
    printf("input two number max and n:\n");
    scanf("%d%d",&max,&n);
    creat(max,n);
    for(i=0;i<n;i++){
          scanf("%d",&number);
          insert(number);
    }
    int choice;
    while(1){
          printf("input a choice:1-insert,2-delect,3-printf\n");
          scanf("%d",&choice);
          switch(choice){
              case 1:printf("input a number:\n");scanf("%d",&number);insert(number);break;
              case 2:printf("The number is %d\n",delect());
              case 3:print();printf("\n");
          }
    }
    return 0;
}
void insert(int number){
    int i=++T->size;
    for(;T->a[i/2]<=number;i=i/2){
        printf("1");
        T->a[i]=T->a[i/2];
    }
    T->a[i]=number;
}
int delect(){
    int temp=T->a[T->size--];
    int maxlist=T->a[1];
    int parent=1;
    int chid;
    for(;parent*2<=T->size;parent=chid){
        chid=parent*2;
        if((chid!=T->size)&&T->a[chid+1]>T->a[chid]){
            chid++;
        }
        if(T->a[parent]<temp)break;
        else {
            T->a[parent]=T->a[chid];
        }
    }
    T->a[parent]=temp;
    return maxlist;
}
void print(){
    for(int i=1;i<=T->size;i++){
        printf("%d ",T->a[i]);
    }
}
void creat(int max,int n){
    T=(T1*)malloc(sizeof(T1));
    T->a=(int*)malloc((max+1)*sizeof(int));
    T->a[0]=1000;
    T->size=0;
    T->max=max;
}