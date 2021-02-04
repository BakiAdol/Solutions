#include <bits/stdc++.h>

using namespace std;

const int Max = 200;

bool check[Max];
vector<int> primes;

void primeGenerate()
{
	primes.push_back(2);
	
	for(int i=3;i<Max;i+=2)
	{
		if(check[i]==0)
		{
			primes.push_back(i);
			
			for(int j=i*i;j<Max;j+=i*2) check[j]=1;
		}
	}
}

void factors(map<int,int> &factors, int m)
{
	int len=primes.size();
	for(int i=0;i<len and primes[i]<=m;i++)
		{
			while(m%primes[i]==0)
			{
				factors[primes[i]]++;
				m/=primes[i];
			}
		}
		if(m>1) factors[m]++;
}

int main()
{
    primeGenerate();
    
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
		int n,m;
		map<int,int> factorsOfM,factorsOfN;
		scanf("%d%d",&m,&n);
		
		factors(factorsOfM,m);
		
		for(int i=2;i<=n;i++)
		{
			factors(factorsOfN,i);
		}
		
		int ans=100000;
		
		for(auto x:factorsOfM)
		{
			int p=x.first;
			int cou=x.second;
			ans=min(ans,factorsOfN[p]/cou);
		}
		printf("Case %d:\n",test);
		if(ans) printf("%d\n",ans);
		else printf("Impossible to divide\n");
	}
    return 0;
}
