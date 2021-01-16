#include<bits/stdc++.h>

using namespace std;

int n,m;

int cx[]={0, 0,-1, 1};
int cy[]={1,-1, 0, 0};

int area[105][105],memo[105][105];

bool isValid(int x, int y, int nx, int ny)
{
	if(nx<0 or ny<0 or nx==n or ny==m) return false;
	return area[x][y]>area[nx][ny];
}

int dp(int x, int y)
{
	int &ret=memo[x][y];
	if(ret!=-1) return ret;
	ret=1;
	
	for(int i=0;i<4;i++)
	{
		int nx=x+cx[i];
		int ny=y+cy[i];
		
		if(isValid(x,y,nx,ny))
		{
			ret=max(ret,1+dp(nx,ny));
		}
	}
	
	return ret;
}

int main()
{
	int t;
	cin >> t;
	string s;
	while(t--)
	{
		cin >> s >> n >> m;
		for(int i=0;i<n;i++)
		{	
			for(int j=0;j<m;j++)
			{
				cin >> area[i][j];
			}
		}
		
		memset(memo,-1,sizeof(memo));
		
		int ans=0;
		
		for(int i=0;i<n;i++)
		{	
			for(int j=0;j<m;j++)
			{
				ans=max(ans,dp(i,j));
			}
		}
		
		cout << s << ": " << ans << endl;
	}
	return 0;
}

