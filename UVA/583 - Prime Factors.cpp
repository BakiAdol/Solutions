#include<bits/stdc++.h>

using namespace std;

vector<int> primes;

void primeGeneration()
{
	bool p[50000];
	for(int i=2;i<50000;i++)
	{
		if(p[i]==0)
		{
			primes.push_back(i);
			for(int j=2;i*j<50000;j++)
			{
				p[i*j]=1;
			}
		}
	}
}

int main()
{
	primeGeneration();
	int len=primes.size();
	
	int n;
	while(scanf("%d",&n) and n)
	{
		printf("%d = ",n);
		bool mul=false;
		if(n<0)
		{
			mul=true;
			n*=-1;
			printf("-1");
		}
		for(int i=0;i<len and primes[i]<=n;i++)
		{
			while(n%primes[i]==0 and n!=1)
			{
				if(mul) printf(" x ");
				printf("%d",primes[i]);
				mul=true;
				n/=primes[i];
			}
		}
		
		if(n!=1)
		{
			if(mul) printf(" x ");
			printf("%d",n);
		}
		
		printf("\n");
	}
	return 0;
}
