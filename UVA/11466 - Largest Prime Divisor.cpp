#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main()
{
	lli n;
	while(scanf("%lld",&n) and n)
	{
		vector<lli> div;
		n=abs(n);
		for(lli i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				div.push_back(i);
				while(n%i==0) n/=i;
			}
		}
		if(n>1) div.push_back(n);
		int len=div.size();
		if(len>1) printf("%lld\n",div[len-1]);
		else printf("-1\n");
	}
    return 0;
}
