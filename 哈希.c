#include<stdlib.h>
#include<stdio.h>

//����
int d[10000];
//ÿ���±��Ӧ��ֵ
int e[10000];
//��һ������±�
int ne[10000];
int index = 0;
//�Ƿ�ɾ��
int de[10000];

//����
void insert(int x){
  int k = x%5;
  e[index] = x;
  ne[index] = d[k];
  d[k] = index ++;
}

//��ѯ
void query(int x){
    int k = x % 5;
    for(int i = d[k] ;i!=-1 ; i = ne[i]){
        if(e[i] == x && de[i] == 0){
            printf("�ҵ���\n");
            return;
        }
    }
    printf("û���ҵ������\n");
}

void delete(int x){
     int k = x % 5;
    for(int i = d[k] ;i!=-1 ; i = ne[i]){
        if(e[i] == x && de[i] == 0){
            printf("ɾ���ɹ�\n");
            de[i] = 1;
            return;
        }
    }
    printf("û�������\n");
}
int main(){
  int a[10] = {1,2,4,5,6,7,8,90,23,11};
  for(int i = 0 ; i < 10000 ; i ++){
      d[i] = -1;
  }
  for(int i = 0 ; i< 10 ; i  ++){
      insert(a[i]);
  }

  int x;
  int choice;
  while(1){
      printf("1-���� 2-����,3-ɾ��\n");
      scanf("%d",&choice);
      switch(choice){
          case 1:
            printf("����Ҫ�������\n");
            scanf("%d",&x);
            insert(x);
            break;
          case 2 :
            printf("����Ҫ���ҵ���\n");
            scanf("%d",&x);
            query(x);
            break;
          case 3:
            printf("����Ҫɾ������\n");
            scanf("%d",&x);
            delete(x);
            break;    
      }
  }
  
}