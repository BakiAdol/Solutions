#include<bits/stdc++.h>

using namespace std;

int n,h;

void cal(string s, int pos, int one)
{
	if(h-one>n-pos+1) return;
	if(pos==n)
	{
		if(one==h)
		{
			for(int i=0;i<n;i++) cout << s[i];
			cout << endl;
		}
		return;
	}
	cal(s,pos+1,one);
	s[pos]='1';
	cal(s,pos+1,one+1);
}

int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		if(i) cout << endl;
		cin >> n>> h;
		cal("0000000000000000",0,0);
	}
	return 0;
}

