#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,test=0;
    scanf("%d",&t);
    while(t--)
    {
		int n;
		scanf("%d",&n);
		vector<int> ours(n),oppo(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&ours[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&oppo[i]);
		}
		sort(ours.begin(),ours.end());
		sort(oppo.begin(),oppo.end());
		
		int points=0;
		
		while(--n)
		{
			if(ours.back()>oppo.back())
			{
				points+=2;
				ours.pop_back();
				oppo.pop_back();
			}
			else if(ours.back()<oppo.back())
			{
				oppo.pop_back();
				ours.erase(ours.begin());
			}
			else
			{
				if(ours[0]<oppo[0])
				{
					oppo.pop_back();
					ours.erase(ours.begin());
				}
				else if(ours[0]>oppo[0])
				{
					points+=2;
					ours.erase(ours.begin());
					oppo.erase(oppo.begin());
				}
				else
				{
					points+= ours[0]==oppo.back();
					oppo.pop_back();
					ours.erase(ours.begin());
				}
			}
		}
		
		points +=ours[0]>oppo[0]?2:ours[0]==oppo[0]?1:0;;
		
		printf("Case %d: %d\n",++test,points);
	}
    return 0;
}
