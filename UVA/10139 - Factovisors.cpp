#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

bool isComposit[46350];
vector<int> primes;
map<int,int> mFactors;
int len;

void primeGenerate()
{
	for(int i=2;i<46350;i++)
	{
		if(!isComposit[i])
		{
			primes.push_back(i);
			for(int j=2;j*i<46350;j++)
			{
				isComposit[i*j]=1;
			}
		}
	}
}

void factorizeOfM(int m)
{
	for(int i=0;i<len and primes[i]<=m;i++)
	{
		while(m%primes[i]==0)
		{
			mFactors[primes[i]]++;
			m/=primes[i];
		}
	}
	if(m>1) mFactors[m]++;
}

bool check(int n)
{
	for(auto x:mFactors)
	{
		lli p=x.first;
		int need=x.second;
		
		while(p<=n)
		{
			int tmp=p;
			while(tmp%x.first==0)
			{
				tmp/=x.first;need--;
			}
			if(need<=0) break;
			p+=x.first;
		}
		
		if(need>0) return false;
	}
	return true;
}


int main()
{
	primeGenerate();
	len=primes.size();
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		mFactors.clear();
		factorizeOfM(m);
		if(check(n)) printf("%d divides %d!\n",m,n);
		else printf("%d does not divide %d!\n",m,n);
	}
	return 0;
}
