#include<bits/stdc++.h>

using namespace std;

vector<int> primes;
bool p[33005];

void primeGenerate()
{
	for(int i=2;i<33005;i++)
	{
		if(p[i]==0)
		{
			primes.push_back(i);
			for(int j=2;j*i<33005;j++)
			{
				p[i*j]=1;
			}
		}
	}
}

int main()
{
	primeGenerate();
	
	int n;
	while(scanf("%d",&n) and n)
	{
		int l=0;
		int r=lower_bound(primes.begin(),primes.end(),n)-primes.begin();
		
		int ans=0;
		
		while(l<=r)
		{
			if(primes[l]+primes[r]>n) r--;
			else if(primes[l]+primes[r]<n) l++;
			else
			{
				ans++;r--;l++;
			}
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
