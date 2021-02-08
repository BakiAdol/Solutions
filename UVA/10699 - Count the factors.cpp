#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

void primeGenerate()
{
	int range=100000;
	bool check[range];
	
	primes.push_back(2);
	
	for(long long int i=3;i<range;i+=2)
	{
		if(check[i]==0)
		{
			primes.push_back(i);
			for(long long int j=i*i;j<range;j+=i*2) check[j]=1;
		}
	}
}

int main()
{
    primeGenerate();
	
	int len=primes.size();
	int n;
	
	
	while(scanf("%d",&n) and n)
	{
		int tmp=n;
		int ans=0;
		for(int i=0;i<len and tmp>=primes[i];i++)
		{
			int x=0;
			while(tmp%primes[i]==0)
			{
				x=1;
				tmp/=primes[i];
			}
			ans+=x;
		}
		if(tmp>1) ans++;
		printf("%d : %d\n",n,ans);
	}
	
    return 0;
}
