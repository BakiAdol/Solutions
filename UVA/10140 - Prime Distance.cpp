#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

bool p[1000005];
vector<lli> primes,pList;
lli U,L;

void primeGenerate()
{
	for(int i=2;i<46350;i++)
	{
		if(!p[i])
		{
			primes.push_back(i);
			for(int j=2;i*j<46350;j++)
			{
				p[i*j]=1;
			}
		}
	}
}

void segmentedSeive()
{
	for(int i=0;primes[i]*primes[i]<=U;i++)
	{
		lli x=L/primes[i];x*=primes[i];
		if(L%primes[i]) x+=primes[i];
		if(x==primes[i]) x+=primes[i];
		while(x<=U)
		{
			p[x-L]=1;
			x+=primes[i];
		}
	}

	for(lli i=L;i<=U;i++)
	{
		if(!p[i-L]) pList.push_back(i);
	}
}


int main()
{
	primeGenerate();
	
	while(scanf("%lld%lld",&L,&U)!=EOF)
	{
		memset(p,0,sizeof(p));
		pList.clear();
		if(L==1)L++;
		segmentedSeive();
		
		int len=pList.size();
		
		if(len<2) printf("There are no adjacent primes.\n");
		else
		{
			int mi,mj,maxi,maxj;
			mi=maxi=0;mj=maxj=1;
			for(int i=2;i<len;i++)
			{
				if(pList[mj]-pList[mi]>pList[i]-pList[i-1])
				{
					mj=i;mi=i-1;
				}
				if(pList[maxj]-pList[maxi]<pList[i]-pList[i-1])
				{
					maxj=i;maxi=i-1;
				}
			}
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",pList[mi],pList[mj],pList[maxi],pList[maxj]);
		}
	}
	return 0;
}
