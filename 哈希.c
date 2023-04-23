#include<stdlib.h>
#include<stdio.h>

//数组
int d[10000];
//每个下标对应的值
int e[10000];
//下一个点的下标
int ne[10000];
int index = 0;
//是否删除
int de[10000];

//插入
void insert(int x){
  int k = x%5;
  e[index] = x;
  ne[index] = d[k];
  d[k] = index ++;
}

//查询
void query(int x){
    int k = x % 5;
    for(int i = d[k] ;i!=-1 ; i = ne[i]){
        if(e[i] == x && de[i] == 0){
            printf("找到了\n");
            return;
        }
    }
    printf("没有找到这个数\n");
}

void delete(int x){
     int k = x % 5;
    for(int i = d[k] ;i!=-1 ; i = ne[i]){
        if(e[i] == x && de[i] == 0){
            printf("删除成功\n");
            de[i] = 1;
            return;
        }
    }
    printf("没有这个数\n");
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
      printf("1-插入 2-查找,3-删除\n");
      scanf("%d",&choice);
      switch(choice){
          case 1:
            printf("输入要插入的数\n");
            scanf("%d",&x);
            insert(x);
            break;
          case 2 :
            printf("输入要查找的数\n");
            scanf("%d",&x);
            query(x);
            break;
          case 3:
            printf("输入要删除的数\n");
            scanf("%d",&x);
            delete(x);
            break;    
      }
  }
  
}