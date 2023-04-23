#include<stdio.h>
#include<stdlib.h>

//临接矩阵
int g[8][8];
//临接表
typedef struct graph{
    //值
    int value;
    //点下标
    int index;
    //下一个结点
    struct graph*next;
}Graph;

int vist[7];
int queue[10000];

int queueSize = 0;
Graph g2[8];
//临接矩阵
void creatByArray(){
      for(int i = 1; i <= 7 ; i ++){
       for(int j = 1 ; j <= 7 ; j ++){
          g[i][j] = 100000000;
       }
   }
   g[1][2] = g[2][1] = 2;
   g[1][3] = g[3][1] = 4;
   g[1][4] = g[4][1] = 1;
   g[2][4] = g[4][2] = 3 ;
   g[2][5] = g[5][2] = 10;
   g[3][4] = g[4][3] = 2;
   g[3][6] = g[6][3] = 5;
   g[4][5] = g[5][4] = 7;
   g[4][6] = g[6][4] = 8;
   g[4][7] = g[7][4] = 4;
   g[5][7] = g[7][5] = 6;
   g[6][7] = g[7][6] = 1;
   for(int i = 1; i <= 7 ; i ++){
       for(int j = 1 ; j <= 7 ; j ++){
           printf("%d ",g[i][j]);
       }
       printf("\n");
   }
}


//向临接表插入边
void insert(int a,int b,int x){
    Graph * node = (Graph*)malloc(sizeof(Graph));
    node->next = NULL;
    node->value = x;
    node->index = b;
    if(g2[a].next == NULL){
        g2[a].next = node;
    }else {
        node->next = g2[a].next;
        g2[a].next = node;
    }
}

//临接表构建图
void creatByLink(){
   for(int i = 0 ;i <= 7 ; i ++){
       g2[i].next = NULL;
   }
   //插入边和权重
   insert(1,2,2);
   insert(2,1,2);
   insert(1,3,4);
   insert(3,1,4);
   insert(1,4,1);
   insert(4,1,1);
   insert(2,4,3);
   insert(4,2,3);
   insert(2,5,10);
   insert(5,2,10);
   insert(3,4,2);
   insert(4,3,2);
   insert(3,6,5);
   insert(6,3,5);
   insert(4,5,7);
   insert(5,4,7);
   insert(4,6,8);
   insert(6,4,8);
   insert(4,7,4);
   insert(7,4,4);
   insert(5,7,6);
   insert(7,5,6);
   insert(6,7,1);
   insert(7,6,1);
     printf("邻接表构建图如下:\n");
    for(int i = 1; i <= 7 ; i ++){
        printf("和%d相连的结点有:\n",i);
        Graph*head = g2[i].next;
        while(head != NULL){
            int k =  head->index;
            int c = head ->value;
            printf("%d  权重是%d\n",k,c);
            head= head->next;
        }
        printf("\n");
    }
}

//深度优先搜索
void dfs(int i){
  vist[i] = 1;
  printf("%d ",i);
  for(int j = 1 ; j <= 7 ; j ++){
     if(g[i][j] != 100000000 && vist[j] == 0){
         dfs(j);
     }
  }
}

//广度优先搜索
void bfs(int w){
   int  l , r ;
   l = r = 0;
    queue[r ++] = w;
    queueSize  = 1;
    for(int i = 1 ;i <= 7 ; i ++)
        vist[i] = 0;
    vist[w] = 1;
    while(queueSize > 0){
        int c = queue[l ++];
        queueSize--;
        printf("%d ",c);
        for(int i = 1 ;i <= 7 ; i ++){
            if(vist[i] == 0 && g[c][i] != 100000000){
                vist[i] = 1;
                queue[r] = i;
                r ++;
                queueSize++;
            }
        }
    }
   printf("\n");
}

//求最小生成树
void prime(){
    for(int i = 1 ; i <= 7 ; i ++){
        vist[i] = 0;
    }
    //最小生成树最终结果
    int pg[8][8];
    //到生成树的距离
    int distant[8];
    //记录上一个点
    int pre[8];
    for(int i = 1 ;i <= 7 ; i ++){
        pre[8] = -1;
        distant[i] = 1000;
        for(int j = 1; j <= 7 ; j ++){
            pg[i][j] = 0;
        }
    }
    distant[1] = 0;
    for(int i = 1 ;i <= 7 ; i ++){
        vist[i] = 0;
    }
    int n = 7;
    int sum = 0;
    while(n --){
        int t = -1;
        int d = 100000;
        //找到到生成树最小的距离的点
        for(int i = 1 ;i <= 7 ; i ++){
           if(distant[i] < d && vist[i] == 0){
              t = i;
              d = distant[i];
           }
        }
        printf("%d\n",t);
        vist[t] = 1;
        if(sum != 0)
          pg[pre[t]][t] = pg[t][pre[t]] = d;
       for(int i = 1 ; i <= 7 ; i ++){
          if(g[t][i] != 100000000 && vist[i] == 0 && g[t][i] < distant[i]){
              distant[i] = g[t][i];
              pre[i] = t;
          }
       }
       sum ++;
    }

    for(int i = 1 ; i <= 7 ; i ++){
        for(int j = 1 ; j <i ; j ++){
            if(pg[i][j] != 0){
                printf("%d-%d-%d\n",i,j,pg[i][j]);
            }
        }
    }
}

//最短路
void dijkstra(int w){
    
    int path[8];
    int dist[8];
    for(int i = 1 ; i <= 7 ; i ++){
        vist[i] = 0;
        path [i]= -1;
        dist [i] = 100000;
    }
    dist[w] = 0;
    int c = 7;
    while(c --){
        int t = -1;
        int d = 10000000;
        //找出离点目标点最短的点
        for(int i = 1 ; i <= 7 ; i ++){
            if((vist[i] == 0) && (t == -1 || dist[i] < d)){
               t = i;
               d = dist[i];
            }
        }
        vist[t] = 1;
        for(int i = 1 ; i <= 7 ; i ++){
            if(vist[i] == 0 && dist[i] > dist[t] + g[t][i]){
                dist[i] = dist[t] + g[t][i];
                path[i] = t;
            }
        }
    }

    for(int i = 1 ; i < 8 ; i ++){
        if(i == w)continue;
        printf("%d 到 %d 的最短路长度是 %d",i,w,dist[i]);
        int count = 0;
        int index = i;
        //计算经过多少个点
        while(index != -1){
            count ++;
            index = path[index];
        }
        int detailPath[count];
        index = i;
        int j = 0;
        while(index != -1){
            detailPath[j ++] = index;
            index = path[index];
        }
        printf("路径是:\n");
        for(j = count - 1 ; j >= 0 ; j --){
            printf("%d ",detailPath[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void countDegree(){
    //入度
    int idegree[8];
    //出度
    int odegree[8];
    for(int i = 1; i <= 7 ; i ++){
        idegree[i] = odegree[i] = 0;
    }
    for(int i = 1 ; i <= 7 ; i ++){
        for(int j = 1 ; j <= 7 ;  j++){
            if(g[i][j] != 100000000){
                idegree[j] ++;
                odegree[i] ++;
            }
        }
    }
    //入度和出度
    for(int i = 1 ; i<= 7 ; i ++){
        printf("%d的入度是%d,出度是%d\n",i,idegree[i],odegree[i]);
    }
}


int main(){
   while(1){
       int choice;
       printf("输入选择: 1-临接矩阵建图 2 - 临接表 3 - dfs  4 - bfs  5 - prime 6-求一个结点到其他点距离和路径  7-入度和出度 8-求各点最短路\n");
       scanf("%d",&choice);
       switch(choice){
          case 1:
            creatByArray();
            break;
          case 2:
            creatByLink();
            break;
          case 3:
            for(int i =1 ;i  <= 7 ; i ++)vist[i] = 0;
            dfs(1);
            printf("\n");
            break;
          case 4:
            bfs(1);
            break;  
          case 5 :
            prime();
            break;  
          case 6:
            dijkstra(1);  
            break;
          case 7:
             countDegree();
             break;  
          case 8:
             for(int i = 1 ; i <= 7 ; i++)
                dijkstra(i);   
            break;
       }
   }
}