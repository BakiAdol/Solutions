#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main()
{
	int n;
	while(cin >>n and n!=-1)
	{
		lli m=0,f=1,a=0,b=1;
		for(int i=0;i<n;i++)
		{
			f=m+1;
			m+=b;
			swap(a,b);
			b+=a;
		}
		cout <<m << " " << m+f << endl;
	}
    return 0;
}
