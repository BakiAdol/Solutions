#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int len;
vector<lli> primes;
vector<int> mu(1000005,0),M(1000005);

void primeGenerate()
{
	lli range=1000001;
	bool check[range];
	
	primes.push_back(2);
	
	for(lli i=3;i<range;i+=2)
	{
		if(check[i]==0)
		{
			primes.push_back(i);
			for(lli j=i*i;j<range;j+=i*2) check[j]=1;
		}
	}
}

void f()
{
	for(int x=2;x<1000001;x++)
	{
		int num=x;
		int facts=0,uniq=0;
		for(int i=0;primes[i]*primes[i]<=num;i++)
		{
			int a=0;
			while(num%primes[i]==0)
			{
				num/=primes[i];
				facts++;
				a=1;
			}
			uniq+=a;
		}
		if(num>1) uniq++,facts++;
		
		if(uniq!=facts) mu[x]=0;
		else if(uniq&1) mu[x]=-1;
		else mu[x]=1;
	}
}

int main()
{
    primeGenerate();
	
	len=primes.size();
	
	f();
	mu[1]=M[1]=1;
	
	for(int i=2;i<1000001;i++)
	{
		M[i]=M[i-1]+mu[i];
	}
	
	int n;
	while(scanf("%d",&n) and n)
	{
		printf("%*d%*d%*d\n",8,n,8,mu[n],8,M[n]);
	}
    return 0;
}
