#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
bool f(long long t)
{
	for(int i=2;i<=sqrt(t);i++)
	{
		if(t%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n;
	cin>>n;
	
	
	while(n--)
	{	long long t;
		cin>>t;
		if(t==1)
		{
			cout<<"NO\n";
			continue;
		}
		long long m=sqrt(t);
		
		
		if(m*m==t)
		{	
		
	
			if(f(m))
			{
			cout<<"YES\n";
			}
			else
			{
			cout<<"NO\n";
			}
		}
		else
		{
			cout<<"NO\n";
		}
		
	
	}
	
 
 
 
  return 0;
}