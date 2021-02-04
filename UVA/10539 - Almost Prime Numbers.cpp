#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

const int Max = 1000005;

bool check[Max];
vector<lli> primes;

void primeGenerate()
{
	primes.push_back(2);
	
	for(long long int i=3;i<Max;i+=2)
	{
		if(check[i]==0)
		{
			primes.push_back(i);
			
			for(long long int j=i*i;j<Max;j+=i*2) check[j]=1;
		}
	}
}

int main()
{
    primeGenerate();
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
		lli l,r,ans=0;
		scanf("%lld%lld",&l,&r);
		for(int i=0;primes[i]*primes[i]<=r;i++)
		{
			lli num=primes[i];
			num*=primes[i];
			while(num<=r)
			{
				if(num>=l) ans++;
				num*=primes[i];
			}
			
		}
		printf("%lld\n",ans);
	}
    
    return 0;
}
