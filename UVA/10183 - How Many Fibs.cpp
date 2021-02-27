#include<bits/stdc++.h>

using namespace std;

vector<string> v;

bool large(string a, string b)
{
	int lena=a.length();
	int lenb=b.length();
	if(lenb>lena) return true;
	if(lenb<lena) return false;
	for(int i=0;i<lena;i++)
	{
		if(b[i]<a[i]) return false; 
		if(b[i]>a[i]) return true;
	}
	return false;
}

int main() 
{
	v.push_back("1");
	v.push_back("1");
	
	for(int i=2;i<500;i++)
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
 	
 	string a,b;
 	while(cin >> a >> b and !(a==b and a=="0"))
 	{
		int ans=0;
		for(int i=1;i<499;i++)
		{
			if(large(b,v[i])) break;
			if(a==v[i] or large(a,v[i])) ans++;
		}
		cout << ans << endl;
	}
    return 0;
}
