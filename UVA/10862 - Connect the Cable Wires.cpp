#include<bits/stdc++.h>

using namespace std;

int mx=4500;
vector<string> v;

int main()
{
	v.push_back("0");
	v.push_back("1");
	v.push_back("1");
	
	for(int i=3;i<mx;i++)
	{
		string s="";
		int lena=v[i-1].length();
		int lenb=v[i-2].length();
		int c=0;
		for(int j=0,k=0;j<lena or k<lenb;j++,k++)
		{
			if(j<lena) c+=v[i-1][j]-'0';
			if(k<lenb) c+=v[i-2][k]-'0';
			s+=c%10 + '0';
			c/=10;
		}
		if(c) s+=c+'0';
		v.push_back(s);
		reverse(v[i-2].begin(),v[i-2].end());
 	}
 	
 	int n;
 	while(cin >>n and n)
 	{
		cout << v[n*2] << endl;
	}
    return 0;
}
