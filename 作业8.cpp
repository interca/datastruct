#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
//方案数量
int number = 0;
int s;
void dfs(vector<int>w,int n,int sum){
   if(sum >= s){
       if(sum == s)
         number++;
       return ;
   }
   for(int i = n ; i <w.size() ;  i ++){
      dfs(w,i + 1,sum+w[i]);
   }
}
int main(){
    int n;
    //读入背包的容量和物品的个数
    cin>>s>>n;
    vector<int>w;
    //读取每个物品的重量
    for(int i = 0 ; i < n ; i ++){
        int a;
        cin>>a;
        w.push_back(a);
    }
    dfs(w,0,0);
    if(number == 0)cout<<"没有方案"<<endl;
    else cout<<"方案有:"<<number<<"种"<<endl;
    return 0;
}