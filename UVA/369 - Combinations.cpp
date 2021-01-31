#include<bits/stdc++.h>

using namespace std;

double nCr(double n, double r)
{
	double res=1;
	for(double i=1;i<=r;i++)
	{
		res*=n+1-i;
		res/=i;
	}
	return res;
}

int main()
{
    double n,r;
    while(scanf("%lf%lf",&n,&r) and n)
    {
		printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",n,r,nCr(n,r));
	}
    return 0;
}
