#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
//存储图
int graph[1000][1000];
//当前图有多少个点
int n;
//将对应的点的名字转换为标号
map<string,int>m; 

//初始化
void init(){
  //刚开始每个点都不相邻
  for(int i = 0 ; i < 1000 ; i ++){
    for(int j = 0 ; j < 1000 ; j ++){
      graph[i][j] = 0;
    }
  }
  int c;
  printf("输入临接点的对数:\n");
  cin>>c;
  while(c --){
    int a,b,d;
    cin>>a>>b>>d;
    graph[a][b] = d;
    graph[b][a] = d;
  }
}
//景点的输出
void outit(){
  for(int i = 0 ; i< n ;i++){
    for(int j= 0 ; j< n ; j++){
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
  for(int i = 0 ; i<n ;i++){
    if(graph[flag][i] !=0)
    printf("jingdian%d lucheng%d\n",i,graph[flag][i]);
  }
}

//景点线路查询
void roadit(int v){
  int vist[10000],dist[10000],path[100000];
  for(int i = 0 ; i <= n ; i ++){
      dist[i] = 10000000000;
      vist[i] = 0;
      path[i] = i;
  }
  dist[v] = 0;
  for(int i = 0 ; i < n ; i ++){
     int mn = 1000000000;
     int index = -1;
     for(int j = 0 ; j < n ; j ++){
         if(vist[j] == 0 && (dist[j] < mn)){
             mn = dist[j];
             index = j;
         }
     }
     if(index == -1)break;
     vist[index] = 1;
     for(int j = 0 ;  j < n ; j ++){
         if(graph[index][j] != 0){
             if(dist[index] + graph[index][j] < dist[j]){
                 dist[j] = dist[index] + graph[index][j];
                 path[j] = index;
             }
         }
     }
  }
  cout<<endl;
  cout<<path[0]<<endl;
  for(int i = 0 ; i < n ; i ++){
      if(i == v){
          cout<<"最短路径长度是0"<<endl;
          cout<<v<<endl;
      }else {
          if(dist[i] == 10000000000 ){
              cout<<"该点和目标点不连通"<<endl;
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




int main(){
  printf("输入景点个数\n");
  cin>>n;
  init();  
  outit();
 // setview();
  roadit(0);
  return 0;
}
