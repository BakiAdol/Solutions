#include<bits/stdc++.h>

using namespace std;

string dict[100];
string s;
int n,len;

void generatePass(int pos, string pass)
{
	if(pos==len)
	{
		cout << pass << endl;return;
	}
	if(s[pos]=='0')
	{
		for(char c='0';c<='9';c++)
		{
			generatePass(pos+1,pass+c);
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			generatePass(pos+1,pass+dict[i]);
		}
	}
}

int main()
{
	int rule;
	while(cin >> n)
	{
		for(int i=0;i<n;i++) cin >> dict[i];
		cin >> rule;
		cout << "--" << endl;
		while(rule--)
		{
			cin >> s;
			len=s.length();
			generatePass(0,"");
		}
	}
	return 0;
}

