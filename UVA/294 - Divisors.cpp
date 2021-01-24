#include<bits/stdc++.h>

using namespace std;

int ar[10005];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		
		memset(ar,0,sizeof(ar));
		
		for(int i=2;i*i<=r;i++)
		{
			int x=l/i;
			x*=i;if(l%i) x+=i;
			while(x<=r)
			{
				if(i*i<x) ar[x-l]+=2;
				else if(i*i==x) ar[x-l]++;
				x+=i;
			}
		}
		l==1 ? ar[0]++ : ar[0]+=2;
		int ans=0;
		for(int i=1;i<=r-l;i++)
		{
			ar[i]+=2;
			if(ar[ans]<ar[i]) ans=i;
		}
		
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",l,r,ans+l,ar[ans]);
	}
	return 0;
}
