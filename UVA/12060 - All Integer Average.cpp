#include<bits/stdc++.h>

using namespace std;

int spaceCount(int num)
{
	int space=0;
	while(num) num/=10,space++;
	return space;
}

int main()
{
	int n,tmp,sum,t=0,x,y,gcd;
	while(scanf("%d",&n) and n)
	{
		sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			sum+=tmp;
		}
		printf("Case %d:\n",++t);
		if(sum%n)
		{
			bool neg=false;
			int negSpace=0;
			if(sum<0) neg=true,negSpace=2;
			
			sum=abs(sum);
			gcd=__gcd(sum,n);
			x=(sum%n)/gcd;
			y=n/gcd;
			
			int spaceNum=spaceCount(sum/n);
			int bigSpace=spaceCount(max(x,y));

			printf("%*d\n",negSpace+spaceNum+bigSpace,x);
			
			if(neg) printf("- ");
			if(sum/n) printf("%d",sum/n);
			for(int i=0;i<bigSpace;i++) printf("-");
			printf("\n");
			
			printf("%*d\n",negSpace+spaceNum+bigSpace,y);
		}
		else if(sum<0) printf("- %d\n",abs(sum/n));
		else printf("%d\n",sum/n);
	}
	return 0;
}
