#include <bits/stdc++.h>

using namespace std;

char land[25][25];
bool visited[25][25];

int dfs(int i, int j)
{
	visited[i][j]=true;
	int res=0;
	if(land[i+1][j]=='.' and !visited[i+1][j]) res+=1+dfs(i+1,j);
	if(land[i][j+1]=='.' and !visited[i][j+1]) res+=1+dfs(i,j+1);
	if(land[i-1][j]=='.' and !visited[i-1][j]) res+=1+dfs(i-1,j);
	if(land[i][j-1]=='.' and !visited[i][j-1]) res+=1+dfs(i,j-1);
	return res;
}

int main()
{
	int t;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		int w,h,x,y;
		cin >> h >> w;
		for(int i=0;i<25;i++)
		for(int j=0;j<25;j++)
		{
			visited[i][j]=false;
			land[i][j]='#';
		}
		
		for(int i=1;i<=w;i++)
		{
			for(int j=1;j<=h;j++)
			{
				cin >> land[i][j];
				if(land[i][j]=='@') x=i,y=j;
			}
		}
		
		int ans=dfs(x,y);
		cout << "Case "<< test << ": " << ans+1 << endl;
	}
 	return 0;
}
