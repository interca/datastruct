#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
//��������
int number = 0;
int s;
void dfs(vector<int>w,int n,int sum){
   if(sum >= s){
       if(sum == s)
         number++;
       return ;
   }
   for(int i = n ; i <w.size() ;  i ++){
      dfs(w,i + 1,sum+w[i]);
   }
}
int main(){
    int n;
    //���뱳������������Ʒ�ĸ���
    cin>>s>>n;
    vector<int>w;
    //��ȡÿ����Ʒ������
    for(int i = 0 ; i < n ; i ++){
        int a;
        cin>>a;
        w.push_back(a);
    }
    dfs(w,0,0);
    if(number == 0)cout<<"û�з���"<<endl;
    else cout<<"������:"<<number<<"��"<<endl;
    return 0;
}