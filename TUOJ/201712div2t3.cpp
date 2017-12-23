#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

long long f, l, r, kk, p, m;

struct mat  
{  
    long long a[2][2];
    mat() {
        memset(a, 0, sizeof(a));
    }
};

mat mat_mul(mat& x, mat& y)
{  
    mat res = mat();
    for(int i=0;i<2;i++)  
    for(int j=0;j<2;j++)  
    for(int k=0;k<2;k++)  
    {  
        res.a[i][j]+=x.a[i][k]*y.a[k][j];
        res.a[i][j]%=p;
    }  
    return res;  
}

int pow(long long n, long long a, long long b)
{  
    mat c = mat();
    mat res = mat();
    c.a[0][0]=1;
    c.a[0][1]=1;
    c.a[1][0]=1;
    c.a[1][1]=0;  
    res.a[0][0] = b;
    res.a[0][1] = a;
    while (n)
    {  
        if(n&1) res=mat_mul(res, c);
        c=mat_mul(c, c);
        n=n>>1;
    }
    return res.a[0][0];
}

void solve()
{
    cin>>f>>l>>r>>kk>>p>>m;
    /*kk = 1000;
    p = 101;
    m = 1;
    f = 1;
    l = 3;
    r = 10000;*/
    int f1 = -1, f2 = -1;
    if (kk <= 200000 && r <= 200000)
    {
        register int ans = 0;
        for (long long i = l; i <= r; i++)
        {
            if (pow(kk - 2, f, i) % p == m)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    else {
        register int ans = 0;
        for (long long i = l; i <= l + 100000; i++)
        {
            if (pow(kk - 2, f, i) % p == m)
            {
                ans++;
                if (f1 == -1) f1 = i;
                else if (f2 == -1)
                {
                    f2 = i;
                    break;
                }
            }
        }
        if (f1 == -1) { cout<<0<<endl; return; }
        if (f2 == -1) { cout<<1<<endl; return; }
        int dt = f2 - f1;
        ans = (r - f1) / dt + 1;
        cout<<ans<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    for (int i=0; i<t; i++)
    {
        solve();
    }
    //cin.get(), cin.get();
    return 0;
}
