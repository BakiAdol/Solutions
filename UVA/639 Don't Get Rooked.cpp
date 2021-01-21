#include<bits/stdc++.h>

using namespace std;

char ar[4][4];
bool place[4][4];
int n;

bool isValid(int i, int j)
{
	if(ar[i][j]=='X') return false;
	int x=i-1;
	while(x>=0)
	{
		if(ar[x][j]=='X') break;
		if(place[x][j]) return false;
		x--;
	}
	x=i+1;
	while(x<n)
	{
		if(ar[x][j]=='X') break;
		if(place[x][j]) return false;
		x++;
	}
	x=j-1;
	while(x>=0)
	{
		if(ar[i][x]=='X') break;
		if(place[i][x]) return false;
		x--;
	}
	x=j+1;
	while(x<n)
	{
		if(ar[i][x]=='X') break;
		if(place[i][x]) return false;
		x++;
	}
	return true;
}

int f(int i, int j)
{
	if(j==n) return f(i+1,0);
	if(i==n) return 0;
	int p=f(i,j+1);
	if(isValid(i,j))
	{
		place[i][j]=true;
		p=max(p,1+f(i,j+1));
		place[i][j]=false;
	}
	return p;
}

int main()
{
	while(cin >> n and n)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin >> ar[i][j];
		cout << f(0,0) << endl;
	}
	return 0;
}
