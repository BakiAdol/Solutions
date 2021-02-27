#include<bits/stdc++.h>

using namespace std;

int n=40;
vector<int> fibi(50);

int main()
{
	fibi[0]=fibi[1]=1;
	for(int i=2;i<n;i++)
	{
		fibi[i]=fibi[i-1]+fibi[i-2];
	}
	
	int t;
	cin >> t;
	while(t--)
	{
		int num;
		cin >> num;
		string s="";
		int pos=n-1,tmp=num;
		while(fibi[pos]>num) pos--;
		for(int i=pos;i>0;i--)
		{
			if(num>=fibi[i])
			{
				num-=fibi[i];
				i--;
				if(i>0) s+="10";
				else s+='1';
			}
			else s+='0';
		}
		
		cout << tmp << " = ";
		if(tmp==0) cout << 0;
		else cout << s;
		cout << " (fib)" << endl;
	}
    return 0;
}
