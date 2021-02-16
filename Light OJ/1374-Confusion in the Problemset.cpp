#include<bits/stdc++.h>

using namespace std;

map<int,int> mp; 

bool f(int n)
{
	for(int i=0;i<n;i++)
	{
		if(mp[i]) mp[i]--;
		else if(mp[n-i-1]) mp[n-i-1]--;
		else return false;
	}
	return true;
}

int main() 
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int n;
		mp.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int tmp;
			scanf("%d",&tmp);
			mp[tmp]++;
		}
		
		printf("Case %d: %s\n",test,f(n)?"yes":"no");
	}
    return 0;
}
