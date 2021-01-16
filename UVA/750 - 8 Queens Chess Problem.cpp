#include <bits/stdc++.h>

using namespace std;

bool visited[10][10];

vector<vector<int>> ans;

bool isValid(int r, int c)
{
	for(int i=1;i<9;i++)
	{
		if(visited[i][c]) return false;
	}
	for(int i=r-1,j=c-1;i>0 and j>0;i--,j--)
	{
		if(visited[i][j]) return false;
	}
	for(int i=r-1,j=c+1;i>0 and j<9;i--,j++)
	{
		if(visited[i][j]) return false;
	}
	return true;
}

bool queen(int row, vector<int> col)
{
	if(row>8)
	{
		ans.push_back(col);
		return false;
	}
	
	for(int c=1;c<9;c++)
	{
		if(isValid(row,c))
		{
			visited[row][c]=1;
			col.push_back(c);
			if(queen(row+1,col)) return true;
			col.pop_back();
			visited[row][c]=0;
		}
	}
	return false;
}

int main() 
{ 
	vector<int> v;
	queen(1,v);
	
	int t,n,m,cou;
	scanf("%d",&t);
	
	for(int test=1;test<=t;test++)
	{
		scanf("%d%d",&n,&m);
		
		if(test>1) puts("");
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		
		cou=0;
		for(int i=0;i<(int)ans.size();i++)
		{
			if(ans[i][m-1]==n)
			{
				printf("%2d     ",++cou);
				for(int j=0;j<8;j++)
				{
					printf(" %d",ans[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
} 
