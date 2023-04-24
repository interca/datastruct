#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int dp[1000][1000];
int graph[1000][1000];
int mx = 100000000;
int cnt;
//tsp问题
int n;
void tsp(){
   //表示经过集合j的点最终回到i，j是二进制表示集合
   int m = pow(2,cnt) - 1;
   for(int i = 1 ; i< 1000 ; i ++){
       for(int j = 1 ; j < 1000 ; j ++){
           dp[i][j] = mx;
       }
   }
   for(int i = 1 ; i <= n ; i++){
       //不经过任何集合到i
       dp[i][0] = graph[i][1];
   }
   for(int j = 1 ; j < m ; j ++){
       for(int i = 1 ; i  <= n ; i ++){
           dp[i][j] = mx;
           //集合不能包括i自己
           if((j >> (i - 1)) & 1 == 1)continue;
           for(int k = 1 ; k <= n ; k ++){
               //从集合里面选出一个数
               if((j >> (k - 1)) & 1 == 0)continue;
               //更新
               dp[i][j] = min(dp[i][j],graph[i][k] + dp[k][j^(1 << (k - 1))]);
               if(i == 2 && j == 4){
                   cout<<k<<" "<<graph[i][k]<<" "<<dp[k][j ^ (1 << (k - 1))]<<endl;;
               }
           }
       }
   }
   cout<<dp[1][m - 1]<<endl;
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
  cout<<dp[2][4]<<endl;
}
