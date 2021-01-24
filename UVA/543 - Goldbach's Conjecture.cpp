#include<bits/stdc++.h>

using namespace std;

vector<int> primes;
bool p[1000005];

void primeGenerate()
{
	for(int i=2;i<1000005;i++)
	{
		if(p[i]==0)
		{
			primes.push_back(i);
			for(int j=2;j*i<1000005;j++)
			{
				p[i*j]=1;
			}
		}
	}
}

int main()
{
	primeGenerate();
	primes.erase(primes.begin());
	
	int n;
	while(scanf("%d",&n) and n)
	{
		int l=0;
		int r=lower_bound(primes.begin(),primes.end(),n)-primes.begin();
		
		while(l<=r)
		{
			if(primes[l]+primes[r]>n) r--;
			else if(primes[l]+primes[r]<n) l++;
			else break;
		}
		if(l>r) printf("Goldbach's conjecture is wrong.\n");
		else printf("%d = %d + %d\n",n,primes[l],primes[r]);
	}
	return 0;
}
