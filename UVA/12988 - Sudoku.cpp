#include <bits/stdc++.h>

using namespace std;

char board[4][4];

bool sudoku(int star)
{
	if(star==0)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
		return true;
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]=='*')
			{
				for(char num='1';num<'5';num++)
				{
					if(board[i][0]==num or board[i][1]==num or board[i][2]==num or board[i][3]==num) continue;
					if(board[0][j]==num or board[1][j]==num or board[2][j]==num or board[3][j]==num) continue;
					
					if(i<2)
					{
						if(j<2)
						{
							if(board[0][0]==num or board[0][1]==num or board[1][0]==num or board[1][1]==num) continue;
						}
						else
						{
							if(board[0][2]==num or board[0][3]==num or board[1][2]==num or board[1][3]==num) continue;
						}
					}
					else
					{
						if(j<2)
						{
							if(board[2][0]==num or board[2][1]==num or board[3][0]==num or board[3][1]==num) continue;
						}
						else
						{
							if(board[2][2]==num or board[2][3]==num or board[3][2]==num or board[3][3]==num) continue;
						}
					}
					
					board[i][j]=num;
					if(sudoku(star-1)) return true;
					board[i][j]='*';
				}
			}
			if(board[i][j]=='*') return false;
		}
	}
	return false;
}

int main() 
{ 
	int t,star;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		star=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				cin >> board[i][j];
				if(board[i][j]=='*') star++;
			}
		}
		cout << "Case #" << test << ":\n";
		sudoku(star);
	}
	return 0;
} 
