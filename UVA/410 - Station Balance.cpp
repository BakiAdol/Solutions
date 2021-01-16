#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c,s;
	int test=0;
	double am,im,tmp;
	while(cin >> c >> s)
	{
		vector<int> v(s);
		am=im=0;
		for(int i=0;i<s;i++)
		{
			cin >> v[i];
			am+=v[i];
		}
		am/=c;
		sort(v.begin(),v.end());
		vector<int> ans[c];
		for(int i=0;i<c and v.size()>0;i++)
		{
			ans[i].push_back(v.back());
			v.pop_back();
		}
		for(int i=c-1;i>=0 and v.size()>0;i--)
		{
			ans[i].push_back(v.back());
			v.pop_back();
		}
		cout << "Set #" << ++test <<endl;
		
		for(int i=0;i<c;i++)
		{
			tmp=0;
			cout <<" "<<i <<":";
			for(int x:ans[i])
			{
				tmp+=x;
				cout << " "<< x;
			}
			cout << endl;
			im+=fabs(am-tmp);
		}
		cout <<fixed<<setprecision(5)<< "IMBALANCE = " << im << endl <<endl;;
	}
	return 0;
}


