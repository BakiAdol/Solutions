#include<bits/stdc++.h>

using namespace std;

string s;
vector<int> v(200);

void ini()
{
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='1') v[len-i-1]++;
	}
}

int main()
{
	int t=0;
	while(cin >> s)
	{
		fill(v.begin(),v.end(),0);
		ini();
		cin >> s;
		ini();
		
		for(int i=0;i<200;i++)
		{
			if(i and v[i] and v[i-1])
			{
				v[i]--;v[i-1]--;
				v[i+1]++;
			}
			
			if(v[i]>1)
			{
				if(i==0)
				{
					v[0]-=2;
					v[1]++;
					i--;
				}
				else if(i==1)
				{
					v[1]-=2;
					v[0]++;
					v[2]++;
					i=-1;
				}
				else if(i==2)
				{
					v[2]-=2;
					v[3]++;
					v[0]++;
					i=-1;
				}
				else
				{
					v[i]-=2;
					v[i-2]++;
					v[i+1]++;
					i-=3;
				}
			}
		}
		
		if(t) cout << endl;
		t=1;
		
		int pos=0;
		for(int i=198;i>=0;i--)
		{
			if(v[i])
			{
				pos=i;break;
			}
		}
		
		for(int i=pos;i>=0;i--)
		{
			if(v[i]) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
	
    return 0;
}
