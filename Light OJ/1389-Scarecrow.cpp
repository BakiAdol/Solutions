#include<bits/stdc++.h>

using namespace std;

int main() 
{
	int t;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		int n,ans=0;
		bool cover=false;
		cin >>n;
		char place[n];
		for(int i=0;i<n;i++) cin >> place[i];
		for(int i=0;i<n;i++)
		{
			if(place[i]=='.')
			{
				if(cover) cover=false;
				else
				{
					ans++;
					cover=true;
					i++;
				}
			}
			else
			{
				if(cover) cover=false;
			}
		}
		
		cout << "Case " << test <<": " << ans << endl;
	}
    return 0;
}
