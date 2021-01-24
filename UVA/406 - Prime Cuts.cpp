#include<bits/stdc++.h>

using namespace std;

vector<int> primes;
bool p[1005];

void primeGeneration()
{
	primes.push_back(1);
	for(int i=2;i<1005;i++)
	{
		if(p[i]==0)
		{
			primes.push_back(i);
			for(int j=2;j*i<1005;j++)
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
	int n,c,l,r;
	
	while(scanf("%d %d",&n,&c)!=EOF)
	{
		l=0;r=len-1;
		while(primes[r]>n) r--;
		int x=c;
		c*=2;
		if((r-l+1)&1) c--;
		while(r-l+1>c)
		{
			r--;
			if(r-l+1>c) l++;
		}
		printf("%d %d:",n,x);
		while(l<=r) printf(" %d",primes[l++]);
		printf("\n\n");
	}
	return 0;
}
