#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
set<string>s;
int n,m;
void dfs(vector<string>&v,string str,int n){
    if(str.size()>=m){
        if(str.size() == m)s.insert(str);
        return ;
    }
   for(int i = 0 ; i <v.size() ; i ++){
       dfs(v,str+(v[i]),i);
   }
}
int main(){
    cin>>n>>m;
    vector<string>v(n);
    for(int i=0 ; i<n ; i++){
       cin>>v[i];
    }
    dfs(v,"",0);
    for(string k : s){
      cout<<k<<endl;
    }
    return 0;
}