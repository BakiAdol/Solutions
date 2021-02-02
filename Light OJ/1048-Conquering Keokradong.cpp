#include<bits/stdc++.h>

using namespace std;

int n,k;
vector<int> v;

bool isPossible(int x)
{
	int sum=0;
	int day=0;
	
	for(int i=0;i<n;i++)
	{
		if(x<v[i]) return false;
		if(sum+v[i]>x)
		{
			day++;sum=0;
		}
		sum+=v[i];
	}
	if(sum) day++;
	
	return day<=k;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
		scanf("%d%d",&n,&k);
		n++;k++;
		v.clear();
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			v.push_back(tmp);
		}
		
		int l=1,r=10000000,m,res;
		while(l<=r)
		{
			m=(l+r)/2;
			if(isPossible(m))
			{
				r=m-1;res=m;
			}
			else l=m+1;
		}
		printf("Case %d: %d\n",test,res);
		
		int sum=0,cou=0;
		for(int i=0;i<n;i++)
		{
			if(sum+v[i]<=res and cou+n-i>=k) sum+=v[i];
			else
			{
				printf("%d\n",sum);
				cou++;sum=v[i];
			}
		}
		if(sum) printf("%d\n",sum);
	}
    return 0;
}
