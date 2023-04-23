#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
 
void solve(){
  int n;
  cin>>n;
  vector<int>v1(n + 2,0);
  vector<int>v2(n + 2,0);
  for(int i = 1 ;i <= n ; i ++)cin>>v1[i];
  for(int i = 1;  i <= n ; i ++)cin>>v2[i];
  int mx=  0;
  int sum = 0;
  int l = 1;
  int r = 1;
  int left = 1;
  for(int i =1 ; i <= n ; i ++){
     if(v1[i] != v2[i]){
        sum ++;
        if(sum >= mx){
           l = left;
           r = i;
           mx = sum;
       }
    }else {
          left = i + 1;
          sum = 0;
      }
  }
  int w = l;
  for(int i = w  - 1 ;i >= 1 ; i --){
    if(v2[i] <= v2[i + 1])l --;
    else break;
  }
  w = r;
  for(int i = w + 1; i <= n ; i ++){
    if(v2[i] >= v2[i - 1])r ++;
    else break;
  }
  cout<<l<<" "<<r<<endl;
}
 
int main(){
  int t = 1;
  cin>>t;
  while(t --){
    solve();
  }
}
