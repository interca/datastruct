#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
 int dp[1000][1000];
//打印路径
int fpath[1000][1000];
using namespace std;
//存储图
int graph[1000][1000];
//当前图有多少个点
int n;
//保留原数组，floyd算法
int f[1000][1000];
//将对应的点的名字转换为标号
map<string,int>m; 
int mx = 100000000;
void insert(int a,int b,int c){
    a --;
    b --;
    graph[a][b] = graph[b][a] = f[a][b] = f[b][a]  = c;
}
//初始化
void init(){
  //刚开始每个点都不相邻
  for(int i = 0 ; i < 1000 ; i ++){
    for(int j = 0 ; j < 1000 ; j ++){
      f[i][j] = mx;
      graph[i][j] = mx;
      if(i == j){
          graph[i][j] = 0;
          f[i][j] = 0;
      }
    }
  }
  int c;
  //printf("输入临接点的对数:\n");
  /**
  cin>>c;
  while(c --){
    int a,b,d;
    cin>>a>>b>>d;
    graph[a][b] = d;
    graph[b][a] = d;
  }
  **/
  n = 7;
  insert(1,2,2);
  insert(1,4,1);
  insert(1,3,4);
  insert(2,5,10);
  insert(2,4,3);
  insert(3,4,2);
  insert(3,6,5);
  insert(4,5,7);
  insert(4,6,8);
  insert(4,7,4);
  insert(5,7,6);
  insert(6,7,1);  
}

//景点的输出
void outit(){
  for(int i = 0 ; i<n ;i++){
    for(int j= 0 ; j<n ; j++){
      printf("%6d" ,graph[i][j]);
    }
    printf("\n");
  }
}
//相邻景点查询
void setview(){
  int flag;
  printf("输入想要查询的景点\n");
  cin>>flag;
  for(int i = 0 ; i< n ;i++){
    if(graph[flag][i] != mx)
    printf("相邻景点为%d 路程是%d\n",i,graph[flag][i]);
  }
}
//景点线路查询
void roadit(int v){
  int vist[10000],dist[10000],path[100000];
  for(int i =0;i<=n;i++){
    dist[i] = mx;
    vist[i] = 0;
    path[i] = i;
  }
  dist[v] = 0;
  for(int i = 0 ; i < n ; i++){
    int mn = 100000000;
    int index = -1;
    for(int j = 0 ; j < n ; j++){
      if(vist[j] == 0 && (dist[j] < mn)){
        mn = dist[j];
        index = j;
      }
    }
    if(index == -1) break;
    vist[index] = 1;
    for(int j = 0 ; j < n ; j++){
      if(graph[index][j] != mx){
        if(dist[index] + graph[index][j] < dist[j]){
          dist[j] = dist[index] + graph[index][j];
          path[j] = index;
        }
      }
    }
  }
  cout<<endl;
  for(int i = 0 ; i< n ; i++){
    if(i == v){
      cout << "最短路径长度是0" <<endl;
      cout << v <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << "该点和目标点不连通" << endl;
        continue;
      }
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
      cout<<endl;
    }
  }
}

//打印floyed路线
void printfpath(int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(a,fpath[a][b]);
    cout<<(fpath[a][b])<<"  ";
    printfpath(fpath[a][b],b);

}
//景点路线综合查询
void roadthem(int a ,int b){
    for(int i = 0 ; i< 1000 ; i ++){
        for(int j = 0;  j< 1000 ; j ++){
            fpath[i][j] = -1;
        }
    }
    for(int k = 0 ; k < n ; k ++){
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if(graph[i][k] + graph[k][j] < graph[i][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    fpath[i][j] = k;
                }
            }
        }
    }
   cout<<"最短路为"<<graph[a][b]<<endl;
   for(int i = 0 ; i < n ; i ++){
       for(int j = 0 ; j < n ; j ++){
           graph[i][j] = f[i][j];
       }
   }
   printf("路径如下:\n");
   cout<<a<<" ";
   printfpath(a,b);
   cout<<b<<endl;
}

//最小生成树
void prime(){
    int dist[1000];
    int vist[1000];
    for(int i =0 ; i < 1000 ; i ++){
        dist[i] = mx;
        vist[i] = 0;
    }
    dist[0] = 0;
    int sum = 0;
    for(int i = 0 ; i< n ; i ++){
        int t = -1;
        for(int j = 0 ; j < n ; j ++){
           if(vist[j] == 0 &&(t == -1 || dist[t] > dist[j])){
               t = j;
           }
        }
        if(dist[t] == mx)break;
        vist[t] = 1;
        for(int j = 0 ; j < n ; j ++){
            if(vist[j] == 0){
                dist[j] = min(dist[j],graph[t][j]);
            }
        }
        sum += dist[t];
    }
    printf("最小生成树的值是:%d\n",sum);
}

//修改景点
void change(){
    int a,b,c;
    printf("输入要修改的景点a和b:\n");
    cin>>a>>b;
    printf("1-修改两点间距离, 2-删除两点间路线\n");
    cin>>c;
    if(c == 1){
        printf("输入修改后距离:\n");
        cin>>c;
        graph[a][b] = graph[b][a] = f[a][b] = f[b][a] = c;
    }else if(c == 2){
        graph[a][b] = graph[b][a] = f[a][b] = f[b][a] = mx;
    }else {
        cout<<"输入错误"<<endl;
    }
}

//加点
void add(){
    n ++;
    printf("添加成功\n");
    for(int i =0 ; i < n ; i ++){
        graph[i][n - 1] = graph[n - 1][i] = f[i][n - 1] = f[n - 1][i] = mx;
        graph[n - 1][n - 1] = f[n - 1][n - 1] = 0;
    }
}

void tsp(){
   //表示经过集合j的点最终回到i，j是二进制表示集合
   int m = pow(2,n) - 1;
   for(int i = 0 ; i< 1000 ; i ++){
       for(int j = 0 ; j < 1000 ; j ++){
           dp[i][j] = mx;
       }
   }
   for(int i = 0 ; i < n ; i++){
       //自己到自己肯定是0
       dp[i][0] = graph[i][0];
   }
   for(int j = 1 ; j < m ; j ++){
       for(int i = 0 ; i  < n ; i ++){
           dp[i][j] = mx;
           //集合不能包括i自己
           if((j >> (i)) & 1 == 1)continue;
           for(int k = 0 ; k < n ; k ++){
               //从集合里面选出一个数
               if((j >> (k)) & 1 == 0)continue;
               //更新
               dp[i][j] = min(dp[i][j],graph[i][k] + dp[k][j^(1 << (k))]);
               if(i == 0 && j <= 2 && dp[i][j] != mx)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
           }
       }
   }
   cout<<dp[0][m - 1]<<endl;
}
//最佳旅游路线确定
//菜单
void menu(){
  int flag;
  printf("--------------------------------------------------------------------------\n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                      欢迎使用本旅游区导游图系统                         \n");
  printf("                                                                      \n");
  printf("                          请选择您需查询的选项                           \n");
  printf("                                                                       \n");
  printf("                            一.景点导游图                               \n");
  printf("                                                                      \n");
  printf("                         二.当前景点的相邻景点                            \n");
  printf("                                                                      \n");
  printf("                       三.当前景点到其他景点做优路线                       \n");
  printf("                                                                      \n");
  printf("                          四.两个景点的最优线路                           \n");
  printf("                                                                      \n");
  printf("                           五.最佳游玩线路推荐                            \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                           六.最小生成树                               \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                           七.修改两点距离                               \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                           八.增加旅游景点                             \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("--------------------------------------------------------------------------\n");

  printf("--------------------------------------------------------------------------\n");
  cout<<endl;
  cout<<endl;
  printf("                           请输入你想要查询的内容\n");
  scanf("%d",&flag);
  printf("--------------------------------------------------------------------------\n");
  switch (flag) {
  case 1:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                                一.景点导游图\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    setview();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");
    break;
  }

  case 2:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                              二.当前景点的相邻景点\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    outit();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");
    break;
  }

  case 3:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                             三.当前景点到其他景点做优路线\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("                              输入要查询的点\n");
    int v;
    scanf("%d" ,&v);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");
    
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                             三.当前景点到其他景点做优路线\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    roadit(v);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");
    break;
  }

  case 4:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                             四.两个景点的最优线路\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("                              输入想要查询的两个景点\n");
    int a,b;
    scanf("%d%d" ,&a,&b);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");


    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                             四.两个景点的最优线路\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    roadthem(a,b);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");
    break;
  }case 5:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                            五.旅行商问题\n");
    printf("--------------------------------------------------------------------------\n");
    tsp();
    cout<<endl;
    cout<<endl;
    break;
  }case 6:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                            六.最小生成树\n");
    prime();
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    break;
  }case 7:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                           七.修改景点\n");
    printf("--------------------------------------------------------------------------\n");
    change();
    cout<<endl;
    cout<<endl;
    break;
  }case 8:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                           八.增加景点\n");
    printf("--------------------------------------------------------------------------\n");
    add();
    cout<<endl;
    cout<<endl;
    break;
  }
  default:
  break;
 }

}
int main(){
  
  int v,a,b;
  printf("输入景点个数\n");
  //cin>>n;
  init();
  while(1){ 
     menu(); 
  }
  return 0;
}
