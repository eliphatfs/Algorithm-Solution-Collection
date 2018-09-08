#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;
int a[100007];

void solve1() {
    for (int i=0; i<m; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int l, r;
            scanf("%d%d", &l, &r);
            for (int i = l; i <= (l + r) / 2; i++) {
                swap(a[i], a[r + l - i]);    
            }    
        } else if (op == 2) {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            for (int i=l; i<=r; i++) a[i] ^= x;    
        } else if (op == 3) {
            int l, r;
            scanf("%d%d", &l, &r);
            long long ans = 0;
            for (int i = l; i <= r; i++) {
                ans += a[i];
            }
            printf("%lld\n", ans);
        }        
    }
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    solve1();
}
