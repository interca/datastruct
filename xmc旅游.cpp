#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
 int dp[1000][1000];
//��ӡ·��
int fpath[1000][1000];
using namespace std;
//�洢ͼ
int graph[1000][1000];
//��ǰͼ�ж��ٸ���
int n;
//����ԭ���飬floyd�㷨
int f[1000][1000];
//����Ӧ�ĵ������ת��Ϊ���
map<string,int>m; 
int mx = 100000000;
void insert(int a,int b,int c){
    a --;
    b --;
    graph[a][b] = graph[b][a] = f[a][b] = f[b][a]  = c;
}
//��ʼ��
void init(){
  //�տ�ʼÿ���㶼������
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
  //printf("�����ٽӵ�Ķ���:\n");
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

//��������
void outit(){
  for(int i = 0 ; i<n ;i++){
    for(int j= 0 ; j<n ; j++){
      printf("%6d" ,graph[i][j]);
    }
    printf("\n");
  }
}
//���ھ����ѯ
void setview(){
  int flag;
  printf("������Ҫ��ѯ�ľ���\n");
  cin>>flag;
  for(int i = 0 ; i< n ;i++){
    if(graph[flag][i] != mx)
    printf("���ھ���Ϊ%d ·����%d\n",i,graph[flag][i]);
  }
}
//������·��ѯ
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
      cout << "���·��������0" <<endl;
      cout << v <<endl;
    }
    else{
      if(dist[i] == mx){
        cout << "�õ��Ŀ��㲻��ͨ" << endl;
        continue;
      }
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
      cout<<endl;
    }
  }
}

//��ӡfloyed·��
void printfpath(int a,int b){
    if(fpath[a][b] < 0)return;
    printfpath(a,fpath[a][b]);
    cout<<(fpath[a][b])<<"  ";
    printfpath(fpath[a][b],b);

}
//����·���ۺϲ�ѯ
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
   cout<<"���·Ϊ"<<graph[a][b]<<endl;
   for(int i = 0 ; i < n ; i ++){
       for(int j = 0 ; j < n ; j ++){
           graph[i][j] = f[i][j];
       }
   }
   printf("·������:\n");
   cout<<a<<" ";
   printfpath(a,b);
   cout<<b<<endl;
}

//��С������
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
    printf("��С��������ֵ��:%d\n",sum);
}

//�޸ľ���
void change(){
    int a,b,c;
    printf("����Ҫ�޸ĵľ���a��b:\n");
    cin>>a>>b;
    printf("1-�޸���������, 2-ɾ�������·��\n");
    cin>>c;
    if(c == 1){
        printf("�����޸ĺ����:\n");
        cin>>c;
        graph[a][b] = graph[b][a] = f[a][b] = f[b][a] = c;
    }else if(c == 2){
        graph[a][b] = graph[b][a] = f[a][b] = f[b][a] = mx;
    }else {
        cout<<"�������"<<endl;
    }
}

//�ӵ�
void add(){
    n ++;
    printf("��ӳɹ�\n");
    for(int i =0 ; i < n ; i ++){
        graph[i][n - 1] = graph[n - 1][i] = f[i][n - 1] = f[n - 1][i] = mx;
        graph[n - 1][n - 1] = f[n - 1][n - 1] = 0;
    }
}

void tsp(){
   //��ʾ��������j�ĵ����ջص�i��j�Ƕ����Ʊ�ʾ����
   int m = pow(2,n) - 1;
   for(int i = 0 ; i< 1000 ; i ++){
       for(int j = 0 ; j < 1000 ; j ++){
           dp[i][j] = mx;
       }
   }
   for(int i = 0 ; i < n ; i++){
       //�Լ����Լ��϶���0
       dp[i][0] = graph[i][0];
   }
   for(int j = 1 ; j < m ; j ++){
       for(int i = 0 ; i  < n ; i ++){
           dp[i][j] = mx;
           //���ϲ��ܰ���i�Լ�
           if((j >> (i)) & 1 == 1)continue;
           for(int k = 0 ; k < n ; k ++){
               //�Ӽ�������ѡ��һ����
               if((j >> (k)) & 1 == 0)continue;
               //����
               dp[i][j] = min(dp[i][j],graph[i][k] + dp[k][j^(1 << (k))]);
               if(i == 0 && j <= 2 && dp[i][j] != mx)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
           }
       }
   }
   cout<<dp[0][m - 1]<<endl;
}
//�������·��ȷ��
//�˵�
void menu(){
  int flag;
  printf("--------------------------------------------------------------------------\n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                      ��ӭʹ�ñ�����������ͼϵͳ                         \n");
  printf("                                                                      \n");
  printf("                          ��ѡ�������ѯ��ѡ��                           \n");
  printf("                                                                       \n");
  printf("                            һ.���㵼��ͼ                               \n");
  printf("                                                                      \n");
  printf("                         ��.��ǰ��������ھ���                            \n");
  printf("                                                                      \n");
  printf("                       ��.��ǰ���㵽������������·��                       \n");
  printf("                                                                      \n");
  printf("                          ��.���������������·                           \n");
  printf("                                                                      \n");
  printf("                           ��.���������·�Ƽ�                            \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                           ��.��С������                               \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                           ��.�޸��������                               \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("                           ��.�������ξ���                             \n");
  printf("                                                                      \n");
  printf("                                                                      \n");
  printf("--------------------------------------------------------------------------\n");

  printf("--------------------------------------------------------------------------\n");
  cout<<endl;
  cout<<endl;
  printf("                           ����������Ҫ��ѯ������\n");
  scanf("%d",&flag);
  printf("--------------------------------------------------------------------------\n");
  switch (flag) {
  case 1:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                                һ.���㵼��ͼ\n");
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
    printf("                              ��.��ǰ��������ھ���\n");
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
    printf("                             ��.��ǰ���㵽������������·��\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("                              ����Ҫ��ѯ�ĵ�\n");
    int v;
    scanf("%d" ,&v);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");
    
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                             ��.��ǰ���㵽������������·��\n");
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
    printf("                             ��.���������������·\n");
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("                              ������Ҫ��ѯ����������\n");
    int a,b;
    scanf("%d%d" ,&a,&b);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    printf("--------------------------------------------------------------------------\n");


    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                             ��.���������������·\n");
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
    printf("                            ��.����������\n");
    printf("--------------------------------------------------------------------------\n");
    tsp();
    cout<<endl;
    cout<<endl;
    break;
  }case 6:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                            ��.��С������\n");
    prime();
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    break;
  }case 7:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                           ��.�޸ľ���\n");
    printf("--------------------------------------------------------------------------\n");
    change();
    cout<<endl;
    cout<<endl;
    break;
  }case 8:{
    printf("--------------------------------------------------------------------------\n");
    cout<<endl;
    cout<<endl;
    printf("                           ��.���Ӿ���\n");
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
  printf("���뾰�����\n");
  //cin>>n;
  init();
  while(1){ 
     menu(); 
  }
  return 0;
}
