#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,tt=0;
	cin >> t;
	while(t--)
	{
		string s,ss;
		cin >> s;
		int len=s.length();
		int l=0,r=len-1;
		ss=s;
		while(l<r)
		{
			ss[r]=s[l];
			l++;r--;
		}
		
		if(s>=ss)
		{
			r=len/2;
			l=len-r-1;
			
			while(l>=0)
			{
				if(s[l]<'9')
				{
					ss[l]=ss[r]=s[l]+1;
					for(int i=l+1;i<r;i++)
					{
						ss[i]='0';
					}
					break;
				}
				l--;r++;
			}
			if(s>=ss)
			{
				ss="";
				for(int i=1;i<len;i++) ss+='0';
				ss='1'+ss+'1';
			}
		}
		
		cout << "Case " << ++tt << ": " << ss << endl;
	}
	return 0;
}
