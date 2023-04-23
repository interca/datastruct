#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
//�ٽӾ���
int graph1[6][6];
//�ٽӱ�
typedef struct g{
    //ֵ
    int value;
    //���±�
    int index;
    //��һ�����
    struct g*nextNode;
}Graph;

Graph graph2[6]; 

int vist[6];
//�ٽӾ��󹹽�ͼ
void creatByMatrix(){
    for(int i= 1;i<=5 ; i++){
        for(int j=0;j<=5;j++){
            graph1[i][j]= 1000000;//��ʼ��
        }
    }
    graph1[1][2] = graph1[2][1] = 8;
    graph1[2][3] = graph1[3][2] = 7;
    graph1[1][4]= graph1[4][1] = 4;
    graph1[2][5] = graph1[5][2] = 12;
    graph1[2][4] = graph1[4][2] = 5;
    graph1[3][4] = graph1[4][3] = 11;
    graph1[3][5] = graph1[5][3] = 6;
    graph1[4][5] = graph1[5][4] = 3;
    printf("�ٽӾ��󹹽�ͼ����:\n");
    for(int  i = 1; i <= 5 ; i ++){
        for(int j = 1; j <=5 ; j++){
            printf("%d ",graph1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//�ڽӱ���ͼ
//�����
void insert(int a,int b,int x){
    Graph * node = (Graph*)malloc(sizeof(Graph));
    node->nextNode = NULL;
    node->value = x;
    node->index = b;
    if(graph2[a].nextNode == NULL){
        graph2[a].nextNode = node;
    }else {
        node->nextNode = graph2[a].nextNode;
        graph2[a].nextNode = node;
    }
}

//�ٽӱ���ͼ
void creatByLinkList(){
    for(int i = 1 ;i <= 5 ; i ++ ){
        graph2[i].nextNode = NULL;
    }
    insert(1,2,8);
    insert(2,1,8);
    insert(2,3,7);
    insert(3,2,7);
    insert(1,4,4);
    insert(4,1,4);
    insert(2,5,12);
    insert(5,2,12);
    insert(2,4,5);
    insert(4,2,5);
    insert(3,4,11);
    insert(4,3,11);
    insert(3,5,6);
    insert(5,3,6);
    insert(4,5,3);
    insert(5,4,3);
    printf("�ڽӱ�:\n");
    for(int i = 1; i <= 5 ; i ++){
        printf("%d���ٽӽ������:\n",i);
        Graph*head = graph2[i].nextNode;
        while(head != NULL){
            int x =  head->index;
            int y = head ->value;
            printf("%d  Ȩ����%d\n",x,y);
            head= head->nextNode;
        }
        printf("\n");
    }
}



//������ȱ���
void printByDfs(int x){
    printf("%d ",x);
    vist[x]  = 1;
    for(int i = 1 ; i <=5 ; i ++){
        if(graph1[x][i] != 0 && vist[i] == 0){
            vist[i] = 1;
            printByDfs(i);
        }
    }
}

//��ȱ���
void printByBfs(){
  cout<<"��ȱ�����:"<<endl;
  //�������
  queue<int>q;
  q.push(1);
  memset(vist,0,sizeof vist);
  while(q.size() > 0){
    int n = q.front();
    q.pop();
    vist[n] ++;
    cout<<n<<" "<<endl;
    for(int i = 1 ; i<= 5 ; i++){
        if(graph1[n][i] !=1000000 && vist[i] ==0){
            q.push(i);
            vist[i] = 1;
        }
    }
  }
   cout<<"\n"<<endl;
}

//��С������
void prime(){
    memset(vist,0,sizeof vist);
    //��С������
    int minTree[6][6];
    //ÿ���㵽��С�������ľ���
    int dist[6];
    //��¼��һ����
    int preNode[6];
    for(int i = 1 ;i <= 5 ; i ++){
        preNode[i] = -1;
        dist[i] = 1000;
        for(int j = 1; j <= 5 ; j ++){
            minTree[i][j] = 0;
        }
    }
    dist[1] = 0;
    int count = 5;
    int sum = 0;
    while(count --){
        int t = -1;
        int dis = 100000;
        //�ҵ�����������С�ľ���ĵ�
        for(int i = 1 ;i <= 5 ; i ++){
           if(dist[i] < dis && vist[i] == 0){
              t = i;
              dis = dist[i];
           }
        }
        vist[t] = 1;
        if(sum != 0)
          minTree[preNode[t]][t] = minTree[t][preNode[t]] = dis;
       for(int i = 1 ; i <= 5 ; i ++){
          if(graph1[t][i] != 1000000 && vist[i] == 0 && graph1[t][i] < dist[i]){
              dist[i] = graph1[t][i];
              preNode[i] = t;
          }
       }
       sum ++;
    }
    

    for(int i = 1 ; i <= 5 ; i ++){
        for(int j = 1 ; j <i ; j ++){
            if(minTree[i][j] != 0){
                printf("%d-%d-%d\n",i,j,minTree[i][j]);
            }
        }
    }
}

void countDegree(){
    int inDegree[6];
    int outDegree[6];
    //��ʼ������
    for(int i = 1 ; i <= 5 ; i ++){
        inDegree[i] = 0;
        outDegree[i] = 0;
    }
    for(int i = 1 ; i<= 5  ; i++){
        for(int j = 1 ; j <= 5 ;  j++){
           inDegree[j] ++;
           outDegree[i] ++;
        }
    }
    for(int i = 1 ; i <= 5 ;  i++){
        cout<<i<<"�ĳ�����:"<<outDegree[i]<<endl;
        cout<<i<<"�������:"<<inDegree[i]<<endl;
    }
}
void minPath(int w){
    int path[6];
    int dist[6];
    for(int i = 1 ; i <= 5 ; i ++){
        vist[i] = 0;
        path [i]= -1;
        dist [i] = 10000;
    }
    dist[w] = 0;
    int c = 5;
    while(c --){
        int node = -1;
        int dis = 10000000;
        //�ҳ����Ŀ�����̵ĵ�
        for(int i = 1 ; i <= 5 ; i ++){
            if((vist[i] == 0) && (node == -1 || dist[i] < dis)){
               node = i;
               dis = dist[i];
            }
        }
        vist[node] = 1;
        for(int i = 1 ; i <= 5 ; i ++){
            if(vist[i] == 0 && dist[i] > dist[node] + graph1[node][i]){
                dist[i] = dist[node] + graph1[node][i];
                path[i] = node;
            }
        }   
    }
    for(int i = 1 ; i<= 5 ;  i++){
        if(w != i){
            printf("%d��%d�����·��%d\n",w,i,dist[i]);
            printf("·������:\n");
            stack<int>s;
            int j = i;
            while(j != -1){
                s.push(j);
                j = path[j];
            }
            while(s.size()){
                cout<<s.top()<<" "<<endl;
                s.pop();
            }
        }
    }
    cout<<"\n"<<endl;
}
int main(){
  while(true){
      printf("�������� 1-�ٽӾ��� 2- �ٽӱ�  3 - dfs 4 - bfs  5 - ���· 6 - prime  7-����  8-�������·\n");
      int c;
      cin>>c;
      switch(c){
          case 1:
            creatByMatrix();
            break;
          case 2:
            creatByLinkList();
            break;  
          case 3:
            memset(vist,0,sizeof(vist));
            printByDfs(1);
            printf("\n");
            break;  
          case 4:
            printByBfs();
            break;
          case 5:
            minPath(1);
            break;  
          case 6:
            prime();
           break;
          case 7:
             countDegree();
             break; 
          case 8:
             for(int i = 1 ; i<= 5 ; i ++){
                 minPath(i);
                 cout<<endl;
             }     
      }
  }
}