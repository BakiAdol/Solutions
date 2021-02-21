#include<bits/stdc++.h>

using namespace std;

int egcd(int a, int b, int &x, int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int x1,y1;
	int gcd=egcd(b,a%b,x1,y1);
	x=y1;
	y=x1-y1*(a/b);
	return gcd;
}

int main() 
{
	int a,b,x,y;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		int gcd=egcd(a,b,x,y);
		printf("%d %d %d\n",x,y,gcd);
	}
    return 0;
}
