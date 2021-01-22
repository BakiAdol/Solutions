#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	for(int test =1;test<=t;test++)
	{
		int n;
		scanf("%d",&n);
		vector<int> v(n+1),p(n+1);
		for(int i=1;i<=n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			v[tmp]=i;
			p[i]=tmp;
		}
		
		int misMatch=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==i) continue;
			misMatch++;
			swap(p[v[i]],p[i]);
			swap(v[p[i]],v[p[v[i]]]);
		}
		
		printf("Case %d: %d\n",test,misMatch);
	}
	return 0;
}
