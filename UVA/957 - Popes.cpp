#include<bits/stdc++.h>

using namespace std;

int main()
{
	int yp;
	while(scanf("%d",&yp)!=EOF)
	{
		int p;
		scanf("%d",&p);
		vector<int> v(p);
		for(int i=0;i<p;i++) scanf("%d",&v[i]);
		int fPos=0,sPos=0;
		for(int i=0;i<p;i++)
		{
			int year=v[i]+yp-1;
			int l=i,r=p-1,m,j=i;
			while(l<=r)
			{
				m=(l+r)/2;
				if(v[m]<=year)
				{
					j=m;l=m+1;
				}
				else r=m-1;
			}
			if(sPos-fPos<j-i) fPos=i,sPos=j;
		}
		printf("%d %d %d\n",sPos-fPos+1,v[fPos],v[sPos]);
	}
	return 0;
}
