#include<bits/stdc++.h>

using namespace std;

void minimize(string &s,int pos)
{
	int len=s.length();
	int one=0;
	for(int i=pos;i<len;i++)
	{
		if(s[i]=='1') one++;
	}
	for(int i=len-1;i>=pos;i--)
	{
		if(one-->0) s[i]='1';
		else s[i]='0';
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++)
	{
		int n;
		scanf("%d",&n);
		string s="";
		while(n)
		{
			if(n&1) s='1'+s;
			else s="0"+s;
			n>>=1;
		}
		int len=s.length();
		int pos=2;
		
		if(s.find("01") == string::npos)
		{
			s.insert(s.begin()+1,'0');
		}
		else
		{
			for(int i=len-1;i>0;i--)
			{
				if(s[i]=='1' and s[i-1]=='0')
				{
					swap(s[i],s[i-1]);
					pos=i+1;
					break;
				}
			}
		}
		
		minimize(s,pos);
		
		n=0;
		int tmp=1;
		len=s.length();
		for(int i=len-1;i>=0;i--)
		{
			if(s[i]=='1') n+=tmp;
			tmp*=2;
		}
		
		printf("Case %d: %d\n",test,n);
	}
    return 0;
}
