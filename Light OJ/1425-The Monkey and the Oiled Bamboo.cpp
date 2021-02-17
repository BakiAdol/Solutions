#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int n;
vector<int> v(100005);

bool f(int k)
{
	for(int i=1;i<=n;i++)
	{
		if(v[i]-v[i-1]>k) return false;
		else if (v[i]-v[i-1]==k) k--; 
	}
	return true;
}

int main() 
{
	int t;
	scanf("%d",&t);
	v[0]=0;
	for(int test=1;test<=t;test++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
		}
		
		lli l,r,m,ans;
		l=0;
		r=ans=1000000002;
		
		while(l<=r)
		{
			m=(l+r)/2;
			if(f(m))
			{
				ans=min(ans,m);
				r=m-1;
			}
			else l=m+1;
		}
		
		printf("Case %d: %lld\n",test,ans);
	}
    return 0;
}
