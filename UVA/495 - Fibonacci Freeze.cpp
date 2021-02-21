#include<bits/stdc++.h>

using namespace std;

int ar[5005][1060];
int pos[5005];

void pc()
{
	memset(ar,0,sizeof(ar));
	pos[1]=pos[0]=0;
	ar[0][0]=ar[1][0]=1;
	for(int i=2;i<5001;i++)
	{
		int c=0;
		for(int j=0;j<=pos[i-1];j++)
		{
			c+=ar[i-1][j]+ar[i-2][j];
			ar[i][j]=c%10;
			c/=10;	
		}
		pos[i]=pos[i-1];
		if(c)
		{
			pos[i]++;
			ar[i][pos[i]]=c;
		}
	}
}

int main() 
{
	int n;
	pc();
	while(scanf("%d",&n)!=EOF)
	{
		printf("The Fibonacci number for %d is ",n);
		if(!n)
		{
			printf("0\n");
			continue;
		}
		n--;
		for(int i=pos[n];i>=0;i--)
		{
			printf("%d",ar[n][i]);
		}
		printf("\n");
	}
    return 0;
}
