#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;
//վ�������
int n;
//վ������
int cnt;
//�Ƿ�ɾ��
int isDelete[1000];
//��ʾ������
int mx = 100000000;
//����
int graph[1000][1000];
//Ʊ��
int price[1000][1000];
//���ֺ�վ��ӳ���ϵ
map<string,int>m;
//����վ������ʱ���                
//��һ���㵽��һ����Ŀ�ʼʱ��ͽ���ʱ��
map<int,map<int,string>>startTime;
map<int,map<int,string>>endTime;

//�˻�����
string username = "hyj";
string password = "123";

//�����������
void insert(int a,int b,int c){
    graph[a][b] = graph[b][a] = c;
}

//��ʼ��
void init(){
    cnt = 8;
    n = 8;
    for(int i = 1 ;i <= n ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            graph[i][j] = mx;
            price[i][j] = mx;
            if(i == j){
                graph[i][j] = 0;
                price[i][j] = 0;
            }
        }
    }
    //�������ݵĲ��ԣ��ֶ���������
    insert(1,2,4);
    insert(1,4,3);
    insert(2,4,4);
    insert(2,3,5);
    insert(2,8,1);
    insert(3,5,9);
    insert(3,8,3);
    insert(4,6,8);
    insert(5,7,4);
    insert(6,7,5);
    insert(6,8,4);
    insert(7,8,6);
}
//��ӡfloyed·��
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(fpath[a][b])<<"->";
    printfpath(fpath,fpath[a][b],b);
}



//floyd
void floyd(){
  int a,b;
  cout<<"����������:";
  cin>>a>>b;
  if(a < 1 || b < 1 || a > n || b > n){
      cout<<"�������"<<endl;
      return;
  }
  if(a == b){
      cout<<"���·���Լ����Լ�"<<endl;
      return;
  }
  //floyd�㷨�Ľ��
  vector<vector<int>>f(1000,vector<int>(1000,mx));
  //��ӡ·��
  vector<vector<int>>fpath(1000,vector<int>(1000,mx));
  for(int i = 1 ; i <= n ; i ++){
      for(int j = 1 ; j <= n ; j ++){
          f[i][j] = graph[i][j];
          fpath[i][j] = -1;
      }
  }
  cout<<f[a][b]<<endl;
  for(int k = 1 ; k <= n ; k ++){
      for(int i = 1 ; i <= n ; i ++){
          for(int j = 1 ; j <= n ; j ++){
              if(isDelete[i] == 1 || isDelete[i] == 1 || isDelete[j] == 1)continue;
              if(f[i][j] > f[i][k] + f[k][j]){
                  f[i][j] = f[i][k] + f[k][j];
                  fpath[i][j] = k;
              }
          }
      }
  }
  cout<<a<<"��"<<b<<"�����·����Ϊ"<<f[a][b]<<endl;
  cout<<"·��:"<<endl;
  cout<<a<<"->";
  printfpath(fpath,a,b);
  cout<<b<<endl<<endl;
  
}

//�洢tsp·��
int path[1000][1000];
//��tsp
int dp[1000][1000];

//�ݹ��ӡtsp·��
void tspPrint(int i,int j,vector<int>&v){
   if(path[i][j] < 0)return;
   tspPrint(i - (1 <<(j - 1)),path[i][j],v);
   v.push_back(j);
}

//tsp����
void tsp(){
  //��¼tsp·��������
  vector<int>v;
  //floyd�㷨�Ľ��
  vector<vector<int>>f(1000,vector<int>(1000,mx));
  //��ӡ·��
  vector<vector<int>>fpath(1000,vector<int>(1000,mx));
  for(int i = 1 ; i <= n ; i ++){
      for(int j = 1 ; j <= n ; j ++){
          f[i][j] = graph[i][j];
          fpath[i][j] = -1;
      }
  }
  for(int k = 1 ; k <= n ; k ++){
      for(int i = 1 ; i <= n ; i ++){
          for(int j = 1 ; j <= n ; j ++){
              if(f[i][j] > f[i][k] + f[k][j]){
                  f[i][j] = f[i][k] + f[k][j];
                  fpath[i][j] = k;
              }
          }
      }
  }
   //dp��ʾ��Ŀ�ĵ��ߵ�j����������i,�߹���·��
   int m = pow(2,n);
   for(int i = 1 ; i< 1000 ; i ++){
       for(int j = 1 ; j < 1000 ; j ++){
           path[i][j] = -1;
           dp[i][j] = mx;
           fpath[i][j] = -1;
       }
   }
   //��һ�ŵ��ߵ�һ�ŵ�
   dp[1][1] = 0;
   for(int i = 0 ; i < m ; i ++){
       for(int j = 1 ; j  <= n ; j ++){
           //���ϰ���Ŀ�Ķ���
           if(i >> (j - 1) & 1 == 0)continue;
           for(int k = 1 ; k <= n ; k ++){
               //�Ӽ�������ѡ��һ����
               if((i - (1 <<(j - 1)))>>(k - 1)& 1){
                  //����
                  if(graph[j][k] + dp[i-(1 <<(j - 1))][k] < dp[i][j]){
                      dp[i][j] = min(dp[i][j],f[j][k] + dp[i-(1 <<(j - 1))][k]);
                      path[i][j] = k;
                  }

               }
           }
       }
   }
   //����֪��1��������Ĺ��ܶٻ�·��Ȼ����ϸ����㵽1�ľ���
   int ans = mx;
   int idex;
   for(int i = 2 ; i<= n ; i ++){
       if(dp[m - 1][i] + f[i][1] < ans){
          idex = i;
      }
      ans = min(ans,dp[m - 1][i] + f[i][1]);
   }
   cout<<"TSP·������:";
   cout<<ans<<endl;
   cout<<"TSP·����:";
   v.push_back(1);
   tspPrint(m - 1,idex,v);
   v.push_back(1);
   cout<<"TSP·����:";
   for(int i =0 ; i < v.size()  - 1; i ++){
      int a = v[i];
      int b = v[i + 1];
      cout<<a - 1<<"->";
      //֤��a b ������ͨ��floydʵ�ֵ�
      if(graph[a][b] > f[a][b]){
         printfpath(fpath,a,b);
      }
      if(i == v.size() - 2){
          cout<<b<<endl;
      }
   }
}


main(){
    init();
    tsp();
}