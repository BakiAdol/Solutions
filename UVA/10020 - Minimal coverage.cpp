#include <bits/stdc++.h>

using namespace std;

#define     ff                          first
#define     ss                          second

int main()
{
    int t,fs=0;
    scanf("%d",&t);
    while(t--)
    {
		int m,n=0,a,b;
		scanf("%d",&m);
		vector<pair<pair<int,int>,int>> v;
		v.push_back({{-100000000,-100000000},0});
		while(scanf("%d%d",&a,&b) and (a or b))
		{
			v.push_back({{a,b},0});
		}
		n=v.size();
		sort(v.begin(),v.end());
		
		for(int i=1;i<n;i++)
		{
			if(v[i].ff.ss>v[v[i-1].ss].ff.ss) v[i].ss=i;
			else v[i].ss=v[i-1].ss;
		}
		
		vector<pair<int,int>> ans;
		
		int cover=0;
		int pos=0;
		while(cover<m)
		{
			while(pos+1<n and v[pos+1].ff.ff<=cover) pos++;
			int p=v[pos].ss;
			
			if(v[p].ff.ss>cover)
			{
				ans.push_back({v[p].ff.ff,v[p].ff.ss});
				cover=v[p].ff.ss;
			}
			else break;
		}
		
		if(fs) printf("\n");
		fs=1;
		
		if(cover<m) printf("0\n");
		else
		{
			int len=ans.size();
			printf("%d\n",len);
			for(int i=0;i<len;i++)
			{
				printf("%d %d\n",ans[i].ff,ans[i].ss);
			}
		}
	}
    return 0;
}
