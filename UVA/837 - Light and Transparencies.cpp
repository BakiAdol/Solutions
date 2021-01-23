#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		double x1,y1,x2,y2,r;
		set<double> points;
		vector<pair<double,pair<double,double>>> v(n),ans;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&r);
			if(x1>x2) swap(x1,x2);
			points.insert(x1);
			points.insert(x2);
			v[i].first=r;
			v[i].second.first=x1;
			v[i].second.second=x2;
		}
		double lft=*points.begin();
		points.erase(points.begin());
		double flft=lft;
		for(auto rt:points)
		{
			double trans=1;
			for(int i=0;i<n;i++)
			{
				if(v[i].second.first<rt and v[i].second.second>lft)
				{
					trans*=v[i].first;
				}
			}
			ans.push_back({trans,{lft,rt}});
			lft=rt;
		}
		
		int len=ans.size();
		
		printf("%d\n",len+2);
		printf("-inf %.3lf 1.000\n",flft);
		for(int i=0;i<len;i++)
		{
			printf("%.3lf %.3lf %.3lf\n",ans[i].second.first,ans[i].second.second,ans[i].first);
		}
		printf("%.3lf +inf 1.000\n",lft);
		if(t) printf("\n");
	}
	return 0;
}
