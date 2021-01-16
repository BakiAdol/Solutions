#include<bits/stdc++.h>

using namespace std;

int n,k;
int memo[55][1005];
int coins[55],freq[55];

int f(int pos, int remain)
{
	if(remain==0) return 1;
	if(pos==n) return 0;
	
	int &ret=memo[pos][remain];
	if(ret!=-1) return ret;
	ret=0;
	
	for(int i=0;i<=freq[pos];i++)
	{
		int x=remain-coins[pos]*i;
		if(x<0) break;
		ret+=f(pos+1,x);
		ret%=100000007;
	}
	
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	for(int test=1;test<=t;test++)
	{
		scanf("%d%d",&n,&k);
		
		for(int i=0;i<n;i++) scanf("%d",&coins[i]);
		for(int i=0;i<n;i++) scanf("%d",&freq[i]);
		
		memset(memo,-1,sizeof(memo));
		
		printf("Case %d: %d\n",test,f(0,k));
	}

	return 0;
}

