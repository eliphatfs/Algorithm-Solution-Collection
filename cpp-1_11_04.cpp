#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main()
{
    int n,f;
    //freopen("1748.open","r",stdin);
    cin>>n>>f;
    int a[10002]={0};
    float r[10002]={0};
    float m=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%f",&r[i]);
        a[i]=100*r[i];
        if(a[i]>a[0])
            a[0]=a[i];
    }
    for(float b=1e7;b>=0.5;b/=2)
    {
    for(float i=m+b;i<=a[0];i+=b)
    {
    	long long has=0;
        for(int k=1;k<=n;k++)
        {
			has+=(int)(a[k]/i);
        }
    if(has<f){m=i-b;break;}
    }
    }
    printf("%.2f",m/(float)100);
    return 0;
}
