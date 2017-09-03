#include <iostream>
#include <cstdio>
using namespace std;
typedef int ll;
void one(ll a, ll b, ll c, ll d, ll k);
ll gcd(ll x, ll y, ll lastmod);
int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        ll a,b,c,d,k;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        one(a, b, c, d, k);
    }
    //getchar();getchar();
    return 0;
}

void one(ll a, ll b, ll c, ll d, ll k)
{
    ll count = 0;
    ll fx = 0;
    ll fy = 0;
    for (ll x=a; x<=b; x++)
        if (x % k == 0)
        {
            fx = x;
            break;
        }
    for (ll y=c; y<=d; y++)
        if (y % k == 0)
        {
            fy = y;
            break;
        }
    if (fx == 0 || fy == 0) printf("%d\n", 0);
    else
    {
        for (ll x = fx; x <= b; x += k)
            for (ll y = fy; y <= d; y += k)
                if (gcd(x, y, 1) == k) count++;
        printf("%d\n", count);
    }
}

ll gcd(ll x, ll y, ll lastmod)
{
    if (x == 0) return lastmod;
    if (y == 0) return lastmod;
    if (x > y)
    {
        x = x % y;
        lastmod = y;
    }
    else
    {
        y = y % x;
        lastmod = x;
    }
    return gcd(x, y, lastmod);
}
