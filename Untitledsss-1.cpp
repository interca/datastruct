#include<stdio.h>
#include <stdlib.h>
int queue[1000];
int l = 0;
int r = 0;
int queueSize = 0;
//临接矩阵
int g[6][6];
//临接表
typedef struct graph{
    //值
    int value;
    //点下标
    int index;
    //下一个结点
    struct graph*next;
}Graph;

Graph g2[6]; 

int vist[6];
//临接矩阵构建图
void creatByMatrix(){
    for(int i= 1;i<=5 ; i++){
        for(int j=0;j<=5;j++){
            g[i][j]=-1;//初始化
        }
    }
    g[1][2] = g[2][1] = 8;
    g[2][3] = g[3][2] = 7;
    g[1][4]= g[4][1] = 4;
    g[2][5] = g[5][2] = 12;
    g[2][4] = g[4][2] = 5;
    g[3][4] = g[4][3] = 11;
    g[3][5] = g[5][3] = 6;
    g[4][5] = g[5][4] = 3;
    printf("临接矩阵构建图如下:\n");
    for(int  i = 1; i <= 5 ; i ++){
        for(int j = 1; j <=5 ; j++){
            if(i==j){
                g[i][j]=0;
            }
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//邻接表构建图
//插入边
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

//构建图
void creatByLinkList(){
    for(int i = 1 ;i <= 5 ; i ++ ){
        g2[i].next = NULL;
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
    printf("邻接表构建图如下:\n");
    for(int i = 1; i <= 5 ; i ++){
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

void dfs(int x){
    printf("%d ",x);
    vist[x]  = 1;
    for(int i = 1 ; i <=5 ; i ++){
        if(g[x][i] != 0 && vist[i] == 0){
            vist[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int x){
    queue[r ++] = x;
    queueSize ++;
    for(int i = 1 ;i <= 5 ; i ++)
        vist[i] = 0;
    vist[x] = 1;
    while(queueSize > 0){
        int c = queue[l];
        l++;
        queueSize--;
        printf("%d ",c);
        for(int i = 1 ;i <= 5 ; i ++){
            if(vist[i] == 0 && g[c][i] != 0){
                vist[i] = 1;
                queue[r ++] = i;
                queueSize++;
            }
        }
    }
}
int main(){
    //初始化
    creatByMatrix();
    creatByLinkList();
    printf("\n");
    printf("dfs:\n");
    dfs(1);
    printf("\n");
    printf("bfs:\n");
    bfs(5);
    return 0;
}