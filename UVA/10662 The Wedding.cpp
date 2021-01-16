#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,r,h,ansT,ansR,ansH;
	int tPrice[25],rPrice[25],hPrice[25];
	int tr[25][25],rh[25][25],ht[25][25];
	int ans,tmp;
	
	while(cin >> t >> r >> h)
	{
		for(int i=0;i<t;i++)
		{
			scanf("%d",&tPrice[i]);
			for(int j=0;j<r;j++) scanf("%d",&tr[i][j]);
		}
		for(int i=0;i<r;i++)
		{
			scanf("%d",&rPrice[i]);
			for(int j=0;j<h;j++) scanf("%d",&rh[i][j]);
		}
		for(int i=0;i<h;i++)
		{
			scanf("%d",&hPrice[i]);
			for(int j=0;j<t;j++) scanf("%d",&ht[i][j]);
		}
		ans=INT_MAX;
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<r;j++)
			{
				if(tr[i][j]) continue;
				for(int k=0;k<h;k++)
				{
					if(rh[j][k]) continue;
					if(ht[k][i]) continue;
					tmp=tPrice[i]+rPrice[j]+hPrice[k];
					if(tmp<ans)
					{
						ans=tmp;
						ansT=i;ansR=j;ansH=k;
					}
				}
			}
		}
		if(ans==INT_MAX)printf("Don't get married!\n");
		else printf("%d %d %d: %d\n",ansT,ansR,ansH,ans);
	}
	
	return 0;
}

