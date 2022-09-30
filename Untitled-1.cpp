
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int n=510,m=100010;
int g[n],value[m],ne[m],idx;
int match[n];
bool st[n];

bool find(int x){
     for(int i=g[x];i!=-1;i=ne[i]){
         int j=value[i];
         if(st[j]==false){
             st[j]=true;
             if(match[j]==0||find(match[j])==true){
                 match[j]=x;
                 return true;
             }
         }
     }
     return false;
}

void add(int a, int b)  // 添加一条边a->b
{
    value[idx] = b, ne[idx] = g[a], g[a] = idx++ ;
}


int main(){
    int n1,n2,m;
    scanf("%d%d%d", &n1, &n2,&m);
    memset(g,-1,sizeof g);
    
    while(m--){
        int a,b;
        scanf("%d%d", &a, &b);
        add(a,b);
    }
    int sum=0;
    for(int i=1;i<=n1;i++){
        memset(st, 0, sizeof st);
        if(find(i))sum++;
    }
    printf("%d",sum);
    return 0;
    void change(v)
}
