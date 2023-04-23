#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<cstdio>

using namespace std;

const int N = 2e4 + 10;

int n, m;
int p[N], d[N];
unordered_map<int,int>mp;

//离散化
int get(int x){
    if(mp.count(x) == 0)mp[x] = ++n;
    return mp[x];
}

int find(int x)  // 并查集
{
    if (p[x] != x){
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main(){
    cin>>n>>m;
    int sum = 0;
    cout<<"s"<<endl;
    for(int i = 0 ; i < N ; i ++)p[i] = i;
    for(int i = 1 ; i <= m ; i ++){
        int a,b;
        string s;
        cin>>a>>b>>s;
         int ans;
        if(s == "even")ans = 0;
        else ans = 1;
        a = get(a - 1);
        b = get(b);
        int pa = find(a);
        int pb = find(b);
        if(pa != pb){
            p[pa] = pb;
            d[pa] = (d[a]^d[b]^ans);
        }else {
            if((d[a] ^ d[b])!= ans){
                sum = i - 1;
                break;
            }
        }
    }
    cout<<sum<<endl;
}