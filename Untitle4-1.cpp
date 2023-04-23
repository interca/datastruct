
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
ll T,n;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		ll x=0;
		scanf("%lld",&n);cout<<n<<endl;
		for(ll i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			ll y=1;
			while(x>y){y*=2;}
			cout<<i<<" "<<y-x<<endl;
		}
	}
	return 0;
}