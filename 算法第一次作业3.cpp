#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#include<vector>
#include<cmath>
#include<map>

int main(){
    int n;
    int a,b;
    cin>>n;
    int v[n];
    for(int i = 0 ; i < n ; i ++){
        cin>>v[i];
    }
    cin>>a>>b;
    if(a <= b){
        int l1 = 0,r1  = n - 1;
        while(l1 < r1){
            int mid = l1 + r1 >> 1;
            if(v[mid] >= a)r1 = mid;
            else l1 = mid  + 1;
        }
       int l2 = 0,r2 = n - 1;
       while(l2 < r2){
          int mid = l2 + r2  + 1>> 1;
          if(v[mid] <= b)l2 = mid;
          else 
          r2 = mid - 1;
       }
       for(int i = max(l1,0) ; i <= min(n - 1,l2) ; i  ++){
           cout<<v[i]<<" ";
       }
    }
    return 0;
}