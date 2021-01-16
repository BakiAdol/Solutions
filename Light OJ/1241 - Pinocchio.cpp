#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;


int main()
{
	int t,n;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%d",&n);
		int pre=2;
		int tmp;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			ans+=(tmp-pre)/5 + ((tmp-pre)%5 ? 1 : 0);
			pre=tmp;
		}
		printf("Case %d: %d\n",test,ans);
	}
	
	return 0;
}

