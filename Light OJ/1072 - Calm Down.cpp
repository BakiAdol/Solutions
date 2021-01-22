#include<bits/stdc++.h>

#define pi acos(-1)

using namespace std;

int main()
{
	int test;
	scanf("%d",&test);
	for(int t=1;t<=test;t++)
	{
		double R,n;
		scanf("%lf%lf",&R,&n);
		
		double sinAngle = sin(pi/n);
		
		double r=(R*sinAngle)/(1+sinAngle);
		
		printf("Case %d: %.6lf\n",t,r);
	}
	return 0;
}
