#include<bits/stdc++.h>

using namespace std;

bool isComposit[105];
vector<int> primes;
int cou[101];

void primeGenerate()
{
	for(int i=2;i<105;i++)
	{
		if(!isComposit[i])
		{
			primes.push_back(i);
			for(int j=2;j*i<105;j++)
			{
				isComposit[i*j]=1;
			}
		}
	}
}

int main()
{
	int n;
	primeGenerate();
	while(scanf("%d",&n) and n)
	{
		memset(cou,0,sizeof(cou));
		
		for(int i=2;i<=n;i++)
		{
			int x=i;
			for(int j=0;x>=primes[j];j++)
			{
				while(x%primes[j]==0)
				{
					cou[primes[j]]++;x/=primes[j];
				}
			}
			if(x>1) cou[x]++;
		}
		printf("%*d! =",3,n);
		int r=100;
		while(cou[r]==0)r--;
		int res=0;
		for(int i=2;i<=r;i++)
		{
			if(isComposit[i]==0)
			{
				if(res%15==0 and res) printf("\n      ");
				res++;
				printf("%*d",3,cou[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
