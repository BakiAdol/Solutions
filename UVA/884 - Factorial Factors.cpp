#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

bool isComposit[1000005];
vector<int> primes;
int factors[1000005];
int len;

void primeGenerate()
{
	for(int i=2;i<1000005;i++)
	{
		if(!isComposit[i])
		{
			primes.push_back(i);
			for(int j=2;j*i<1000005;j++)
			{
				isComposit[i*j]=1;
			}
		}
	}
}

void cal(int pos,lli num)
{
	for(int i=pos;i<len;i++)
	{
		if(num*primes[i]<=1000000)
		{
			factors[num*primes[i]]=factors[num]+1;
			cal(i,num*primes[i]);
		}
		else return;
	}
}

int main()
{
	primeGenerate();
	len=primes.size();
	cal(0,1);
	for(int i=2;i<1000001;i++)
	{
		factors[i]+=factors[i-1];
	}
	
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",factors[n]);
	}
	return 0;
}
