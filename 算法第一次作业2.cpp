#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
#include<map>
int vist[10];
int c = 0;
void dfs(string s){
    if(s.size() == 9){
       int a[9];
       for(int i = 0 ; i< 9 ; i ++){
           a[i] = s[i] - '0';
       }
       int fz = (a[0] * 10 +a[1]) * a[2] + (a[3] * 100 + a[4] * 10 + a[5]);
       if(fz % a[6] != 0)return;
       cout<<s[0]<<s[1]<<"*"<<s[2]<<"+"<<s[3]<<s[4]<<s[5]<<"/"<<s[6]<<"-"<<s[7]<<s[8]<<"=";
       int sum = fz/a[6] - (a[7] * 10 + a[8]);
       cout<<"("<<sum<<")"<<endl;
       c ++;
       return;
    }
    for(int i = 1 ; i <= 9 ; i ++){
        if(vist[i] == 0){
            if(i == 1 &&(s.size() == 2 || s.size() == 6))continue;
            vist[i] = 1;
            dfs(s + to_string(i));
            vist[i] = 0;
        }
    }
}
int main(){
    dfs("");
    cout<<c<<endl;
    return 0;
}