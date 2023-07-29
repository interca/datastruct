#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>

int main(){
  int n;
  cin>>n;;
  vector<int>v(n + 1,0);
  for(int i = 1 ;i <= n ; i ++)cin>>v[i];
  int m;
  cin>>m;
  int mx = 10000000;
  while(m){
    int dp[n + 1][m + 1];
    for(int i = 0 ;i <= n ; i ++){
       for(int j = 0 ; j <= m ; j ++){
            if(j == 0){
                 dp[i][j] = 0;
                 continue;
            }
            dp[i][j] = mx;
       }
    }
    int mn = mx;
    for(int i = 1 ; i <= n ; i ++){
       for(int j = 0 ; j <= m ; j ++){
            for(int k = 0 ; k * v[i] <= j ; k ++){
               dp[i][j] = min(dp[i][j],dp[i - 1][j - k * v[i]] + k);
            }
       }
  }
    cout<<dp[n][m]<<endl;
    cin>>m;
  }
  return 0;
}

