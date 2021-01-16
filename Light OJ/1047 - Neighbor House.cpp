#include<bits/stdc++.h>

using namespace std;

int n;

int ar[22][4];
int memo[22][4];

int f(int pos, int pre)
{
	if(pos==n) return 0;
	
	int &ret=memo[pos][pre];
	if(ret!=-1) return ret;
	ret=100000000;
	
	if(pre!=1) ret=min(ret,f(pos+1,1)+ar[pos][1]);
	if(pre!=2) ret=min(ret,f(pos+1,2)+ar[pos][2]);
	if(pre!=3) ret=min(ret,f(pos+1,3)+ar[pos][3]);
	
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	for(int test=1;test<=t;test++)
	{
		scanf("%d",&n);
		
		memset(memo,-1,sizeof(memo));
		
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&ar[i][1],&ar[i][2],&ar[i][3]);
		}
		
		printf("Case %d: %d\n",test,f(0,0));
	}

	return 0;
}

