#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//��ϣ����
int has[100100];
//ÿ���±��Ӧ��ֵ
int value[20010];
//��һ������±�
int nex[20010];
int ide = 0;
//�Ƿ�ɾ��
int del[20010];



//��ѯ
void queryHash(int val){
    int key = val % 7;
    for(int i = has[key] ;i!=-1 ; i = nex[i]){
        if(value[i] == val && del[i] == 0){
            cout<<"�ҵ��������"<<endl;
            return;
        }
    }
    cout<<"û���ҵ������"<<endl;
}

//�����ϣ��
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
            cout<<"ɾ���ɹ�"<<endl;
            del[i] = 1;
            return;
        }
    }
    cout<<"û�������"<<endl;
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
      printf("1-����һ���� 2-����һ����,3-ɾ��һ����\n");
      cin>>c;
      switch(c){
          case 1:
            cout<<"����Ҫ���������"<<endl;
            cin>>x;
            insertHash(x);
            break;
          case 2 :
            cout<<"����Ҫ���ҵ���"<<endl;;
            cin>>x;
            queryHash(x);
            break;
          case 3:
            cout<<"����Ҫɾ������"<<endl;
            cin>>x;
            delHash(x);
            break;    
      }
  }
  
}