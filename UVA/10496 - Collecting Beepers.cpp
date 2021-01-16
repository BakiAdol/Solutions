#include<bits/stdc++.h>

using namespace std;

int x,y,bp;
vector<pair<int,int>> bep;

int memo[13][4100];

int dp(int pre, int mask)
{
	if(mask==(1<<bp)-1)
	{
		return abs(bep[pre].first-bep[0].first)+abs(bep[pre].second-bep[0].second);
	}
	
	int &ret=memo[pre][mask];
	if(ret!=-1) return ret;
	ret=1000000;
	
	for(int i=1;i<bp;i++)
	{
		if((mask&(1<<(i)))==0)
		{
			int dis=abs(bep[pre].first-bep[i].first)+abs(bep[pre].second-bep[i].second);
			ret=min(ret,dis+dp(i,mask|(1<<i)));
		}
	}
	return ret;
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		scanf("%d%d",&x,&y);
		scanf("%d",&bp);
		
		bep.clear();
		memset(memo,-1,sizeof(memo));
		
		bep.push_back({x,y});
		for(int i=0;i<bp;i++)
		{
			scanf("%d%d",&a,&b);
			bep.push_back({a,b});
		}
		bp++;
		
		printf("The shortest path has length %d\n",dp(0,1));
	}
	return 0;
}

