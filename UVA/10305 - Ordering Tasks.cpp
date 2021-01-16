#include<bits/stdc++.h>

using namespace std;

int n,m,u,v;

vector<int> adj[105];
stack<int> res;

bool visited[105];

void dfs(int node)
{
	visited[node]=1;
	
	for(int i=0;i<(int)adj[node].size();i++)
	{
		if(visited[adj[node][i]]==0) dfs(adj[node][i]);
	}
	
	res.push(node);
}

int main()
{
	while(scanf("%d%d",&n,&m) and (n>0 or m>0))
	{
		for(int i=1;i<101;i++) adj[i].clear();
		memset(visited,0,sizeof(visited));
		
		while(m--)
		{
			scanf("%d%d",&u,&v);
			adj[u].push_back(v);
		}
		
		for(int i=1;i<=n;i++) if(!visited[i]) dfs(i);
		
		printf("%d",res.top());
		res.pop();
		
		while(!res.empty())
		{
			printf(" %d",res.top());
			res.pop();
		}
		puts("");
	}
    
	return 0;
}
