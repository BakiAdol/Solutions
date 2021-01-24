#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n) and n)
	{
		vector<int> v(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		
		double coprime=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(__gcd(v[i],v[j])==1) coprime++;
			}
		}
		n--;
		n=(n*(n+1))/2;
		
		if(coprime) printf("%.6lf\n",sqrt(6*n/coprime));
		else printf("No estimate for this data set.\n");
	}
	return 0;
}
