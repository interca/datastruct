#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int num[50];
int d[10000];
int e[10000];
int ne[10000];

int index=0;
//��ʼ��
void init(){
    //�����
    srand((unsigned)time(NULL));
    for(int i = 0 ; i < 50 ; i ++){
        num[i] = (rand()%1800)+ 200;
    }
    for(int i = 0 ; i  < 10000 ; i ++){
        d[i] = -1;
    }

} 

void insert(int x){
        int k= x % 7;
        e[index]=x;
        ne[index]=d[k];
        d[k]=index;
        index++;
    }

int quary(int x){
    int k= x % 7;
    for(int i=d[k];i!=-1;i=ne[i]){
       if(e[i]==x)return 1;
    }
    return 0;
}
int main(){
    init();
    for(int i = 0 ; i < 50 ;  i++){
        insert(num[i]);
    }
    while(1){
        int choice;
        printf("�����ѯ������\n");
        scanf("%d",&choice);
        int r = quary(choice);
        if(choice == 1)printf("�������\n");
        else printf("û�������\n");
    }
}
