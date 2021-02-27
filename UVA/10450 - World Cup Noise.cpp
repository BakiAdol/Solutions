#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

vector<lli> v;

int main()
{
	v.push_back(1);
	v.push_back(2);
	for(int i=2;i<52;i++)
	{
		v.push_back(v[i-1]+v[i-2]);
	}
	int t;
	cin >> t;
	for(int test=1;test<=t;test++)
	{
		int n;
		cin >>n;
		cout << "Scenario #"<<test<<":" << endl;
		cout << v[n] << endl << endl;
	}
    return 0;
}
