#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

bool isComposite[1000005];
int digitP[1000005];

void primeGenerate()
{
	isComposite[0]=isComposite[1]=1;
	for(int i=2;i<1000005;i++)
	{
		if(!isComposite[i])
		{
			lli j=i;j*=j;
			while(j<1000005)
			{
				isComposite[j]=1;
				j+=i;
			}
		}
	}
}

bool isDigitPrime(int n)
{
	int tmp=0;
	while(n)
	{
		tmp+=n%10;
		n/=10;
	}
	return !isComposite[tmp];
}

int main()
{
    primeGenerate();
    
    for(int i=2;i<1000005;i++)
    {
		digitP[i]=digitP[i-1];
		if(!isComposite[i] and isDigitPrime(i))
		{
			digitP[i]++;
		}
	}
	
	int n,l,r;
	scanf("%d",&n);
    while(n--)
    {
		scanf("%d%d",&l,&r);
		printf("%d\n",digitP[r]-digitP[l-1]);
	}
    return 0;
}
