#include <bits/stdc++.h>

using namespace std;

#define ulli unsigned long long int

int fibi[1000005];

int fibiCal(int mod)
{
	fibi[0]=0;fibi[1]=1%mod;
	for(int i=2;;i++)
	{
		fibi[i]=(fibi[i-1]+fibi[i-2])%mod;
		if(fibi[i]==fibi[1] and fibi[i-1]==fibi[0])
		{
			return i-1;
		}
	}
}

int bigMod(ulli num, ulli p, ulli mod)
{
	if(p==0) return 1;
	int ans=bigMod(num,p/2,mod);
	ans=(ans*ans)%mod;
	if(p&1) ans=(ans*num)%mod;
	return ans;
}

int main()
{
	int t,n;
	ulli a,b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> n;
		n=fibiCal(n);
		cout << fibi[bigMod(a%n,b,n)] << endl;
	}
	return 0;
}
