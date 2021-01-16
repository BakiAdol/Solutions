#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n) and n)
	{
		long long int ans=0,sum,tmp;
		scanf("%lld",&sum);
		for(int i=1;i<n;i++)
		{
			ans+=abs(sum);
			scanf("%lld",&tmp);
			sum+=tmp;
		}
		printf("%lld\n",ans);
	}

	return 0;
}





