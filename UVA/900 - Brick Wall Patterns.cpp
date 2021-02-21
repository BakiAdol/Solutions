#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<lli> v(100);

lli f(int len)
{
	if(v[len]==0)
	{
		return v[len]=f(len-1)+f(len-2);
	}
	return v[len];
}

int main() 
{
	int n;
	v[0]=v[1]=1;
	while(scanf("%d",&n) and n)
	{
		printf("%lld\n",f(n));
	}
    return 0;
}
