#include<bits/stdc++.h>

using namespace std;

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int capacity, travelTime, cars;
		scanf("%d%d%d",&capacity,&travelTime,&cars);
		
		int extra=cars%capacity;
		
		int netTime,trips,load, arriveTime, fres;
		netTime=trips=load=0;fres=1;
		
		for(int i=0;i<cars;i++)
		{
			scanf("%d",&arriveTime);
			
			if(load==capacity or(fres and i%capacity>=extra and i and extra))
			{
				fres=0;
				netTime+=travelTime*2;
				load=1;
				trips++;
				netTime=max(netTime,arriveTime);
			}
			else
			{
				load++;
				netTime=max(netTime,arriveTime);
			}
		}
		trips++;
		netTime+=travelTime;
		
		printf("%d %d\n",netTime,trips);
	}
    return 0;
}
