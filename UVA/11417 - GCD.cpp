#include<bits/stdc++.h>

using namespace std;

int main() 
{
	int n;
	while(scanf("%d",&n) and n)
	{
		int G=0;
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			G+=__gcd(i,j);
		}

		printf("%d\n",G);
	}
    return 0;
}
