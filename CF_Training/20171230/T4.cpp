#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int n;
long long x[2000];
long long y[2000];

int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        scanf("%I64d%I64d", &x[i], &y[i]);
    long double mind = 1e200;
    x[0] = x[n]; y[0] = y[n];
    x[n+1] = x[1]; y[n+1] = y[1];
    for (int i=1; i<=n; i++)
    {
        long long cx1 = x[i-1];
        long long cy1 = y[i-1];
        long long cx2 = x[i+1];
        long long cy2 = y[i+1];
        long double x0 = x[i];
        long double y0 = y[i];
        long double A = -(cy1 - cy2);
        long double B = cx1 - cx2;
        long double C = (cy1 - cy2) * cx2 - (cx1 - cx2) * cy2;
        
        long double d = abs(A * x0 + B * y0 + C) / sqrt(A * A + B * B);
        mind = min(mind, d);
    }
    printf("%.10lf", (double)(mind/2.0L));
    //cin.get(), cin.get();
    return 0;
}
