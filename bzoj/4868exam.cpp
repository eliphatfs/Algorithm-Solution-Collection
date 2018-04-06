#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m;  // STU TES
ll a, b, c;  // op1 op2 wait
int ti[100007];  // STU T 1..n
int bi[100007];  // TES T 1..m
int tbi[100007];
ll cost[100007];

ull sumpti[100007];

int maxt = 0;

void cal_sum_pti() {
    sumpti[1] = 0;
    for (int i = 2; i <= n; ++i) {
        sumpti[i] = sumpti[i - 1] + ti[i] - ti[1];
    }
}

inline int indexof_ti(int d, int l, int r) {
    if (d > ti[r]) return r;
    if (d <= ti[l]) return -1;
    if (l >= r || l <= 0 || r > n) return -1;
    int mm = (l + r) >> 1;
    if (ti[mm + 1] >= d && ti[mm] < d)
        return mm;
    if (ti[mm + 1] < d)
        return indexof_ti(d, mm + 1, r);
    if (ti[mm] >= d)
        return indexof_ti(d, l, mm);
}

inline int indexof_ti2(int d, int l, int r) {
    if (d >= ti[r]) return r;
    if (d < ti[l]) return -1;
    if (l >= r || l <= 0 || r > n) return -1;
    int mm = (l + r) >> 1;
    if (ti[mm + 1] > d && ti[mm] <= d)
        return mm;
    if (ti[mm + 1] <= d)
        return indexof_ti(d, mm + 1, r);
    if (ti[mm] > d)
        return indexof_ti(d, l, mm);
}

inline int indexof_bi(int d, int l, int r) {
    if (d > bi[r]) return r;
    if (l >= r || l <= 0 || r > m) return -1;
    int mm = (l + r) >> 1;
    if (bi[mm + 1] >= d && bi[mm] < d)
        return mm;
    if (bi[mm + 1] < d)
        return indexof_bi(d, mm + 1, r);
    if (bi[mm] >= d)
        return indexof_bi(d, l, mm);
}

ll first_data() {
    sort(ti + 1, ti + n + 1);
    sort(bi + 1, bi + m + 1);
    cal_sum_pti();
    ll ans = 0;
    for (int i = 1; i <= m; ++i) {
        int pti = indexof_ti(bi[i], 1, n);
        if (pti == -1) continue;
        ans += pti * (long long)(bi[i] - ti[1]) - sumpti[pti];
        maxt = max(maxt, bi[i]);
    }
    ans = ans * c;
    return ans;
}

ull f(ll d) {
    memcpy(tbi, bi, sizeof(bi));
    memset(cost, 0, sizeof(cost));
    ull ans = 0;
    int totc = 0;
    for (int i = 1; i <= m; i++) {
        if (tbi[i] < d)
            totc += d - tbi[i];
    }
    for (int i = 1; i <= m; ++i) {
        if (tbi[i] > d) {
            if (a < b && tbi[i] - d <= totc) {
                ans += a * (long long)(tbi[i] - d);
                totc -= (tbi[i] - d);
            } else if (a < b) {
                ans += a * (long long)totc;
                tbi[i] -= totc;
                totc = 0;
                ans += b * (long long)(tbi[i] - d);
            } else {
                ans += b * (long long)(tbi[i] - d);
            }
            tbi[i] = d;
        }
    }
    int maxtt = 0;
    for (int i = 1; i <= m; ++i) {
        maxtt = max(maxtt, tbi[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (maxtt > ti[i]) {
            if (c > 10000000) ans = (1ll<<61);
            else
                ans += (maxtt - ti[i]) * c;
        }
    }
    return ans;
}

ll tri_search(ll l, ll r) {
    if (r - l <= 2) {
        ull f1 = f(l);
        ull f2 = f(l + 1);
        ull f3 = f(l + 2);
        return min(min(f1, f2), f3);
    }
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    ull fm1 = f(m1);
    ull fm2 = f(m2);
    if (fm1 > fm2)
        return tri_search(m1, r);
    else
        return tri_search(l, m2);
    /*else if (fm1 == fm2)
        return fm1;*/
}

int main() {
    cin>>a>>b>>c;
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        scanf("%d", &ti[i]);
    for (int i=1; i<=m; i++)
        scanf("%d", &bi[i]);

    first_data();
    cout<<tri_search(0, maxt + 1);
    //cin.get(),cin.get();
}
