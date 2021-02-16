#include<bits/stdc++.h>

using namespace std;

struct com{
	int a,b,c,s;
};

int n,res;
vector<com> v;
vector<int> take(15);

void f(int pos, int cou, int score)
{
	if(cou==3)
	{
		res=max(res,score);
		return;
	}
	if(pos==n) return;
	f(pos+1,cou,score);
	if(!take[v[pos].a] and !take[v[pos].b] and !take[v[pos].c])
	{
		take[v[pos].a]=take[v[pos].b]=take[v[pos].c]=true;
		f(pos+1,cou+1,score+v[pos].s);
		take[v[pos].a]=take[v[pos].b]=take[v[pos].c]=false;
	}
}

int main() 
{
	int test=0;
	com cm;
	while(scanf("%d",&n) and n)
	{
		v.clear();
		for(int i=0;i<15;i++) take[i]=0;
		res=-1;
		
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d%d",&cm.a,&cm.b,&cm.c,&cm.s);
			v.push_back(cm);
		}

		f(0,0,0);
		
		printf("Case %d: %d\n",++test,res);

	}
	
	
    return 0;
}
