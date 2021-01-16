#include <bits/stdc++.h>

using namespace std;

bool f(string s, string t)
{
	int lens = s.length();
	int lent = t.length();
	int subpos=0;
	
	for(int i=0;i<lent;i++)
	{
		if(t[i]==s[subpos]) subpos++;
	}
	
	return subpos==lens;
}

int main()
{
	string s,t;
	
	while(cin >>s >> t)
	{
		cout << (f(s,t) ? "Yes" : "No") << endl;
	}
	
	return 0;
}


