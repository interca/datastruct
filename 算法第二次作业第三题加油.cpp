#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>

int main(){
    int n;
    cin>>n;
    int m;
    int flag = n;
    vector<int>num;
    cin>>m;
    int a[m];
    int count = 0;
    for(int i = 0 ;i < m ; i ++)cin>>a[i];
    for(int i = 0 ;i < m ; i ++){
        if(flag > a[i]){
            flag -= a[i];
        }else {
            count ++;
            flag = n;
            flag -= a[i];
            num.push_back(i);
        }
    }
    cout<<count<<endl;
    for(int i = 0 ;i < num.size() ; i ++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
//30
//10
//11 14 28 6 7 8 5 2 20 8
