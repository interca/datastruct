#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int dp[1000][1000];
int graph[1000][1000];
int mx = 100000000;
int cnt;
//tsp����
int n;
//��ӡfloyed·��
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(fpath[a][b])<<"->";
    printfpath(fpath,fpath[a][b],b);
}

int path[1000][1000];


//�ݹ��ӡtsp·��
void tspPrint(int i,int j,vector<int>&v){
   if(path[i][j] < 0)return;
   tspPrint(i - (1 <<(j - 1)),path[i][j],v);
   v.push_back(j);
}
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
   int m = pow(2,cnt);
   for(int i = 1 ; i< 1000 ; i ++){
       for(int j = 1 ; j < 1000 ; j ++){
           path[i][j] = -1;
           dp[i][j] = mx;
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
   v.push_back(1);
   tspPrint(m - 1,idex,v);
   v.push_back(1);
   cout<<"TSP·����:";
   for(int i =0 ; i < v.size()  - 1; i ++){
      int a = v[i];
      int b = v[i + 1];
      cout<<a<<"->";
      //֤��a b ������ͨ��floydʵ�ֵ�
      if(graph[a][b] > f[a][b]){
         //cout<<a<<"ssss"<<b<<endl;
         printfpath(fpath,a,b);
      }
      if(i == v.size() - 2){
          cout<<b<<endl;
      }
   }
}
void insert(int a,int b,int c){
    graph[a][b] = graph[b][a] = c;
}
int main(){
    for(int i = 0 ;i < 1000 ; i ++){
        for(int j = 0 ; j< 1000 ; j ++){
            graph[i][j] = mx;
        }
    }
  cnt = 3;
  n = 3;
  insert(1,2,1);
  insert(2,3,1);
  insert(3,1,3);
  tsp();
}
