#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    const double pi=3.1415926535898;
    int n,f;
    cin>>n>>f;
    f=f+1;
    int r[10001]={0};
    double a[10001]={0};
    double m=0;
    for(int i=1;i<=n;i++)
    {
        cin>>r[i];
        a[i]=r[i]*r[i]*pi;
        if(a[i]>a[0])
            a[0]=a[i];
    }
    //0.0001
    for(double b=1000000000;b>=0.00009;b/=10)
    {
    for(double i=m+b;i<=a[0];i+=b)
    {
            int has=0;
            for(int k=1;k<=n;k++)
            {
                    if(a[k]>=i)
                    {

                                  has+=(int)(a[k]/i);
                    }
            }

    if(has<f){m=i-b;break;}
    }
    }
    m=(long long)(m*1000+0.5)/1000.0;
    cout.setf(ios::fixed);
    cout<<setprecision(3)<<m;
    return 0;
}
