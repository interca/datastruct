#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
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
void insert(int a,int b,int c,int p,string start,string end){
    graph[a][b] = graph[b][a] = c;
    price[a][b] = price[b][a] = p;
    startTime[a][b] = start;
    startTime[b][a] = start;
    endTime[a][b] = end;
    endTime[b][a] = end;
}

//初始化
void init(){
    cnt = 7;
    n = 7;
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
    insert(1,2,2,2,"00:00:00","23:59:59");
    insert(1,4,1,1,"00:00:00","23:59:59");
    insert(1,3,4,4,"00:00:00","23:59:59");
    insert(2,5,10,10,"00:00:00","23:59:59");
    insert(2,4,3,3,"00:00:00","23:59:59");
    insert(3,4,2,2,"00:00:00","23:59:59");
    insert(3,6,5,5,"00:00:00","23:59:59");
    insert(4,5,7,7,"00:00:00","23:59:59");
    insert(4,6,8,8,"00:00:00","23:59:59");
    insert(4,7,4,4,"00:00:00","23:59:59");
    insert(5,7,6,6,"00:00:00","23:59:59");
    insert(6,7,1,1,"00:00:00","23:59:59");  
}

//添加站点
void addStation(){
  string s;
  cout<<"      输入要添加的站点名称: ";
  cin>>s;
  if(m.count(s) && isDelete[m[s]] == 0){
      cout<<"      该站点已经存在"<<endl;
  }else {
     n ++;
     cnt ++;
     for(int i = 1 ; i <= n ; i ++){
         graph[i][n] = mx;
         graph[n][i] = mx;
     }
     m[s] = n;
     graph[n][n] = 0;
     cout<<"      添加成功"<<endl;
  }
}

//删除站点
void deleteStation(){
  string s;
  cout<<"      输入要删除的站点名称: ";
  cin>>s;
  if(m.count(s) == 0 || isDelete[m[s]] == 1){
      cout<<"     该站点已经不存在"<<endl;
  }else {
      m[s] = 0;
      isDelete[m[s]] = 1;
      if(m[s] == n)n --;
      cnt --;
      cout<<"     删除成功"<<endl;
  }
}

//更新距离
void changeDist(){
   cout<<"      输入站点的信息:起点名称,终点名称,要更新的距离:"<<endl;
   string start,end;
   int distant;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      距离:";
   cin>>distant;
   //cout<<start<<"  "<<end<<endl;
   //cout<<m[start]<<" "<<m[end]<<endl;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       graph[x][y] = graph[y][x] = distant;
       cout<<"      更新成功"<<endl;
       //cout<<start<<"  "<<end<<endl;
       //cout<<m[start]<<" "<<m[end]<<endl;
   }
}

//更新票价
void changePrice(){
   cout<<"      输入站点的信息:起点名称,终点名称,要更新票价:"<<endl;
   string start,end;
   int p;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      票价:";
   cin>>p;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       price[x][y] = price[y][x] = p;
       cout<<"      更新成功"<<endl;
   }
}

//更新运营时间
void changeStartTime(){
   cout<<"      输入站点的信息:起点名称,终点名称,起始时间:"<<endl;
   string start,end,time;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      时间:";
   cin>>time;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       startTime[x][y] = time;
       startTime[y][x] = time;
       cout<<"      更新成功"<<endl;
   }
}


//更新结束时间
void changeEndTime(){
   cout<<"      输入站点的信息:起点名称,终点名称,结束时间:"<<endl;
   string start,end,time;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      时间:";
   cin>>time;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       startTime[x][y] = time;
       startTime[y][x] = time;
       cout<<"      更新成功"<<endl;
   }
}
//管理员模式
void admin(){
  string u;
  string p;
  int choice;
  int f = 1;
  //验证账户密码的正确性
  while(1){
    cout<<"               1-输入账户密码     2-退出"<<endl;
    cin>>choice;
    if(choice == 1){
      cout<<"               账户:";
      cin>>u;
      cout<<endl;
      cout<<"               密码:";
      cin>>p;
      cout<<endl;
      if((u == username && p == password))break;
      else cout<<"              账户或者密码错误       "<<endl;
    }else  if(choice == 2){
       return;
    } else {
        cout<<"      输入错误,请重新输入!"<<endl;
    }
  }

  cout<<"               登录成功!"<<endl<<endl;
  cout<<"                         ------------ 管理员后台系统 ----------- "<<endl<<endl;
  while(f){
    cout<<"      1-增加站点    2-删除站点    3-修改线路距离   4-修改线路票价  5-修改线路起始时间  6-更新路线的结束时间  7-退出 "<<endl<<endl;
    cin>>choice;
    switch (choice){
        case 1:
          addStation();
          break;
        case 2:
          deleteStation();
          break;
        case 3:
          changeDist();
          break;
        case 4:
          changePrice();
          break;
        case 5:
          changeStartTime();
          break; 
        case 6:
          changeEndTime();
          break;
        case 7:
          f = 0;
          break;  
        default:
          cout<<"                         输入错误,请重新输入"<<endl;
          break;           
    }
  }
}

//打印每个点的临接点及其距离
void prinfAll(){
  for(int i = 1 ; i <= n ; i ++){
      if(isDelete[i] == 0){
          cout<<"站点"<<i<<"的临接站点有:"<<endl;
          for(int j =1 ; j <= n ; j ++){
              if(isDelete[j] == 0 && graph[i][j] != mx && i != j){
                  cout<<j<<",距离是"<<graph[i][j]<<endl;
              }
          }
      }
  }
}

//距离最短路
void dijkstra(){
  cout<<" 请输入站点:";
  int v;
  cin>>v;
  cout<<endl;
  if(v > n || v <= 0){
      cout<<"输入不合法"<<endl;
      return;
  }
  //距离数组
  int dist[1000];
  //路径数组
  int path[1000];
  //是否被访问过
  int vist[1000];
  for(int i = 0 ; i< 1000 ; i ++){
      dist[i] = mx;
      path[i] = i;
      vist[i] = 0;
  }
  dist[v] = 0;
  for(int i = 0 ; i < cnt ; i  ++){
      int t = -1;
      for(int j = 1 ; j <= n ; j ++){
          if(isDelete[j] == 0 && vist[j] == 0 &&(t == -1 || dist[j] < dist[t])){
              t = j;
          }
      }
      if(t == -1)break;
      vist[t] = 1;
      for(int j = 1;  j <= n ; j ++){
         if(isDelete[j] == 0 && graph[t][j] != mx && dist[j] > graph[t][j] + dist[t]){
             dist[j] = graph[t][j] + dist[t];
             //记录上一个点是哪一个
             path[j] = t;
         }
      }
  }

  cout<<endl;
  for(int i = 1 ; i<= n ; i++){
    if(isDelete[i] == 1)continue;
    if(i == v){
      cout<<"站点"<<v<<endl;
      cout << "最短路径长度是0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << i<<"和目标点不连通" << endl;
        continue;
      }
      cout<<"站点"<<i<<endl;
      cout<<"最短路长度是:"<<dist[i]<<endl;
      vector<int>num;
      int index = i;
      num.push_back(index);
      while(path[index] != index){
        num.push_back(path[index]);
        index = path[index];
      }
      for(int j = num.size() - 1 ; j >= 0 ; j --){
        cout<<num[j]<<" ";
      }
      cout<<endl<<endl;;
    }
  }

}

//打印floyed路线
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(fpath[a][b])<<" ";
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
  cout<<a<<" ";
  printfpath(fpath,a,b);
  cout<<b<<endl<<endl;
  
}


//最少价格
void dijkstra2(){
  cout<<" 请输入站点:";
  int v;
  cin>>v;
  cout<<endl;
  if(v > n || v <= 0){
      cout<<"输入不合法"<<endl;
      return;
  }
  //距离数组
  int dist[1000];
  //路径数组
  int path[1000];
  //是否被访问过
  int vist[1000];
  for(int i = 0 ; i< 1000 ; i ++){
      dist[i] = mx;
      path[i] = i;
      vist[i] = 0;
  }
  dist[v] = 0;
  for(int i = 0 ; i < cnt ; i  ++){
      int t = -1;
      for(int j = 1 ; j <= n ; j ++){
          if(isDelete[j] == 0 && vist[j] == 0 &&(t == -1 || dist[j] < dist[t])){
              t = j;
          }
      }
      if(t == -1)break;
      vist[t] = 1;
      for(int j = 1;  j <= n ; j ++){
         if(isDelete[j] == 0 && price[t][j] != mx && dist[j] > price[t][j] + dist[t]){
             dist[j] = price[t][j] + dist[t];
             //记录上一个点是哪一个
             path[j] = t;
         }
      }
  }

  cout<<endl;
  for(int i = 1 ; i<= n ; i++){
    if(isDelete[i] == 1)continue;
    if(i == v){
      cout<<"站点"<<v<<endl;
      cout << "最少花费是0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << i<<"和目标点不连通" << endl;
        continue;
      }
      cout<<"站点"<<i<<endl;
      cout<<"最少花费是:"<<dist[i]<<endl;
      vector<int>num;
      int index = i;
      num.push_back(index);
      while(path[index] != index){
        num.push_back(path[index]);
        index = path[index];
      }
      for(int j = num.size() - 1 ; j >= 0 ; j --){
        cout<<num[j]<<" ";
      }
      cout<<endl<<endl;
    }
  }
}

//任意两个站点的价格
void floyd2(){
   int a,b;
  cout<<"输入两个点:";
  cin>>a>>b;
  if(a < 1 || b < 1 || a > n || b > n){
      cout<<"输入错误"<<endl;
      return;
  }
  if(a == b){
      cout<<"最少花费是0"<<endl;
      return;
  }
  //floyd算法的结果
  vector<vector<int>>f(1000,vector<int>(1000,mx));
  //打印路径
  vector<vector<int>>fpath(1000,vector<int>(1000,mx));
  for(int i = 1 ; i <= n ; i ++){
      for(int j = 1 ; j <= n ; j ++){
          f[i][j] = price[i][j];
          fpath[i][j] = -1;
      }
  }
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
  cout<<a<<"到"<<b<<"的最少花费为"<<f[a][b]<<endl;
  cout<<"路径:"<<endl;
  cout<<a<<" ";
  printfpath(fpath,a,b);
  cout<<b<<endl<<endl;
}

//最小生成树
void prime(){
    int dist[1000];
    int vist[1000];
    for(int i =0 ; i < 1000 ; i ++){
        dist[i] = mx;
        vist[i] = 0;
    }
    dist[1] = 0;
    int sum = 0;
    for(int i = 0 ; i< cnt; i ++){
        cout<<i<<endl;
        int t = -1;
        //找到距离生成树最近的点
        for(int j = 1 ; j <= n ; j ++){
           if(vist[j] == 0 &&(t == -1 || dist[t] > dist[j])){
               t = j;
           }
        }
        if(dist[t] == mx)break;
        //加入生成树
        vist[t] = 1;
        //更新其所有为加入生成树的临接点的距离
        for(int j = 1 ; j <= n ; j ++){
            if(vist[j] == 0){
                dist[j] = min(dist[j],graph[t][j]);
            }
        }
        sum += dist[t];
    }
    printf("最小生成树的值是:%d\n",sum);
}

int dp[1000][1000];
//tsp问题
void tsp(){
   //dp表示从i出发，经过其余顶点j,，最终回到原点的距离
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
           if(isDelete[i] == 1)continue;
           dp[i][j] = mx;
           //集合不能包括i自己
           if((j >> (i - 1)) & 1 == 1)continue;
           for(int k = 1 ; k <= n ; k ++){
               if(isDelete[k] == 1)continue;
               //从集合里面选出一个数
               if((j >> (k - 1)) & 1 == 0)continue;
               //更新
               dp[i][j] = min(dp[i][j],graph[i][k] + dp[k][j^(1 << (k - 1))]);
           }
       }
   }
   cout<<dp[1][m - 1]<<endl;
}

//用户模式
void user(){  
    cout<<"                              ------------ 用户模式 -------------            "<<endl<<endl;
    int choice;
    int f = 1;
    while(f){
        cout<<"  1-每个站点的相邻车座和距离  2-求到目的地最短路  3-求任意两个点的最短路  4-求到目的地最少花费  5-求任意两个地点的最短花费   6-最小生成树  7-tsp"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
              prinfAll();
              break;
            case 2:  
              dijkstra();
              break;
            case 3:
              floyd();
              break;
            case 4:
              dijkstra2();
              break;  
            case 5:
              floyd2();
              break;
            case 6:
              prime();
              break;
            case 7:
              tsp();
              break;
            case 8: 
              f = 0;
              break;
            default:
               cout<<"  输入错误"<<endl;  
       }
    }
}

int main(){
  init();
  int choice;
  int f = 1;
  while(f){
    cout<<" -------------- 欢迎进入城市交通管理系统 ---------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"        请选择进入系统的模式: 1-管理员   2-用户  3-退出 "<<endl;;
    cin>>choice;
    cout<<endl<<endl;
    switch (choice){
        case 1 :
          admin();
          break;
        case 2 :
          user();
          break;
        case 3 :
          f = 0;
          break;
        default :
          cout<<"输入错误,请重新输入"<<endl;
          break;  
    }
  }
  return 0;
}

