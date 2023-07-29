#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<fstream>
#include<sstream>
#include <codecvt>
using namespace std;
//站点最大编号
int n;
//站点数量
int cnt;
//是否被删除
int isDelete[2000];
//表示正无穷
int mx = 100000000;
//距离
int graph[2000][2000];
//票价
int price[2000][2000];
//名字和站点映射关系
map<string,int>m;
map<int,string>mp;
//两个站的运行时间段                
//从一个点到另一个点的开始时间和结束时间
map<int,map<int,string>>startTime;
map<int,map<int,string>>endTime;

//账户密码
string username = "hyj";
string password = "123";

//打印图
void printGraph(){
  for(int i = 1 ; i <= n ; i ++){
    for(int j = 1 ; j <= n ; j ++){
       if(graph[i][j] == mx)cout<<-1<<" ";
       else cout<<graph[i][j]<<" ";
    }
    cout<<endl;
  }
}

//插入数据
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
    cnt = 10;
    n = 10;
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
    ifstream infile("graph.txt");
    string line;
    vector<vector<string>> data;

    //读入边
    while (getline(infile, line)) {
        istringstream iss(line);
        vector<string> row;
        string val;
        while (iss >> val) {
            row.push_back(val);
        }
        data.push_back(row);
    }
   
    string line2;
    vector<vector<string>> data2;
    //读入图的映射关系
    ifstream infile2("point.txt");
    infile2.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    while(getline(infile2,line2)){
      istringstream iss(line2);
      vector<string> row;
      string val;
      while (iss >> val) {
        row.push_back(val);
      }
      data2.push_back(row);
    }
    for(auto k : data2){
      int  a = stoi(k[0]);
      string b = k[1];
      m[b] = a;
      mp[a] = b;
    }

    for (auto row : data) {
        int a=stoi(row[0]);
        int b=stoi(row[1]);
        int c=stoi(row[2]);
        int d=stoi(row[3]);
        insert(a,b,c,d,row[4],row[5]);
    }
}
//初始化
/**void init(){
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
    /**insert(1,2,2,2,"00:00:00","23:59:59");
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
    **/


//添加站点
void addStation(){
     string s; 
     cout<<"  输入站点名称:";
     cin>>s;
     cout<<endl;
     if(m[s] != 0){
       cout<<"改点已经存在"<<endl;
     }
     n ++;
     for(int i = 1 ; i <= n ; i ++){
         graph[i][n] = mx;
         graph[n][i] = mx;
     }
     graph[n][n] = 0;
     cout<<"      添加成功"<<endl;
  }

//删除站点
void deleteStation(){
  int s;
  cout<<"  输入要删除的站点: ";
  cin>>s;
  if(s <= 0 || s > n){
    cout<<"站点不存在"<<endl;
    return;
  }
  int g[100][100];
  for(int  i = 1 ; i <= n ; i ++){
    for(int j = 1 ; j <= n ; j ++){
      g[i][j] = graph[i][j];
    }
  }
  for(int i = 1 ; i <= n ; i ++){
    for(int j = 1 ; j <= n ; j ++){
        int a = i;
        int b = j;
        if(a >= s)a ++;
        if(b >= s)b ++;
        graph[i][j] = graph[i][j] = g[a][b];
    }
  }
  n --;
}

//更新距离
void changeDist(){
   cout<<"      输入站点的信息:起点和终点,要更新的距离:"<<endl;
   string start,end;
   int t;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      距离:";
   cin>>t;
   int x = m[start];
   int y = m[end];
   if(x == 0 || y == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       graph[x][y] = t;
       graph[y][x] = t;
       cout<<"      更新成功"<<endl;
   }
}

//更新票价
void changePrice(){
   cout<<"      输入站点的信息:起点,终点,要更新票价:"<<endl;
  string start,end;
   int t;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      票价:";
   cin>>t;
   int x = m[start];
   int y = m[end];
   if(x == 0 || y == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       price[x][y] = t;
       price[y][x] = t;
       cout<<"      更新成功"<<endl;
   }
}

//更新运营时间
void changeStartTime(){
   cout<<"      输入站点的信息:起点,终点,起始时间:"<<endl;
   string start,end;
   int t;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      时间:";
   cin>>t;
   int x = m[start];
   int y = m[end];
   if(x == 0 || y == 0){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       startTime[x][y] = t;
       startTime[y][x] = t;
       cout<<"      更新成功"<<endl;
   }
}


//更新结束时间
void changeEndTime(){
   cout<<"      输入站点的信息:起点,终点,结束时间:"<<endl;
   int start,end,time;
   cout<<"      起点:";
   cin>>start;
   cout<<endl;
   cout<<"      终点:";
   cin>>end;
   cout<<endl;
   cout<<"      时间:";
   cin>>time;
   if(start < 0 || end > n){
       cout<<"      起点或者终点不存在"<<endl;
   }else {
       int x = start;
       int y = end;
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
    cout<<"      1-增加站点     2-修改线路距离   3-修改线路票价  4-修改线路起始时间  5-更新路线的结束时间  6-打印整个路线    7-退出 "<<endl<<endl;
    cin>>choice;
    switch (choice){
        case 1:
          addStation();
          break;
        case 2:
          changeDist();
          break;
        case 3:
          changePrice();
          break;
        case 4:
          changeStartTime();
          break; 
        case 5:
          changeEndTime();
          break;
        case 6:
          printGraph();
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

//当前站点的临接点及其距离
void prinfAll(){
  cout<<"输入当前站点:";
  string s;
  cin>>s;
  if(m[s] == 0){
    cout<<"不存在这个站点"<<endl;
    return;
  }
  cout<<endl;
  int v = m[s];
  if(v < 1 || v > n){
    cout<<"输入有误"<<endl;
    return;
  }
  cout<<"站点"<<s<<"的临接点有:"<<endl;
  for(int i = 1 ; i <= n ; i ++){
        if(graph[v][i] < mx && i != v)
        cout<<mp[i]<<",距离是"<<graph[v][i]<<endl;
  }
  cout<<endl<<endl;
}

//距离最短路
void dijkstra(){
  cout<<"输入当前站点:";
  string s;
  cin>>s;
  if(m[s] == 0){
    cout<<"不存在这个站点"<<endl;
    return;
  }
  int v = m[s];
  cout<<endl;
 
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
      cout<<"站点"<<mp[v]<<endl;
      cout << "最短路径长度是0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << mp[i]<<"和目标点不连通" << endl;
        continue;
      }
      cout<<"站点"<<mp[i]<<endl;
      cout<<"最短路长度是:"<<dist[i]<<endl;
      vector<int>num;
      int index = i;
      num.push_back(index);
      while(path[index] != index){
        num.push_back(path[index]);
        index = path[index];
      }
      for(int j = num.size() - 1 ; j >= 0 ; j --){
        cout<<mp[num[j]]<<" ";
         if(j != 0)cout<<"->";
      }
      cout<<endl<<endl;;
    }
  }

}

//打印floyed路线
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(mp[fpath[a][b]])<<"->";
    printfpath(fpath,fpath[a][b],b);
}



//floyd
void floyd(){
  string s1,s2;
  int a,b;
  cout<<"输入两个点:";
  cin>>s1>>s2;
  a = m[s1];
  b = m[s2];
  if(a == 0 || b == 0){
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
  cout<<s1<<"到"<<s2<<"的最短路长度为"<<f[a][b]<<endl;
  cout<<"路径:"<<endl;
  cout<<s1<<"->";
  printfpath(fpath,a,b);
  cout<<s2<<endl<<endl;
  
}


//最少价格
void dijkstra2(){
   cout<<"输入当前站点:";
  string s;
  cin>>s;
  if(m[s] == 0){
    cout<<"不存在这个站点"<<endl;
    return;
  }
  int v = m[s];
  cout<<endl;
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
      cout<<"站点"<<mp[v]<<endl;
      cout << "最少花费是0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout <<mp[i]<<"和目标点不连通" << endl;
        continue;
      }
      cout<<"站点"<<mp[i]<<endl;
      cout<<"最少花费是:"<<dist[i]<<endl;
      vector<int>num;
      int index = i;
      num.push_back(index);
      while(path[index] != index){
        num.push_back(path[index]);
        index = path[index];
      }
      for(int j = num.size() - 1 ; j >= 0 ; j --){
        cout<<mp[num[j]];
        if(j != 0)cout<<"->";
      }
      cout<<endl<<endl;
    }
  }
}

//任意两个站点的价格
void floyd2(){
  string s1,s2;
  int a,b;
  cout<<"输入两个点:";
  cin>>s1>>s2;
  a = m[s1];
  b = m[s2];
  if(a == 0 || b == 0){
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
  cout<<s1<<"到"<<s2<<"的最少花费为"<<f[a][b]<<endl;
  cout<<"路径:"<<endl;
  cout<<s1<<"->";
  printfpath(fpath,a,b);
  cout<<s2<<endl<<endl;
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
    for(int i = 0 ; i< n; i ++){
        //cout<<i<<endl;
        int t = -1;
        //找到距离生成树最近的点
        for(int j = 1 ; j <= n ; j ++){
           if(vist[j] == 0 &&(t == -1 || dist[t] > dist[j])){
               t = j;
           }
        }
        if(t == -1 || dist[t] == mx){
          cout<<"不能构成最小生成树"<<endl;
          return;
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

//存储tsp路径
int path[2000][2000];
//求tsp  //表示从起点出发，经过i状态的城市,到达j点的最短路
int dp[2000][2000];

//递归打印tsp路径
void tspPrint(int i,int j,vector<int>&v){
   if(path[i][j] < 0)return;
   tspPrint(i - (1 <<(j - 1)),path[i][j],v);
   v.push_back(j);
}

//tsp问题
void tsp(){
  string s;
  int w;
  cout<<"输入起始位置:";
  cin>>s;
  cout<<endl;
  w = m[s];
  if(w == 0){
    cout<<"没有这个点"<<endl;
    return;
  }
  //记录tsp路径的数组
  vector<int>v;
  //floyd算法的结果
  vector<vector<int>>f(2000,vector<int>(2000,mx));
  //打印路径
  vector<vector<int>>fpath(2000,vector<int>(2000,mx));
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
   for(int i = 1 ; i< 2000 ; i ++){
       for(int j = 1 ; j < 2000 ; j ++){
           path[i][j] = -1;
           dp[i][j] = mx;
       }
   }
   //从一号点走到一号点
   dp[1 << (w - 1)][w] = 0;
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
       if(dp[m - 1][i] + f[i][w] < ans){
          idex = i;
      }
      ans = min(ans,dp[m - 1][i] + f[i][w]);
   }
   m;
   ;
   dp[m-1][5];
   cout<<"TSP路径和是:";
   cout<<ans<<endl;
   cout<<"TSP路径是:";
   v.push_back(w);
   tspPrint(m - 1,idex,v);
   v.push_back(w);
   cout<<"TSP路径是:";
   cout<<endl;
   for(int i =0 ; i < v.size()  - 1; i ++){
      int a = v[i];
      int b = v[i + 1];
      cout<<mp[a]<<"->";
      //证明a b 两点是通过floyd实现的
      if(graph[a][b] > f[a][b]){
         printfpath(fpath,a,b);
      }
      if(i == v.size() - 2){
          cout<<mp[b]<<endl;
      }
   }
   cout<<endl<<endl;
}





int mn = mx;
void dfs(vector<int>num,vector<vector<int>>&v,int x,int t,int sum,vector<int>&vist){
   if(x == t){
     num.push_back(x);
     num.push_back(sum);
     v.push_back(num);
     mn = min(mn,sum);
     return;
   }
   num.push_back(x);
   for(int i = 1 ; i <= n ; i ++){
      if(vist[i] == 0 && graph[x][i] != mx){
        vist[i] = 1;
        dfs(num,v,i,t,sum + graph[x][i],vist);
        vist[i] = 0;
      }
   }
}

//寻找两个点的最优路线和全部线路
void findAllRotue(){
   string s1,s2;
   mn = mx;
   vector<int>vist(1000,0);
   int a,b;
   cout<<"输入起点:";
   cout<<endl;
   cin>>s1;
   cout<<"输入终点:";
   cout<<endl;
   cin>>s2;
   vector<vector<int>>v;
   vector<int>num;
   a = m[s1];
   b = m[s2];
   int ide;
   vist[a] = 1;
   dfs(num,v,a,b,0,vist);

   for(int k = 0 ; k < v.size() ; k ++){
      auto w = v[k];
      for(int i = 0 ;i < w.size() - 1 ; i ++){
        cout<<mp[w[i]];
        if(i != w.size() - 2)cout<<"-->";
      }
      cout<<endl;
      if(w[w.size() - 1] == mn){
        ide = k; 
      }
   }
    cout<<endl;
    cout<<"最短路是:"<<mn<<endl;
    cout<<"最优路径是:"<<endl;
    for(int i = 0 ; i < v[ide].size() - 1 ; i ++){
        cout<<mp[v[ide][i]];
         if(i != v[ide].size() - 2)cout<<"-->";
    }
    cout<<endl<<endl;;
}

//用户模式
void user(){  
    cout<<"                              ------------ 用户模式 -------------            "<<endl<<endl;
    int choice;
    int f = 1;
    while(f){
        cout<<"  1-当前站点相邻车座和距离  2-求到目的地最短路  3-求任意两个点的最短路  4-求到目的地最少花费  5-求任意两个地点的最短花费 6-最小生成树   7-tsp    8-打印整个地铁  9-展示两个站点全部路线 10-退出"<<endl;
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
              printGraph();
              break;
            case 9:
              findAllRotue();
              break;  
            case 10:
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

