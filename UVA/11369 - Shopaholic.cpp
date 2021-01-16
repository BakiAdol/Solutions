#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		
		int pos=2;
		int ans=0;
		while(pos<n)
		{
			ans+=v[pos];pos+=3;
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
