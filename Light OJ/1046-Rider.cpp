#include<bits/stdc++.h>

using namespace std;

int n,m;
char board[12][12];
int ans[12][12];
int cou[12][12];
bool visited[12][12];

int cx[]={1,1,2,2,-1,-1,-2,-2};
int cy[]={2,-2,1,-1,2,-2,1,-1};

bool isValid(int i, int j)
{
	if(i<0 or j<0 or i>=m or j>=n) return false;
	if(visited[i][j]) return false;
	return true;
}

void bfs(int i, int j, int who)
{
	queue<pair<int,pair<int,int>>> q;
	q.push({0,{i,j}});
	visited[i][j]=true;
	cou[i][j]++;
	
	while(!q.empty())
	{
		int moves=q.front().first+1;
		int x=q.front().second.first;
		int y=q.front().second.second;
		q.pop();
		
		for(i=0;i<8;i++)
		{
			int xi=x+cx[i];
			int yi=y+cy[i];
			if(isValid(xi,yi))
			{
				visited[xi][yi]=true;
				cou[xi][yi]++;
				ans[xi][yi]+=moves/who +(moves%who ? 1 :0);
				q.push({moves,{xi,yi}});
			}
		}
	}
}

int main() 
{
	int t;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		cin >> m >> n;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> board[i][j];
				ans[i][j]=cou[i][j]=0;
			}
		}
		
		int total=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]!='.')
				{
					total++;
					memset(visited,0,sizeof(visited));
					bfs(i,j,board[i][j]-'0');
				}
				
			}
		}
		int res=100000;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(total==cou[i][j])
				{
					res=min(res,ans[i][j]);
				}
			}
		}
		if(res==100000) res=-1;
		cout << "Case " << test << ": " << res << endl;
	}
    return 0;
}
