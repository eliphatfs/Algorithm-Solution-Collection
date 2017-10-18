#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
ll xx2[100]; // xx2[i] = x^(2^i) % 1000
ll xxmod(ll x)
{
    memset(xx2, 0, sizeof(xx2));
    ll result = 1;
    ll tmpx = x;
    xx2[0] = x;
    int maxi = 0;
    for (int i=1; i<100; i++)
    {
        xx2[i] = xx2[i-1] * xx2[i-1];
        xx2[i] %= 1000;
    }
    while (tmpx != 0)
    {
        tmpx >>= 1;
        ++maxi;
    }
    tmpx = x;
    int i2 = maxi;
    while (tmpx != 0)
    {
        if (tmpx & 1)
            result *= xx2[maxi - i2], result %= 1000;
        tmpx >>= 1;
        --i2;
    }
    return result % 1000;
}

struct bnum
{
    ll d[3072];
    int len;
    bnum()
    {
        memset(d, 0, sizeof(d));
        len = 0;
    }
    bnum operator=(ll num)
    {
        while(num > 0)
        {
            d[len++] = num % 10;
            num /= 10;
        }
        return *this;
    }
    void mul(ll num)
    {
        int o=0;
        for (int i=0; i<3000; i++)
        {
            d[i] = d[i] * num + o;
            o = d[i] / 10;
            d[i] %= 10;
        }
    }
    void div(ll num)
    {
        for (int i=3000; i>0; i--)
        {
            d[i-1] += 10 * (d[i] % num);
            d[i] /= num;
        }
        d[0] /= num;
    }
    char * toString()
    {
        int l = 3000;
        while (d[l-1] == 0)
            l--;
        char * str = new char[l+1];
        for (int i=0; i<l; i++)
        {
            str[i] = d[l-1-i] + '0';
        }
        str[l]='\0';
        return str;
    }
};

int main()
{
    ll k, x;
    cin>>k>>x;
    ll xxm = xxmod(x);
    //g(x)
    //C(k-1, g(x)-1)
    bnum ans;
    ans = 1;
    for (ll x = xxm - 1, i = 0; i < k - 1; x--, i++)
        ans.mul(x);
    for (int i=1; i<=k-1; i++)
        ans.div(i);
    char * out = ans.toString();
    while(out[0] == '0') ++out;
    if (ans.len == 0) cout<<0;
    else cout<<out;
    //cin.get(),cin.get();
    return 0;
}
