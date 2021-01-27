#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

int maxN=18410000;

bool isComposit[18410000];
vector<int> primes;
int len;

void primeGenerate()
{
	isComposit[0]=isComposit[1]=1;
	for(int i=2;i<maxN;i++)
	{
		if(!isComposit[i])
		{
			primes.push_back(i);
			lli j=i;j*=j;
			while(j<maxN)
			{
				isComposit[j]=1;
				j+=i;
			}
		}
	}
}


int main()
{
	primeGenerate();
	len=primes.size();
	
	vector<pair<int,int>> v;
	v.push_back({0,0});
	
	for(int i=1;i<len;i++)
	{
		if(primes[i]-primes[i-1]==2)
		{
			v.push_back({primes[i-1],primes[i]});
		}
	}
	
	int n;
	
	while(scanf("%d",&n)!=EOF)
	{
		printf("(%d, %d)\n",v[n].first,v[n].second);
	}
	
	/** vector<int> v, store only first prime of a twin
	 *  res = (v[n], v[n]+2)
	 * **/
	
	return 0;
}
