#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#include<set>
#include<vector>
#include<cmath>
set<long long>s2;
set<long long>s;
vector<int>v;
int cnt;
void count(long long x){
    for(int i = 2 ; i <= x ; i ++){
        if(s.count(i) == 0){
            s2.insert(i);
            for(int j = i; j <= x ; j = j + i){
                s.insert(j); 
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    long long mx = -1;
    for(int i = 0 ; i < n ;  i ++){
       long long a;
       cin>>a;
       mx = max(mx,a);
       v.push_back(a);
    }
    if(mx >= 2)count(mx);
    for(int i = 0 ; i < v.size() ;i ++){
        if(s2.count(v[i]) == 1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}