#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
#include<map>
int dp[1000][1000];
int w[1000];
int v[1000];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i ++)cin>>w[i];
    for(int i = 1 ; i <= n ; i ++)cin>>v[i];
    for(int i = 1 ; i <= n ; i ++){
        for(int j = 0 ; j <= m ;  j ++){
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]){
                dp[i][j] = max(dp[i][j],dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}