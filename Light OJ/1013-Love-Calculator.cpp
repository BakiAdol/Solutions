#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

string a,b;
int lena,lenb;

int memo[35][35];
lli ways[35][35][70];

int lcs(int posa, int posb)
{
	if(posa==lena or posb==lenb) return 0;
	
	int &ret=memo[posa][posb];
	if(ret!=-1) return ret;
	
	if(a[posa]==b[posb]) ret=1+lcs(posa+1,posb+1);
	else ret=max(lcs(posa,posb+1),lcs(posa+1,posb));
	
	return ret;
}

lli uniqueString(int len, int posa, int posb)
{
	if(len<0) return 0;
	if(len==0 and lena==posa and lenb==posb) return 1;
	if(len>0 and lena==posa and lenb==posb) return 0;
	if(lena==posa and lenb!=posb) return uniqueString(len-1,posa,posb+1);
	if(lena!=posa and lenb==posb) return uniqueString(len-1,posa+1,posb);
	
	
	lli &ret=ways[posa][posb][len];
	if(ret!=-1) return ret;
	
	if(a[posa]==b[posb]) ret=uniqueString(len-1,posa+1,posb+1);
	else ret=uniqueString(len-1,posa+1,posb)+uniqueString(len-1,posa,posb+1);

	return ret;
}

int main()
{
	int t;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		cin >> a >> b;
		lena=a.length();
		lenb=b.length();
		memset(memo,-1,sizeof(memo));
		int len=lena+lenb-lcs(0,0);
		memset(ways,-1,sizeof(ways));
		cout << "Case " << test << ": " << len << " " << uniqueString(len,0,0) << endl;
	}

	return 0;
}
