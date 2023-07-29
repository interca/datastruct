#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include<map>
#include<cstring>
using namespace std;
#include <unordered_set>
#include<set>
#include<cmath>
#include<queue>

 
void solve() {
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i = 0 ; i < n ; i ++)cin >> v[i];
  int mx = 0;
  int ide1 = -1;
  int mn = 0;
  int ide2 = - 1;
  for(int i =  0 ; i  < n ; i ++){
     if(v[i] >= mx){
       mx = v[i];
       ide1 = i;
     }
     if(v[i] < mn){
       mn = v[i];
       ide2 = i;
     }
  }
  vector<pair<int,int>>p;
  if((ide1 != -1 && ide2 == -1) ||(ide1 != -1 && ide2 != -1 && abs(mx) >= abs(mn))){
     if(ide1 != 0){
       v[0] += v[ide1];
       p.push_back({0,ide1});
     }
     for(int i = 1  ;i < ide1 ; i ++){
        while(v[i] < v[i - 1]){
            v[i] += v[ide1];
            v[i] += v[i - 1];
            p.push_back({i,ide1});
            p.push_back({i,i - 1});
        }
     }
      if(ide1 > 0 && v[ide1] < v[ide1 - 1]){
           v[ide1] += v[ide1 - 1];
           p.push_back({ide1,ide1 - 1});
        }
     for(int i = ide1 + 1 ; i < n ; i ++){
         while(v[i] < v[i - 1]){
            v[i] += v[ide1];
            v[i] += v[i - 1];
            p.push_back({i,ide1});
            p.push_back({i,i - 1});
        }
     }
  }else {
     if(ide2 != n - 1){
          v[n - 1] += v[ide2];
          p.push_back({n - 1,ide2});
        }
     for(int i = n - 2 ; i > ide2 ; i --){
         while(v[i] > v[i + 1]){
             v[i] += v[ide2];
             v[i] += v[i + 1];
             p.push_back({i,ide2});
             p.push_back({i,i + 1});
         }
     }
     if(ide2 < n - 1 && v[ide2] > v[ide2 + 1]){
          v[ide2] =+ v[ide2 + 1];
          p.push_back({ide2,ide2 + 1});
       }
     for(int i = ide2 - 1 ; i  >= 0 ; i  --){
         while(v[i] > v[i + 1]){
             v[i] += v[ide2];
             v[i] += v[i + 1];
             p.push_back({i,ide2});
             p.push_back({i,i + 1});
         }
     }
  }
  cout<<p.size()<<endl;
  for(int i = 0 ; i < p.size() ; i ++){
    cout<<p[i].first + 1<<" "<<p[i].second + 1<<endl;
  }
}
 
 
int main(){
  int t = 1;
  cin>>t;
  while(t --)solve();
}