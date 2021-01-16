#include<bits/stdc++.h>

using namespace std;

int n;

bool isPrime(int num)
{
	for(int i=2;i<num;i++)
	{
		if(num%i==0) return false;
	}
	
	return true;
}

void f(vector<int> v, int mask)
{
	if(mask==(1<<n)-1)
	{
		if(!isPrime(v.back()+1)) return;
		for(int i=0;i<n;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",v[i]);
		}
		printf("\n");return;
	}
	for(int i=2;i<=n;i++)
	{
		if((mask&(1<<(i-1)))==0 and isPrime(v.back()+i))
		{
			v.push_back(i);
			f(v,mask|(1<<(i-1)));
			v.pop_back();
		}
	}
}

int main()
{
	int t=0;
	vector<int> v;
	v.push_back(1);
	while(scanf("%d",&n)!=EOF)
	{
		if(t) printf("\n");
		printf("Case %d:\n",++t);
		f(v,1);
	}
	return 0;
}

