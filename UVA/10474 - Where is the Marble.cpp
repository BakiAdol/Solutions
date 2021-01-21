#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,q,t=0;
	while(scanf("%d%d",&n,&q) and n)
	{
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		sort(v.begin(),v.end());
		printf("CASE# %d:\n",++t);
		while(q--)
		{
			int marble;
			scanf("%d",&marble);
			int l=0,r=n-1,m,pos=-1;
			while(l<=r)
			{
				m=(l+r)/2;
				if(v[m]>marble) r=m-1;
				else if(v[m]<marble) l=m+1;
				else pos=m,r=m-1;
			}
			if(pos!=-1) printf("%d found at %d\n",marble,pos+1);
			else printf("%d not found\n",marble);
		}
	}
	return 0;
}
