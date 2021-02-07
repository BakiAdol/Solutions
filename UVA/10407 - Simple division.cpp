#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<int> numbers;

void primeGenerate()
{
	int range=1000000;
	bool check[range];
	
	primes.push_back(2);
	
	for(long long int i=3;i<range;i+=2)
	{
		if(check[i]==0)
		{
			primes.push_back(i);
			for(long long int j=i*i;j<range;j+=i*2) check[j]=1;
		}
	}
}

bool f(int x)
{
	int rem=(numbers[0]%x +x)%x;
	for(auto a:numbers)
	{
		if((a%x +x)%x !=rem) return false;
	}
	return true;
}

int main()
{
    primeGenerate();
	
	int x;
	while(scanf("%d",&x) and x)
    {
		numbers.clear();
		numbers.push_back(x);
		while(scanf("%d",&x) and x)
		{
			numbers.push_back(x);
		}
		
		int ans=1;
		sort(numbers.begin(),numbers.end());
		
		for(auto a:primes)
		{
			if(f(a))
			{
				ans=a;
				break;
			}
		}
		
		int res=ans;
		int tmp=ans;
		while(tmp<=numbers.back())
		{
			if(f(tmp)) res=tmp;
			tmp+=ans;
		}
		
		printf("%d\n",res);
	}
    return 0;
}
