#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
#include<map>


void solve(){
  int n,m;
  cin>>n>>m;
  if(n % m == 1 )cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
 
int main(){
  int t = 1;
  cin>>t;
  while(t --){
    solve();
  }
}