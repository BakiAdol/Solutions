#include<bits/stdc++.h>

typedef long long int lli;

using namespace std;

vector<lli> v(25);

lli factorial(lli n)
{
	if(n==0) return 1;
	auto &ret=v[n];
	if(ret!=0) return ret;
	ret=n;
	return ret*=factorial(n-1);
}

int main()
{
	int t;
	lli n,tmp,total;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> s >> n;
		sort(s.begin(),s.end());
		n++;total=0;
		int len=s.length();
		while(len--)
		{
			for(int i=0;i<=len;i++)
			{
				tmp=factorial(len);
				if(total+tmp>=n)
				{
					if(total+tmp<n)total+=tmp;
					cout << s[i];
					s.erase(s.begin()+i);
					break;
				}else total+=tmp;
			}
		}
		cout << endl;
	}
	
	return 0;
}

