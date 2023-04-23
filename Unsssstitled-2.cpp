#include <iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
//�洢ͼ
int graph[1000][1000];
//��ǰͼ�ж��ٸ���
int n;
//����Ӧ�ĵ������ת��Ϊ���
map<string,int>m; 

//��ʼ��
void init(){
  //�տ�ʼÿ���㶼������
  for(int i = 0 ; i < 1000 ; i ++){
    for(int j = 0 ; j < 1000 ; j ++){
      graph[i][j] = 0;
    }
  }
  int c;
  printf("�����ٽӵ�Ķ���:\n");
  cin>>c;
  while(c --){
    int a,b,d;
    cin>>a>>b>>d;
    graph[a][b] = d;
    graph[b][a] = d;
  }
}
//��������
void outit(){
  for(int i = 0 ; i< n ;i++){
    for(int j= 0 ; j< n ; j++){
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
  for(int i = 0 ; i<n ;i++){
    if(graph[flag][i] !=0)
    printf("jingdian%d lucheng%d\n",i,graph[flag][i]);
  }
}

//������·��ѯ
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
          cout<<"���·��������0"<<endl;
          cout<<v<<endl;
      }else {
          if(dist[i] == 10000000000 ){
              cout<<"�õ��Ŀ��㲻��ͨ"<<endl;
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




int main(){
  printf("���뾰�����\n");
  cin>>n;
  init();  
  outit();
 // setview();
  roadit(0);
  return 0;
}
