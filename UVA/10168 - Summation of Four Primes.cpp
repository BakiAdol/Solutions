#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

bool isComposit[10000003];
vector<int> primes;
map<int,int> mFactors;
int len;

void primeGenerate()
{
	isComposit[0]=isComposit[1]=1;
	for(int i=2;i<10000003;i++)
	{
		if(!isComposit[i])
		{
			primes.push_back(i);
			for(int j=2;j*i<10000003;j++)
			{
				isComposit[i*j]=1;
			}
		}
	}
}

int findPos(int num)
{
	int pos=-1,l=0,r=len-1,m;
	
	while(l<=r)
	{
		m=(l+r)/2;
		if(primes[m]<num)
		{
			pos=m;
			l=m+1;
		}
		else r=m-1;
	}
	
	return pos;
}

bool cal(int num)
{
	for(int i=findPos(num);i>=0;i--)
	{
		int x=num-primes[i];
		for(int j=findPos(x);j>=0;j--)
		{
			int y=x-primes[j];
			for(int k=findPos(y);k>=0;k--)
			{
				int z=y-primes[k];
				if(!isComposit[z])
				{
					printf("%d %d %d %d\n",primes[i],primes[j],primes[k],z);
					return true;
				}
			}
		}
	}
	return false;
}


int main()
{
	primeGenerate();
	len=primes.size();

	int num;
	while(scanf("%d",&num)!=EOF)
	{
		if(!cal(num)) printf("Impossible.\n");
	}
	
	return 0;
}
