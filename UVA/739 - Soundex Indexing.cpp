#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

char nameEncode(char c)
{
	if(c=='R') return '6';
	if(c=='M' or c=='N') return '5';
	if(c=='L') return '4';
	if(c=='D' or c=='T') return '3';
	if(c=='C' or c=='S' or c=='K' or c=='G' or c=='J' or c=='Q' or c=='X' or c=='Z') return '2';
	if(c=='B' or c=='P' or c=='F' or c=='V') return '1';
	return '0';
}

int main()
{
	for(int i=0;i<9;i++) cout << " ";
	cout << "NAME      ";
	for(int i=0;i<15;i++) cout << " ";
	cout << "SOUNDEX CODE" << endl;
	
	string s,tmp;
	while(cin >> s)
	{
		string ans;
		tmp=s[0];
		ans=s[0];
		int pos=0;
		for(int i=1;i<(int)s.length();i++)
		{
			char gc=nameEncode(s[i]);
			if(gc==tmp[pos]) continue;
			if(pos==0 and nameEncode(s[0])==gc) continue;
			++pos;
			tmp+=gc;
			if(gc!='0') ans+=gc;
		}
		ans+="000";
		for(int i=0;i<9;i++) cout << " ";
		s+="                              ";
		for(int i=0;i<25;i++) cout << s[i];
		cout << ans[0] << ans[1] << ans[2] << ans[3] << endl;
	}
	for(int i=0;i<19;i++) cout << " ";
	cout << "END OF OUTPUT" << endl;
	return 0;
}

