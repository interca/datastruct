
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
 int lengthz = 0;
     int lengtho = 0;
     int mx1 = 0;
     int mx2 = 0;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i = 0 ; i<n ;i ++){
        int a;
        cin>>a;
        v.push_back(a);
        if(v[i] == 1){
           lengtho ++;
           lengthz --;
           if(lengthz < 0) lengthz = 0;
           mx1 = max(lengtho,mx1);
        }else {
            lengthz ++;
            lengtho --;
            if(lengtho < 0)lengtho = 0;
            mx2 = max(mx2,lengthz);
        }
    }
  cout<<mx1+mx2+1<<endl;
    return 0;
} 