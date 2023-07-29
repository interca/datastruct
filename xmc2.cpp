#include <algorithm>
#include<cstring>
#include <iostream>

using namespace std;

const int N = 10000000;

int n,res;
int q[N] , tmp[N];

void sort(int q[] , int l , int r){
    if(l >= r) return;

    int mid = l+r >> 1;

    sort(q,l,mid) , sort(q, mid+1, r);

    int k=0 ,i=l, j = mid+1;
    while(i <= mid && j<= r){
        if(q[i]<=q[j]) tmp[k++] = q[i++];
        else{
            res+= mid - i + 1;
            int b = i;
            while (b<=mid) {
                printf("\n(%d %d)\n",q[b],q[j]);
                b++;
            }
            tmp[k++] = q[j++];
            
        } 
    }
    while (i<=mid) {
    tmp[k++] = q[i++];
    }
    while (j<=r) {
    tmp[k++] = q[j++];
    }
    

    for(i=l , j=0; i<=r ; i++,j++){
        q[i] = tmp[j];
    }

} 

int main(){
    cout<<"输入数组元素个数"<<endl;
    scanf("%d",&n);

    cout<<"输入数组元素"<<endl;
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&q[i]);
    }

    sort(q,0,n-1);
    cout<<endl;
    cout<<"逆序对共有"<<res<<"对"<<endl;

    return 0;
}