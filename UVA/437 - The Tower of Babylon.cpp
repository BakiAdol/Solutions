#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

vector<pair<int,pair<int,int>>> blocks;

int memo[200];

int n,h,w,l,test;

int dp(int pos)
{
	int ans=0;
	
	if(memo[pos]!=-1) return memo[pos];
	
	for(int i=1;i<n;i++)
	{
		if(blocks[pos].s.f>blocks[i].s.f and blocks[pos].s.s>blocks[i].s.s)
		{
			ans=max(ans,blocks[i].f+dp(i));
		}
	}
	return memo[pos]=ans;
}

int main()
{
	test=0;
	while(scanf("%d",&n) and n)
	{
		memset(memo,-1,sizeof(memo));
		
		blocks.clear();
		
		blocks.push_back({100000000,{100000000,100000000}});
		
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&l,&w,&h);
			blocks.push_back({h,{l,w}});
			blocks.push_back({h,{w,l}});
			blocks.push_back({w,{l,h}});
			blocks.push_back({w,{h,l}});
			blocks.push_back({l,{w,h}});
			blocks.push_back({l,{h,w}});
		}
		
		n=blocks.size();
		
		printf("Case %d: maximum height = %d\n",++test,dp(0));
	}
	
	return 0;
}
