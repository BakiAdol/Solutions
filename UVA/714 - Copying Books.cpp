#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int b,n;
		scanf("%d%d",&b,&n);
		vector<int> v(b);
		for(int i=0;i<b;i++) scanf("%d",&v[i]);
		reverse(v.begin(),v.end());
		
		lli l=1,r=10000000000,m,ans;
		while(l<=r)
		{
			m=(l+r)/2;
			int x=0;
			lli total=0;
			for(int i=0;i<b;i++)
			{
				if(v[i]>m)
				{
					x=n+1;
					break;
				}
				else if(v[i]+total>m)
				{
					x++;
					total=v[i];
				}
				else total+=v[i];
			}
			if(total) x++;
			if(x>n) l=m+1;
			else ans=m,r=m-1;
		}
		
		vector<int> res;
		lli sum=0;int cou=0;
		for(int i=0;i<b;i++)
		{
			if(sum+v[i]<=ans and cou+b-i>=n)
			{
				res.push_back(v[i]);
				sum+=v[i];
			}
			else
			{
				sum=v[i];res.push_back(-1);cou++;
				res.push_back(v[i]);
			}
		}
		reverse(res.begin(),res.end());
		
		for(int i=0;i<(int)res.size();i++)
		{
			if(i==0) printf("%d",res[i]);
			else if(res[i]==-1) printf(" /");
			else printf(" %d",res[i]);
		}
		printf("\n");
	}
	return 0;
}
