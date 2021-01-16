#include<bits/stdc++.h>

using namespace std;

int main()
{
	int h,m,s,c;
	long long int total;
	while(cin >> h)
	{
		c=h%100;h/=100;
		s=h%100;h/=100;
		m=h%100;h/=100;
		
		total = c + s*100 + m*60*100 + h*60*60*100;
		total *=10000000;
		total/= 24*60*60*100;
		
		c=total%100;total/=100;
		s=total%100;total/=100;
		m=total%100;total/=100;
		
		cout << total;
		if(m<10) cout << 0;
		cout << m;
		if(s<10) cout << 0;
		cout << s;
		if(c<10) cout << 0;
		cout << c << endl;
	}
	return 0;
}

