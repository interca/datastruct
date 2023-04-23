#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//哈希数组
int has[100100];
//每个下标对应的值
int value[20010];
//下一个点的下标
int nex[20010];
int ide = 0;
//是否删除
int del[20010];



//查询
void queryHash(int val){
    int key = val % 7;
    for(int i = has[key] ;i!=-1 ; i = nex[i]){
        if(value[i] == val && del[i] == 0){
            cout<<"找到这个数了"<<endl;
            return;
        }
    }
    cout<<"没有找到这个数"<<endl;
}

//插入哈希表
void insertHash(int val){
  int key = val%7;
  value[ide] = val;
  nex[ide] = has[key];
  has[key] = ide ++;
}

void delHash(int val){
     int key = val % 7;
    for(int i = has[key] ;i!=-1 ; i = nex[i]){
        if(value[i] == val && del[i] == 0){
            cout<<"删除成功"<<endl;
            del[i] = 1;
            return;
        }
    }
    cout<<"没有这个数"<<endl;
}
int main(){
  vector<int> num  = {5,6,4,2,3,6,7,8,9};
  for(int i = 0 ; i < num.size() ; i ++){
      has[i] = -1;
  }
  for(int i = 0 ; i< num.size() ; i  ++){
      insertHash(num[i]);
  }

  int x;
  int c;
  while(true){
      printf("1-插入一个数 2-查找一个数,3-删除一个数\n");
      cin>>c;
      switch(c){
          case 1:
            cout<<"输入要插入的数字"<<endl;
            cin>>x;
            insertHash(x);
            break;
          case 2 :
            cout<<"输入要查找的数"<<endl;;
            cin>>x;
            queryHash(x);
            break;
          case 3:
            cout<<"输入要删除的数"<<endl;
            cin>>x;
            delHash(x);
            break;    
      }
  }
  
}