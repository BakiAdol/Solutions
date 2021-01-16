#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n,ans,tmp,c=0;
	while(cin >> n)
	{
		long long int ar[n];
		for(int i=0;i<n;i++) cin >> ar[i];
		ans=0;
		for(int i=0;i<n;i++)
		{
			tmp=1;
			for(int j=i;j<n;j++)
			{
				tmp*=ar[j];
				ans=max(ans,tmp);
			}
		}
		cout << "Case #" << ++c << ": The maximum product is "<< ans << ".\n\n";
	}
	return 0;
}

