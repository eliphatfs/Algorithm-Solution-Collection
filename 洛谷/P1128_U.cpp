#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
int modxs[51000] = {0};
int pcur = 2;
struct bnum
{
    long long d[3000];
    bnum()
    {
        memset(d, 0, sizeof(d));
    }
    bnum operator=(long long num)
    {
        memset(d, 0, sizeof(d));
        int i=0;
        while (num > 0)
        {
            d[i++] = num % 10;
            num /= 10;
        }
    }
    bnum operator*(long long num)
    {
        bnum oth = bnum();
        long long o = 0;
        for (int i=0; i<2999; i++)
        {
            oth.d[i] = d[i] * num + o;
            o = oth.d[i] / 10;
            oth.d[i] %= 10;
        }
        return oth;
    }
    string toString()
    {
        bool flag = false;
        char buf[3000];
        int pt = 0;
        for (int i=2999; i>=0; i--)
        {
            if (d[i] > 0) flag = true;
            if (flag) buf[pt++] = d[i] + '0'; 
        }
        buf[pt++] = '\0';
        if (!flag) return "0";
        else return string(buf);
    }
};
inline void nextp()
{
    for (register int i=pcur+1; ; i++)
    {
        register int sqrti = (int)sqrt(i);
        for (register int j=2; j<=sqrti; j++) if (i % j == 0) goto skipn;
        pcur = i;
        return;
        skipn:
            ;
    }
}
int main()
{
    int n;
    cin>>n;
    if (n == 1)
    {
        cout<<1;
        return 0;
    }
    bnum m;
    m = 1;
    int sqrtn = (int)sqrt(n);
    for (int i=2; i<=n; i++)
    {
        int sqrti = (int)sqrt(i);
        for (int j=2; j<=sqrti; j++) if(i % j == 0) goto skip;
        while (n % i == 0)
        {
            n /= i;
            modxs[i]++;
        }
        skip:
            ;
    }
    for (int i=50999; i>=2; i--)
    {
        while (modxs[i] > 0)
        {
            modxs[i]--;
            for (int j=0; j<i-1; j++)
                m = m * pcur;
            nextp();
        }
    }
    cout<<m.toString();
    //cin.get(), cin.get();
    return 0;
}
