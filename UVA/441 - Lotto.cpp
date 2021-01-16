#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v(15);

void f(int pos,vector<int> x)
{
	if(x.size()==6)
	{
		for(int i=0;i<6;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",x[i]);
		}
		printf("\n");
	}
	for(int i=pos;i<n;i++)
	{
		x.push_back(v[i]);
		f(i+1,x);
		x.pop_back();
	}
}

int main()
{
	bool blank=false;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		if(blank) printf("\n");
		blank=true;
		vector<int> x;
		f(0,x);
	}
	
	return 0;
}

