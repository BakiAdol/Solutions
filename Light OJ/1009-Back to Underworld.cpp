#include <bits/stdc++.h>

using namespace std;

vector<int> adj[20005];
bool visited[20005];
bool which[20005];

int bfs(int node)
{
	int vam=1,lykan=0;
	queue<int> q;
	visited[node]=true;
	q.push(node);
	which[node]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto x:adj[u])
		{
			if(!visited[x])
			{
				visited[x]=true;
				q.push(x);
				if(which[u]==1)
				{
					which[x]=0;
					lykan++;
				}
				else
				{
					which[x]=1;
					vam++;
				}
			}
		}
	}
	return max(vam,lykan);
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<=20005;i++)
		{
			adj[i].clear();
			visited[i]=false;
		}
		for(int i=0;i<n;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans=0;
		for(int i=0;i<20005;i++)
		{
			if(!adj[i].empty() and !visited[i])
			{
				ans+=bfs(i);
			}
		}
		printf("Case %d: %d\n",test,ans);
	}
 	return 0;
}
