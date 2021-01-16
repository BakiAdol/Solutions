#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t,n,x1,y1,z1,x2,y2,z2,a,b,c;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		scanf("%d",&n);
		x1=y1=z1=1;
		x2=y2=z2=1000;
		
		while(n--)
		{
			scanf("%d%d%d",&a,&b,&c);
			x1=max(x1,a);
			y1=max(y1,b);
			z1=max(z1,c);
			
			scanf("%d%d%d",&a,&b,&c);
			x2=min(x2,a);
			y2=min(y2,b);
			z2=min(z2,c);
		}
		
		printf("Case %d: ",test);
		if(x1>x2 or y1>y2 or z1>z2) printf("0\n");
		else printf("%d\n",abs(x1-x2)*abs(y1-y2)*abs(z1-z2));
	}
	return 0;
}

