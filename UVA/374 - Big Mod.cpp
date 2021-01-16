#include <bits/stdc++.h>

using namespace std;
 
typedef long long int lli;

lli b,p,m;

lli bm(lli pow)
{
	if(pow==1) return b%m;
	if(pow==0) return 1;
	lli ans=1;
	ans*=bm(pow/2);
	ans*=ans;
	ans%=m;
	if(pow&1) ans*=b;
	return ans%m;
}

int main()
{
	
	while(scanf("%lld %lld %lld",&b,&p,&m)!=EOF)
	{
		printf("%lld\n",bm(p));
	}
	
	return 0;
}
