#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, m;
		scanf("%d%d",&n,&m);
		
		int ans=0;
		while(m--)
		{
			int k,tmp,zz=1;
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&tmp);
				zz=(zz*tmp)%n;
			}
			ans=(ans+zz)%n;
		}
		printf("%d\n",ans);
	}
    return 0;
}
