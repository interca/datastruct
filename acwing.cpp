#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
#include<map>
vector<string>v;
int n;
int m;
vector<string>v2(100);

//先求出所有的排列
void dfs(string s){
    if(s.size() == n){
        v.push_back(s);
        return;
    }
    for(int w = 1 ; w >= 0 ; w --){
        dfs(s + to_string(w));
    }
}
int f = 0;

//判断两个字符串是否只有一个位不同
bool judge(string a,string b){
    int sum = 0;
    for(int j = 0 ; j < a.size() ; j ++){
        if(a[j] != b[j])sum ++;
    }
    if(sum != 1)return false;
    return true;
}

//求格雷码
void gl(vector<int>&vist,int c){
   if(f == 1)return;
   if(c == m){
       for(int i = 0 ; i < c - 1 ; i ++){
          string a = v2[i];
          string b = v2[i + 1];
          bool flag = judge(a,b);
          if(flag == false)return;

       }
       for(int i = 0 ; i < m ; i ++){
           cout<<v2[i]<<endl;
       }
       f = 1;
       return;
   }
   for(int i = 0 ; i < m ;  i ++){
       if(vist[i] == 0){
       //剪枝，减少回溯次数
       if(c - 1 >=0){
          string a = v2[c - 1];
          string b = v[i];
          bool flag = judge(a,b);
          if(flag == false)continue;
        }
           vist[i] = 1;
           v2[c] = v[i];
           gl(vist,c + 1);
           vist[i] = 0;
       }
   }
}

int main(){
   cin>>n;
   dfs("");
   m = v.size();
   vector<int>vist(m,0);
   gl(vist,0);
}