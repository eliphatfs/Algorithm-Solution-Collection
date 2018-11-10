#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int n;
int a[100007];

ll fill_pa(int l, int r, int filled) {
    if (l > r) return 0;
    int mind = 987654321;
    for (int i=l; i<=r; i++) {
        if (mind > a[i]) mind = a[i];
    }
    ll contrib = mind - filled;
    int last = l;
    for (int i=l; i<=r; i++) {
        if (a[i] == mind) {
            contrib += fill_pa(last, i - 1, mind);
            last = i + 1;
        }
    }
    contrib += fill_pa(last, r, mind);
    return contrib;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    cout << fill_pa(0, n - 1, 0);
    getchar(), getchar();
    return 0;
}
