#include<bits/stdc++.h>

using namespace std;

void f(int x, int y)
{
	if(x==y) return;
	f(x/10,y/10);
	printf("%d",y%10);
}

int main()
{
	int n,x,y,tmp,t=0;
	while(scanf("%d",&n) and n)
	{
		printf("Case %d:\n",++t);
		scanf("%d",&x);
		y=x;
		while(--n)
		{
			scanf("%d",&tmp);
			if(y+1<tmp)
			{
				if(x==y) printf("0%d\n",x);
				else
				{
					printf("0%d-",x);
					f(x,y);
					printf("\n");
				}
				x=y=tmp;
			}
			else y=tmp;
		}
		if(x==y) printf("0%d\n",x);
		else
		{
			printf("0%d-",x);
			f(x,y);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
