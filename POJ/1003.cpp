#include<iostream>

using namespace std;

int main()
{
    double c;
    while(scanf("%lf",&c) and c)
    {
		double tmp=0;
		int ans=1;
		while(tmp<c) tmp+=1.0/++ans;
		printf("%d card(s)\n",--ans);
	}
    return 0;
}
