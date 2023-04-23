#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
  vector<int>v(5,0);
  v[0]=1;
  v[1]=2;
  v[2]=3;
  v[3]=4;
   v.erase(v.begin());
   cout<<v[0];
   return 0;
}