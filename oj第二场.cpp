#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
#include<cmath>
#include<string.h>
int main(){
 string s ="";
 string s2 = "";
 cin>>s;
  for(int i= 0 ; i <s.size() ; i ++){
     if(s[i] >='A' &&s[i] <='Z')s[i] = s[i] + 32;
  }
  char s3[1000010];
  cin.getline(s3,sizeof(s3));
  for(int i= 0 ;i < strlen(s3);i++){
      s2+=s3[i];
  }
  for(int i= 0 ; i <=s2.size() ; i ++){
     if(s[i] >='A' &&s2[i] <='Z')s2[i] = s2[i] + 32;
  }
  int sum = 0;
  cout<<s<<endl;
  cout<<s2<<endl;
  for(int i = 0 ;i  < s2.size() - 1; i ++){
      if(s2[i] == s[0] && s2[i + 1] == s[1])sum ++;
  }
  int count = s2.find(s);
  if(count>s2.size())cout<<-1;
  else {
      cout<<sum<<" "<<count<<endl;
  }
  return 0;
}