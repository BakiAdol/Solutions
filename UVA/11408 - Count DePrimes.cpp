#include<bits/stdc++.h>

using namespace std;

int mx=5000010;
vector<bool> prime(mx);
vector<int> facSums(mx);
vector<int> countde(mx);

void f()
{
	for(int i=2;i<mx;i++)
	{
		if(prime[i]==0)
		{
			facSums[i]+=i;
			for(int j=2*i;j<mx;j+=i)
			{
				prime[j]=1;
				facSums[j]+=i;
			}
		}
	}
	for(int i=2;i<mx;i++)
	{
		countde[i]=1-prime[facSums[i]];
		countde[i]+=countde[i-1];
	}
}

int main()
{
	f();
	int l,r;
	while(scanf("%d",&l) and l)
	{
		scanf("%d",&r);
		printf("%d\n",countde[r]-countde[l-1]);
	}
    return 0;
}
