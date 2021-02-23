#include<bits/stdc++.h>

using namespace std;

int main()
{
	v[0]=1;
	for(int i=1;i<10001;i++)
	{
		v[i]=(v[i-1]*2)%mod;
	}
	string s="",tmp;
	while(cin >> tmp)
	{
		s+=tmp;
		int len=tmp.length();
		if(tmp[len-1]=='#')
		{
			reverse(s.begin(),s.end());
			len=s.length();
			int total=0;
			for(int i=1;i<len;i++)
			{
				if(s[i]=='1')
				{
					total=(total+v[i-1])%mod;
				}
			}
			if(total==0) cout << "YES" << endl;
			else cout << "NO" << endl;
			s="";
		}
	}
    return 0;
}
