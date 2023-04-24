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
//tsp问题
int n;
//打印floyed路线
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(fpath[a][b])<<" ";
    printfpath(fpath,fpath[a][b],b);
}

int path[1000][1000];

void tspPrint(int i,int j){
   if(path[i][j] < 0)return;
   tspPrint(i - (1 <<(j - 1)),path[i][j]);
   cout<<j<<"->";
}
void tsp(){
   //floyd算法的结果
  vector<vector<int>>f(1000,vector<int>(1000,mx));
  //打印路径
  vector<vector<int>>fpath(1000,vector<int>(1000,mx));
  for(int i = 1 ; i <= n ; i ++){
      for(int j = 1 ; j <= n ; j ++){
          f[i][j] = graph[i][j];
          fpath[i][j] = -1;
          path[i][j] = -1;
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
 //dp表示从目的地走到j出发，经过i,走过的路程
   int m = pow(2,cnt);//1<<n
   for(int i = 1 ; i< 1000 ; i ++){
       for(int j = 1 ; j < 1000 ; j ++){
           dp[i][j] = mx;
       }
   }
   //从一号点走到一号点
   dp[1][1] = 0;
   for(int i =  0; i < m ; i ++){
       for(int j = 1 ; j  <= n ; j ++){
           //集合包括目的顶点
           if(i >> (j - 1) & 1 == 0)continue;
           for(int k = 1 ; k <= n ; k ++){
               //从集合里面选出一个数
               if((i - (1 <<(j - 1)))>>(k - 1)& 1){
                  //更新
                  if(f[j][k] + dp[i-(1 <<(j - 1))][k] < dp[i][j]){
                       dp[i][j] = min(dp[i][j],graph[j][k] + dp[i-(1 <<(j - 1))][k]);
                       path[i][j] = k;
                  }
               }
           }
       }
   }
//现在知道1到各个点的哈密顿回路，然后加上各个点到1的距离
   int ans = mx;
   int t = -1;
   for(int i = 2 ; i<= n ; i ++){
       if(dp[m - 1][i] + graph[i][1] < ans){
           t = i;
       }
      ans = min(ans,dp[m - 1][i] + graph[i][1]);
   }
   cout<<"路径和是:";
   cout<<ans<<endl;
   cout<<"路径是:"
   cout<<1<<"->";
   tspPrint(m - 1,t);
   cout<<1<<endl;
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
