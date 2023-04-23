#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int find(int a,vector<int>&v){
   int l = 0;
   int r = v.size() - 1;
   while(l <= r){
       int mid = (l + r)/2;
       if(v[mid] > a)r = mid - 1;
       else  if(v[mid] < a) l = mid + 1;
       else return 1;
   }
   return -1;
}
int main(){
    vector<int>v(10000);
    for(int i = 0 ; i < 10000 ; i ++){
        int  a = rand();
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int re;
    re = find(-1,v);
    if(re == -1)cout<<"没有找到"<<endl;
    else cout<<"找到"<<endl;
    re = find(v[1],v);
    if(re == -1)cout<<"没有找到"<<endl;
    else cout<<"找到"<<endl;
    return 0;   
}