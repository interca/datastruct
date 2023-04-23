#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[50010];
    memset(a,0,sizeof a);
    int n;
    cin>>n;
    int m1 = -1;
    int m2 = -1;
    for(int i = 0 ; i < n ; i++){
        int b;
        cin>>b;
        a[b]++;
        if(m1 == -1){
            m1 = b;
            m2 = 1;
        }else {
            if(a[b] > m2){
                m1 = b;
                m2 = a[b];
            }
        }
    }
    cout<<m1<<endl;
    cout<<m2;
    return 0;
}