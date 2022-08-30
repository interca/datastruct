#include<stdio.h>
#include<stdlib.h>
typedef struct t
{
    int data;
    int parent;
    int n;
}T1;
void insert(T1*T,int i,int data,int parent);
int  findroot(T1*T,int number);
int main(){
    int n;
    int i;
    int number;
    T1 *T;
    printf("input n:\n");
    scanf("%d",&n);
    int data,parent;
    T=(T1*)malloc(sizeof(T1)*n);
    for(i=0;i<n;i++){
         T[i].n=n;
         scanf("%d%d",&data,&parent);
         insert(T,i,data,parent);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",T[i].data,T[i].parent,T[i].n);
    }
    for(i=0;i<n;i++){
        printf(" The %d root is %d and count=%d \n",i+1,findroot(T,i+1),T[findroot(T,i+1)].data);
    }
    return 0;
}
void  insert(T1*T,int i,int data,int parent){
    T[i].data=data;
    T[i].parent=parent;
}
int findroot(T1*T,int number){
    int i;
    for(i=0;T[i].data!=number&&i<T[0].n;i++);
    if(i>=T[0].n)return -1;
    for(;T[i].parent>=0;i=T[i].parent);
    return i;

}

