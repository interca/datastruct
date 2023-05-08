#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<fstream>
#include<sstream>
using namespace std;
//站点最大编号
int n;
//站点数量
int cnt;
//是否被删除
int isDelete[1000];
//表示正无穷
int mx = 100000000;
//距离
int graph[1000][1000];
//票价
int price[1000][1000];
//名字和站点映射关系
map<string,int>m;
//两个站的运行时间段                
//从一个点到另一个点的开始时间和结束时间
map<int,map<int,string>>startTime;
map<int,map<int,string>>endTime;

//账户密码
string username = "hyj";
string password = "123";

//插入测试数据
void insert(int a,int b,int c){
    graph[a][b] = graph[b][a] = c;
}

//初始化
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
    //方便数据的测试，手动插入数据
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
//打印floyed路线
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(fpath[a][b])<<"->";
    printfpath(fpath,fpath[a][b],b);
}



//floyd
void floyd(){
  int a,b;
  cout<<"输入两个点:";
  cin>>a>>b;
  if(a < 1 || b < 1 || a > n || b > n){
      cout<<"输入错误"<<endl;
      return;
  }
  if(a == b){
      cout<<"最短路是自己到自己"<<endl;
      return;
  }
  //floyd算法的结果
  vector<vector<int>>f(1000,vector<int>(1000,mx));
  //打印路径
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
  cout<<a<<"到"<<b<<"的最短路长度为"<<f[a][b]<<endl;
  cout<<"路径:"<<endl;
  cout<<a<<"->";
  printfpath(fpath,a,b);
  cout<<b<<endl<<endl;
  
}

//存储tsp路径
int path[1000][1000];
//求tsp
int dp[1000][1000];

//递归打印tsp路径
void tspPrint(int i,int j,vector<int>&v){
   if(path[i][j] < 0)return;
   tspPrint(i - (1 <<(j - 1)),path[i][j],v);
   v.push_back(j);
}

//tsp问题
void tsp(){
  //记录tsp路径的数组
  vector<int>v;
  //floyd算法的结果
  vector<vector<int>>f(1000,vector<int>(1000,mx));
  //打印路径
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
   //dp表示从目的地走到j出发，经过i,走过的路程
   int m = pow(2,n);
   for(int i = 1 ; i< 1000 ; i ++){
       for(int j = 1 ; j < 1000 ; j ++){
           path[i][j] = -1;
           dp[i][j] = mx;
           fpath[i][j] = -1;
       }
   }
   //从一号点走到一号点
   dp[1][1] = 0;
   for(int i = 0 ; i < m ; i ++){
       for(int j = 1 ; j  <= n ; j ++){
           //集合包括目的顶点
           if(i >> (j - 1) & 1 == 0)continue;
           for(int k = 1 ; k <= n ; k ++){
               //从集合里面选出一个数
               if((i - (1 <<(j - 1)))>>(k - 1)& 1){
                  //更新
                  if(graph[j][k] + dp[i-(1 <<(j - 1))][k] < dp[i][j]){
                      dp[i][j] = min(dp[i][j],f[j][k] + dp[i-(1 <<(j - 1))][k]);
                      path[i][j] = k;
                  }

               }
           }
       }
   }
   //现在知道1到各个点的哈密顿回路，然后加上各个点到1的距离
   int ans = mx;
   int idex;
   for(int i = 2 ; i<= n ; i ++){
       if(dp[m - 1][i] + f[i][1] < ans){
          idex = i;
      }
      ans = min(ans,dp[m - 1][i] + f[i][1]);
   }
   cout<<"TSP路径和是:";
   cout<<ans<<endl;
   cout<<"TSP路径是:";
   v.push_back(1);
   tspPrint(m - 1,idex,v);
   v.push_back(1);
   cout<<"TSP路径是:";
   for(int i =0 ; i < v.size()  - 1; i ++){
      int a = v[i];
      int b = v[i + 1];
      cout<<a - 1<<"->";
      //证明a b 两点是通过floyd实现的
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