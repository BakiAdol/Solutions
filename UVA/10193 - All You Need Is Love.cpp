#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		string s,l;
		cin >> s >> l;
		int si=stoi(s,0,2);
		int li=stoi(l,0,2);
		
		cout << "Pair #" << test <<": ";
		if(__gcd(si,li)>1) cout << "All you need is love!";
		else cout << "Love is not all you need!";
		cout << endl;
	}
    return 0;
}
