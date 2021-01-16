#include <bits/stdc++.h>
 
using namespace std;

int ar[10],br[10];
bool used[10];

bool cal(int val,int pos)
{
	if(pos==5)
	{
		if(val==23) return true;
		return false;
	}
	
	if(cal(val+ar[pos],pos+1)) return true;
	if(cal(val-ar[pos],pos+1)) return true;
	if(cal(val*ar[pos],pos+1)) return true;

	return false;
}

bool per(int pos)
{
	if(pos==5) if(cal(ar[0],1)) return true;

	for(int i=0;i<5;i++)
	{
		if(!used[i])
		{
			ar[pos]=br[i];
			used[i]=1;
			if(per(pos+1)) return true;
			used[i]=0;
		}
	}
	return false;
}

int main()
{
	while(cin >> ar[0]>> ar[1]>> ar[2]>> ar[3]>> ar[4])
	{
		if(ar[0]==0 and ar[1]==0 and ar[2]==0 and ar[3]==0 and ar[4]==0) break;
		for(int i=0;i<5;i++) br[i]=ar[i];
		for(int i=0;i<7;i++) used[i]=0;
		cout << (per(0) ? "Possible" : "Impossible") << endl;
	}
	
    return 0;
}

