#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
 
void solve(){
  string s;
  cin >> s;
  int a[26];
  memset(a,0,sizeof(a));
  for(auto k : s){
     int w = k - 'a';
     a[w] ++;
  }
  int mn = 100000000;
  for(int i = 0 ;i  < 26 ; i ++){
    if(a[i] == 0)continue;
    char b = i + 'a';
    int mx = 0;
    int sum = 0;
    for(int i = 0 ; i < s.size() ; i ++){
       if(s[i] == b){
          mx = max(sum,mx);
          sum = 0;
       }else {
          sum ++;
          mx = max(sum,mx);
       }
    }
    int sm = 0;
    while(mx){
       if(mx % 2 == 0){
         mx = mx /2;
       }else mx = mx / 2;
       sm ++;
    }
    mn = min(mn,sm);
  }
  cout<<mn<<endl;
}
 
int main(){
  int t = 1;
  cin>>t;
  while(t --){
    solve();
  }
}