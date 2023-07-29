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
//վ�������
int n;
//վ������
int cnt;
//�Ƿ�ɾ��
int isDelete[2000];
//��ʾ������
int mx = 100000000;
//����
int graph[2000][2000];
//Ʊ��
int price[2000][2000];
//���ֺ�վ��ӳ���ϵ
map<string,int>m;
map<int,string>mp;
//����վ������ʱ���                
//��һ���㵽��һ����Ŀ�ʼʱ��ͽ���ʱ��
map<int,map<int,string>>startTime;
map<int,map<int,string>>endTime;

//�˻�����
string username = "hyj";
string password = "123";

//��ӡͼ
void printGraph(){
  for(int i = 1 ; i <= n ; i ++){
    for(int j = 1 ; j <= n ; j ++){
       if(graph[i][j] == mx)cout<<-1<<" ";
       else cout<<graph[i][j]<<" ";
    }
    cout<<endl;
  }
}

//��������
void insert(int a,int b,int c,int p,string start,string end){
    graph[a][b] = graph[b][a] = c;
    price[a][b] = price[b][a] = p;
    startTime[a][b] = start;
    startTime[b][a] = start;
    endTime[a][b] = end;
    endTime[b][a] = end;
}

//��ʼ��
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

    //�����
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
    //����ͼ��ӳ���ϵ
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
//��ʼ��
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
    //�������ݵĲ��ԣ��ֶ���������
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


//���վ��
void addStation(){
     string s; 
     cout<<"  ����վ������:";
     cin>>s;
     cout<<endl;
     if(m[s] != 0){
       cout<<"�ĵ��Ѿ�����"<<endl;
     }
     n ++;
     for(int i = 1 ; i <= n ; i ++){
         graph[i][n] = mx;
         graph[n][i] = mx;
     }
     graph[n][n] = 0;
     cout<<"      ��ӳɹ�"<<endl;
  }

//ɾ��վ��
void deleteStation(){
  int s;
  cout<<"  ����Ҫɾ����վ��: ";
  cin>>s;
  if(s <= 0 || s > n){
    cout<<"վ�㲻����"<<endl;
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

//���¾���
void changeDist(){
   cout<<"      ����վ�����Ϣ:�����յ�,Ҫ���µľ���:"<<endl;
   string start,end;
   int t;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      ����:";
   cin>>t;
   int x = m[start];
   int y = m[end];
   if(x == 0 || y == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       graph[x][y] = t;
       graph[y][x] = t;
       cout<<"      ���³ɹ�"<<endl;
   }
}

//����Ʊ��
void changePrice(){
   cout<<"      ����վ�����Ϣ:���,�յ�,Ҫ����Ʊ��:"<<endl;
  string start,end;
   int t;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      Ʊ��:";
   cin>>t;
   int x = m[start];
   int y = m[end];
   if(x == 0 || y == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       price[x][y] = t;
       price[y][x] = t;
       cout<<"      ���³ɹ�"<<endl;
   }
}

//������Ӫʱ��
void changeStartTime(){
   cout<<"      ����վ�����Ϣ:���,�յ�,��ʼʱ��:"<<endl;
   string start,end;
   int t;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      ʱ��:";
   cin>>t;
   int x = m[start];
   int y = m[end];
   if(x == 0 || y == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       startTime[x][y] = t;
       startTime[y][x] = t;
       cout<<"      ���³ɹ�"<<endl;
   }
}


//���½���ʱ��
void changeEndTime(){
   cout<<"      ����վ�����Ϣ:���,�յ�,����ʱ��:"<<endl;
   int start,end,time;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      ʱ��:";
   cin>>time;
   if(start < 0 || end > n){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       int x = start;
       int y = end;
       startTime[x][y] = time;
       startTime[y][x] = time;
       cout<<"      ���³ɹ�"<<endl;
   }
}
//����Աģʽ
void admin(){
  string u;
  string p;
  int choice;
  int f = 1;
  //��֤�˻��������ȷ��
  while(1){
    cout<<"               1-�����˻�����     2-�˳�"<<endl;
    cin>>choice;
    if(choice == 1){
      cout<<"               �˻�:";
      cin>>u;
      cout<<endl;
      cout<<"               ����:";
      cin>>p;
      cout<<endl;
      if((u == username && p == password))break;
      else cout<<"              �˻������������       "<<endl;
    }else  if(choice == 2){
       return;
    } else {
        cout<<"      �������,����������!"<<endl;
    }
  }

  cout<<"               ��¼�ɹ�!"<<endl<<endl;
  cout<<"                         ------------ ����Ա��̨ϵͳ ----------- "<<endl<<endl;
  while(f){
    cout<<"      1-����վ��     2-�޸���·����   3-�޸���·Ʊ��  4-�޸���·��ʼʱ��  5-����·�ߵĽ���ʱ��  6-��ӡ����·��    7-�˳� "<<endl<<endl;
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
          cout<<"                         �������,����������"<<endl;
          break;           
    }
  }
}

//��ǰվ����ٽӵ㼰�����
void prinfAll(){
  cout<<"���뵱ǰվ��:";
  string s;
  cin>>s;
  if(m[s] == 0){
    cout<<"���������վ��"<<endl;
    return;
  }
  cout<<endl;
  int v = m[s];
  if(v < 1 || v > n){
    cout<<"��������"<<endl;
    return;
  }
  cout<<"վ��"<<s<<"���ٽӵ���:"<<endl;
  for(int i = 1 ; i <= n ; i ++){
        if(graph[v][i] < mx && i != v)
        cout<<mp[i]<<",������"<<graph[v][i]<<endl;
  }
  cout<<endl<<endl;
}

//�������·
void dijkstra(){
  cout<<"���뵱ǰվ��:";
  string s;
  cin>>s;
  if(m[s] == 0){
    cout<<"���������վ��"<<endl;
    return;
  }
  int v = m[s];
  cout<<endl;
 
  //��������
  int dist[1000];
  //·������
  int path[1000];
  //�Ƿ񱻷��ʹ�
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
             //��¼��һ��������һ��
             path[j] = t;
         }
      }
  }

  cout<<endl;
  for(int i = 1 ; i<= n ; i++){
    if(isDelete[i] == 1)continue;
    if(i == v){
      cout<<"վ��"<<mp[v]<<endl;
      cout << "���·��������0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << mp[i]<<"��Ŀ��㲻��ͨ" << endl;
        continue;
      }
      cout<<"վ��"<<mp[i]<<endl;
      cout<<"���·������:"<<dist[i]<<endl;
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

//��ӡfloyed·��
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
  cout<<"����������:";
  cin>>s1>>s2;
  a = m[s1];
  b = m[s2];
  if(a == 0 || b == 0){
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
  cout<<s1<<"��"<<s2<<"�����·����Ϊ"<<f[a][b]<<endl;
  cout<<"·��:"<<endl;
  cout<<s1<<"->";
  printfpath(fpath,a,b);
  cout<<s2<<endl<<endl;
  
}


//���ټ۸�
void dijkstra2(){
   cout<<"���뵱ǰվ��:";
  string s;
  cin>>s;
  if(m[s] == 0){
    cout<<"���������վ��"<<endl;
    return;
  }
  int v = m[s];
  cout<<endl;
  //��������
  int dist[1000];
  //·������
  int path[1000];
  //�Ƿ񱻷��ʹ�
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
             //��¼��һ��������һ��
             path[j] = t;
         }
      }
  }

  cout<<endl;
  for(int i = 1 ; i<= n ; i++){
    if(isDelete[i] == 1)continue;
    if(i == v){
      cout<<"վ��"<<mp[v]<<endl;
      cout << "���ٻ�����0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout <<mp[i]<<"��Ŀ��㲻��ͨ" << endl;
        continue;
      }
      cout<<"վ��"<<mp[i]<<endl;
      cout<<"���ٻ�����:"<<dist[i]<<endl;
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

//��������վ��ļ۸�
void floyd2(){
  string s1,s2;
  int a,b;
  cout<<"����������:";
  cin>>s1>>s2;
  a = m[s1];
  b = m[s2];
  if(a == 0 || b == 0){
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
  cout<<s1<<"��"<<s2<<"�����ٻ���Ϊ"<<f[a][b]<<endl;
  cout<<"·��:"<<endl;
  cout<<s1<<"->";
  printfpath(fpath,a,b);
  cout<<s2<<endl<<endl;
}

//��С������
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
        //�ҵ���������������ĵ�
        for(int j = 1 ; j <= n ; j ++){
           if(vist[j] == 0 &&(t == -1 || dist[t] > dist[j])){
               t = j;
           }
        }
        if(t == -1 || dist[t] == mx){
          cout<<"���ܹ�����С������"<<endl;
          return;
        }
        if(dist[t] == mx)break;
        //����������
        vist[t] = 1;
        //����������Ϊ�������������ٽӵ�ľ���
        for(int j = 1 ; j <= n ; j ++){
            if(vist[j] == 0){
                dist[j] = min(dist[j],graph[t][j]);
            }
        }
        sum += dist[t];
    }
    printf("��С��������ֵ��:%d\n",sum);
}

//�洢tsp·��
int path[2000][2000];
//��tsp  //��ʾ��������������i״̬�ĳ���,����j������·
int dp[2000][2000];

//�ݹ��ӡtsp·��
void tspPrint(int i,int j,vector<int>&v){
   if(path[i][j] < 0)return;
   tspPrint(i - (1 <<(j - 1)),path[i][j],v);
   v.push_back(j);
}

//tsp����
void tsp(){
  string s;
  int w;
  cout<<"������ʼλ��:";
  cin>>s;
  cout<<endl;
  w = m[s];
  if(w == 0){
    cout<<"û�������"<<endl;
    return;
  }
  //��¼tsp·��������
  vector<int>v;
  //floyd�㷨�Ľ��
  vector<vector<int>>f(2000,vector<int>(2000,mx));
  //��ӡ·��
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
   //dp��ʾ��Ŀ�ĵ��ߵ�j����������i,�߹���·��
   int m = pow(2,n);
   for(int i = 1 ; i< 2000 ; i ++){
       for(int j = 1 ; j < 2000 ; j ++){
           path[i][j] = -1;
           dp[i][j] = mx;
       }
   }
   //��һ�ŵ��ߵ�һ�ŵ�
   dp[1 << (w - 1)][w] = 0;
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
       if(dp[m - 1][i] + f[i][w] < ans){
          idex = i;
      }
      ans = min(ans,dp[m - 1][i] + f[i][w]);
   }
   m;
   ;
   dp[m-1][5];
   cout<<"TSP·������:";
   cout<<ans<<endl;
   cout<<"TSP·����:";
   v.push_back(w);
   tspPrint(m - 1,idex,v);
   v.push_back(w);
   cout<<"TSP·����:";
   cout<<endl;
   for(int i =0 ; i < v.size()  - 1; i ++){
      int a = v[i];
      int b = v[i + 1];
      cout<<mp[a]<<"->";
      //֤��a b ������ͨ��floydʵ�ֵ�
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

//Ѱ�������������·�ߺ�ȫ����·
void findAllRotue(){
   string s1,s2;
   mn = mx;
   vector<int>vist(1000,0);
   int a,b;
   cout<<"�������:";
   cout<<endl;
   cin>>s1;
   cout<<"�����յ�:";
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
    cout<<"���·��:"<<mn<<endl;
    cout<<"����·����:"<<endl;
    for(int i = 0 ; i < v[ide].size() - 1 ; i ++){
        cout<<mp[v[ide][i]];
         if(i != v[ide].size() - 2)cout<<"-->";
    }
    cout<<endl<<endl;;
}

//�û�ģʽ
void user(){  
    cout<<"                              ------------ �û�ģʽ -------------            "<<endl<<endl;
    int choice;
    int f = 1;
    while(f){
        cout<<"  1-��ǰվ�����ڳ����;���  2-��Ŀ�ĵ����·  3-����������������·  4-��Ŀ�ĵ����ٻ���  5-�����������ص����̻��� 6-��С������   7-tsp    8-��ӡ��������  9-չʾ����վ��ȫ��·�� 10-�˳�"<<endl;
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
               cout<<"  �������"<<endl;  
       }
    }
}

int main(){
  init();
  int choice;
  int f = 1;
  while(f){
    cout<<" -------------- ��ӭ������н�ͨ����ϵͳ ---------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"        ��ѡ�����ϵͳ��ģʽ: 1-����Ա   2-�û�  3-�˳� "<<endl;;
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
          cout<<"�������,����������"<<endl;
          break;  
    }
  }
  return 0;
}

