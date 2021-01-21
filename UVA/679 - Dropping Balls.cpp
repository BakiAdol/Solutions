#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int d,i;
		scanf("%d%d",&d,&i);
		int leaf=pow(2,d-1);
		int pos=1;
		while(pos<leaf)
		{
			pos=pos*2 +1;
			if(i&1) pos--,i++;
			i/=2;
		}
		printf("%d\n",pos);
	}
	scanf("%d",&t);
	return 0;
}
