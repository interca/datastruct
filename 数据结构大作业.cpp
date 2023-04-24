#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
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

//���վ��
void addStation(){
  string s;
  cout<<"      ����Ҫ��ӵ�վ������: ";
  cin>>s;
  if(m.count(s) && isDelete[m[s]] == 0){
      cout<<"      ��վ���Ѿ�����"<<endl;
  }else {
     n ++;
     cnt ++;
     for(int i = 1 ; i <= n ; i ++){
         graph[i][n] = mx;
         graph[n][i] = mx;
     }
     m[s] = n;
     graph[n][n] = 0;
     cout<<"      ��ӳɹ�"<<endl;
  }
}

//ɾ��վ��
void deleteStation(){
  string s;
  cout<<"      ����Ҫɾ����վ������: ";
  cin>>s;
  if(m.count(s) == 0 || isDelete[m[s]] == 1){
      cout<<"     ��վ���Ѿ�������"<<endl;
  }else {
      m[s] = 0;
      isDelete[m[s]] = 1;
      if(m[s] == n)n --;
      cnt --;
      cout<<"     ɾ���ɹ�"<<endl;
  }
}

//���¾���
void changeDist(){
   cout<<"      ����վ�����Ϣ:�������,�յ�����,Ҫ���µľ���:"<<endl;
   string start,end;
   int distant;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      ����:";
   cin>>distant;
   //cout<<start<<"  "<<end<<endl;
   //cout<<m[start]<<" "<<m[end]<<endl;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       graph[x][y] = graph[y][x] = distant;
       cout<<"      ���³ɹ�"<<endl;
       //cout<<start<<"  "<<end<<endl;
       //cout<<m[start]<<" "<<m[end]<<endl;
   }
}

//����Ʊ��
void changePrice(){
   cout<<"      ����վ�����Ϣ:�������,�յ�����,Ҫ����Ʊ��:"<<endl;
   string start,end;
   int p;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      Ʊ��:";
   cin>>p;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       price[x][y] = price[y][x] = p;
       cout<<"      ���³ɹ�"<<endl;
   }
}

//������Ӫʱ��
void changeStartTime(){
   cout<<"      ����վ�����Ϣ:�������,�յ�����,��ʼʱ��:"<<endl;
   string start,end,time;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      ʱ��:";
   cin>>time;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
       startTime[x][y] = time;
       startTime[y][x] = time;
       cout<<"      ���³ɹ�"<<endl;
   }
}


//���½���ʱ��
void changeEndTime(){
   cout<<"      ����վ�����Ϣ:�������,�յ�����,����ʱ��:"<<endl;
   string start,end,time;
   cout<<"      ���:";
   cin>>start;
   cout<<endl;
   cout<<"      �յ�:";
   cin>>end;
   cout<<endl;
   cout<<"      ʱ��:";
   cin>>time;
   if(m[start] == 0 || m[end] == 0){
       cout<<"      �������յ㲻����"<<endl;
   }else {
       int x = m[start];
       int y = m[end];
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
    cout<<"      1-����վ��    2-ɾ��վ��    3-�޸���·����   4-�޸���·Ʊ��  5-�޸���·��ʼʱ��  6-����·�ߵĽ���ʱ��  7-�˳� "<<endl<<endl;
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
          cout<<"                         �������,����������"<<endl;
          break;           
    }
  }
}

//��ӡÿ������ٽӵ㼰�����
void prinfAll(){
  for(int i = 1 ; i <= n ; i ++){
      if(isDelete[i] == 0){
          cout<<"վ��"<<i<<"���ٽ�վ����:"<<endl;
          for(int j =1 ; j <= n ; j ++){
              if(isDelete[j] == 0 && graph[i][j] != mx && i != j){
                  cout<<j<<",������"<<graph[i][j]<<endl;
              }
          }
      }
  }
}

//�������·
void dijkstra(){
  cout<<" ������վ��:";
  int v;
  cin>>v;
  cout<<endl;
  if(v > n || v <= 0){
      cout<<"���벻�Ϸ�"<<endl;
      return;
  }
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
      cout<<"վ��"<<v<<endl;
      cout << "���·��������0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << i<<"��Ŀ��㲻��ͨ" << endl;
        continue;
      }
      cout<<"վ��"<<i<<endl;
      cout<<"���·������:"<<dist[i]<<endl;
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

//��ӡfloyed·��
void printfpath(vector<vector<int>>fpath,int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(fpath,a,fpath[a][b]);
    cout<<(fpath[a][b])<<" ";
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
  cout<<a<<" ";
  printfpath(fpath,a,b);
  cout<<b<<endl<<endl;
  
}


//���ټ۸�
void dijkstra2(){
  cout<<" ������վ��:";
  int v;
  cin>>v;
  cout<<endl;
  if(v > n || v <= 0){
      cout<<"���벻�Ϸ�"<<endl;
      return;
  }
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
      cout<<"վ��"<<v<<endl;
      cout << "���ٻ�����0" <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << i<<"��Ŀ��㲻��ͨ" << endl;
        continue;
      }
      cout<<"վ��"<<i<<endl;
      cout<<"���ٻ�����:"<<dist[i]<<endl;
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

//��������վ��ļ۸�
void floyd2(){
   int a,b;
  cout<<"����������:";
  cin>>a>>b;
  if(a < 1 || b < 1 || a > n || b > n){
      cout<<"�������"<<endl;
      return;
  }
  if(a == b){
      cout<<"���ٻ�����0"<<endl;
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
  cout<<a<<"��"<<b<<"�����ٻ���Ϊ"<<f[a][b]<<endl;
  cout<<"·��:"<<endl;
  cout<<a<<" ";
  printfpath(fpath,a,b);
  cout<<b<<endl<<endl;
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
    for(int i = 0 ; i< cnt; i ++){
        cout<<i<<endl;
        int t = -1;
        //�ҵ���������������ĵ�
        for(int j = 1 ; j <= n ; j ++){
           if(vist[j] == 0 &&(t == -1 || dist[t] > dist[j])){
               t = j;
           }
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

int dp[1000][1000];
//tsp����
void tsp(){
   //dp��ʾ��i�������������ඥ��j,�����ջص�ԭ��ľ���
   int m = pow(2,cnt) - 1;
   for(int i = 1 ; i< 1000 ; i ++){
       for(int j = 1 ; j < 1000 ; j ++){
           dp[i][j] = mx;
       }
   }
   for(int i = 1 ; i <= n ; i++){
       //�������κμ��ϵ�i
       dp[i][0] = graph[i][1];
   }
   for(int j = 1 ; j < m ; j ++){
       for(int i = 1 ; i  <= n ; i ++){
           if(isDelete[i] == 1)continue;
           dp[i][j] = mx;
           //���ϲ��ܰ���i�Լ�
           if((j >> (i - 1)) & 1 == 1)continue;
           for(int k = 1 ; k <= n ; k ++){
               if(isDelete[k] == 1)continue;
               //�Ӽ�������ѡ��һ����
               if((j >> (k - 1)) & 1 == 0)continue;
               //����
               dp[i][j] = min(dp[i][j],graph[i][k] + dp[k][j^(1 << (k - 1))]);
           }
       }
   }
   cout<<dp[1][m - 1]<<endl;
}

//�û�ģʽ
void user(){  
    cout<<"                              ------------ �û�ģʽ -------------            "<<endl<<endl;
    int choice;
    int f = 1;
    while(f){
        cout<<"  1-ÿ��վ������ڳ����;���  2-��Ŀ�ĵ����·  3-����������������·  4-��Ŀ�ĵ����ٻ���  5-�����������ص����̻���   6-��С������  7-tsp"<<endl;
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

