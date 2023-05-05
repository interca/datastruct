#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n + 1);
    for(int i = 1 ; i <= n ; i ++){
        cin>>v[i];
    }
    vector<int>dp(n + 1,1);
    vector<int>path(n + 1,0);
    int mx = 1;
    int idex = 1;
    for(int i = 1 ; i <= n ; i ++){
      for(int j = 1 ; j < i ; j ++){
          if(v[j] <= v[i]){
              if(dp[j] + 1 > dp[i]){
                  dp[i] = dp[j] + 1;
                  path[i] = j;
              }
          }
      }
      if(dp[i] > mx){
          mx = dp[i];
          idex = i;
      }
    }
    cout<<"最长递增子序列的长度是:"<<mx<<endl;
    cout<<"最长递增子序列是:"<<endl;
    vector<int>a;
    while(idex != 0){
       a.push_back(v[idex]);
       idex = path[idex];
    }
    for(int i = a.size() - 1 ; i >= 0 ; i --){
        cout<<a[i]<<" ";
    }
    return 0;
}