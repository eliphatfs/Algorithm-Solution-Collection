#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
    long double ld;
    cin>>ld;
    ld=(long long)(ld*1e12+0.5)/1e12;
    cout.setf(ios::fixed);
    cout<<setprecision(12)<<ld;
    return 0;
}
#include<iostream>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
    long double ld;
    cin>>ld;
    ld=(long long)(ld*1000+0.5)/1000.0;
    cout.setf(ios::fixed);
    cout<<setprecision(3)<<ld;
    return 0;
}
