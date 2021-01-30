#include<bits/stdc++.h>

using namespace std;

double areaOfTriangle(double a, double b, double c)
{
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        double a,b,c,r;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&r);
        
        double total_area=areaOfTriangle(a,b,c);
        
        double lft=0,rgt=100,m;
        
        int x=60;
        
        while(--x)
        {
            m=(lft+rgt)/2;
            double tmp_area=areaOfTriangle(a*m/100,b*m/100,c*m/100);
            double tmp_ratio=(tmp_area/(total_area-tmp_area));
            
            if(tmp_ratio>r) rgt=m;
            else if(tmp_ratio<r) lft=m;
            else break;
        }
        
        printf("Case %d: %.6lf\n",test,a*m/100);
    }
    return 0;
}
