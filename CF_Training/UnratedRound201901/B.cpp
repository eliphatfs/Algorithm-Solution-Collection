#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
int n, m;
ll a[100007];
ll c[100007];
ll tot;
map<ll, set<int> > ci;  // cost -> dishes
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) scanf("%I64d", &a[i]), tot += a[i];
    for (int i=1; i<=n; i++)
    {
        scanf("%I64d", &c[i]);
        ci[c[i]].insert(i);
    }
    for (int i=0; i<m; i++)
    {
        int t, d;
        ll ans = 0;
        scanf("%d%d", &t, &d);
        if (a[t] >= d)
        {
            a[t] -= d;
            tot -= d;
            ans += d * c[t];
            if (a[t] == 0)
            {
                ci[c[t]].erase(t);
            }
        }
        else
        {
            ans += a[t] * c[t];
            tot -= a[t];
            d -= a[t];
            a[t] = 0;
            ci[c[t]].erase(t);
            while (d > 0)
            {
                while ((ci.begin()->second).size() == 0 && ci.size() != 0)
                    ci.erase(ci.begin());
                if (tot == 0)
                {
                    ans = 0;
                    break;
                }
                int kind = *(ci.begin()->second).begin();
                if (a[kind] >= d)
                {
                    a[kind] -= d;
                    tot -= d;
                    ans += d * c[kind];
                    d = 0;
                    if (a[kind] == 0)
                    {
                        ci[c[kind]].erase(kind);
                    }
                } else {
                    tot -= a[kind];
                    ans += a[kind] * c[kind];
                    d -= a[kind];
                    a[kind] = 0;
                    ci[c[kind]].erase(kind);
                }
            }
        }
        printf("%I64d\n", ans);
    }
    // cin.get(), cin.get();
    return 0;
}
