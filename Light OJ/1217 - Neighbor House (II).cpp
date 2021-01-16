#include<bits/stdc++.h>

using namespace std;

int n;

int ar[1005];
int memo[1005][2];

int f(int pos, bool fst)
{
	if(pos>=n) return 0;
	if(fst and pos==n-1) return 0;
	
	int &ret=memo[pos][fst];
	if(ret!=-1) return ret;

	ret=max(f(pos+2,pos==0?true:fst)+ar[pos],f(pos+1,fst));
	
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
		
		for(int i=0;i<n;i++) scanf("%d",&ar[i]);
		
		printf("Case %d: %d\n",test,f(0,0));
	}

	return 0;
}

