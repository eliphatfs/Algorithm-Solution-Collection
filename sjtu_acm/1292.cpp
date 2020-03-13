#include <iostream>
#include <cstdio>
using namespace std;

template<typename T>
inline void do_swap(T& a, T& b) {
    T c = a; a = b; b = c;
}

inline int mmax(int x, int y) {
    return x > y ? x : y;
}

int seq[1000007];
int inv[1000007];
int n;
int cnt_op = 0;
int vis[1000007];

inline void solve_iter(int i) {
    if (i == seq[i]) return;
    int a = seq[i];
    int b = seq[inv[i]];
    do_swap(seq[i], seq[inv[i]]);
    inv[a] = inv[i];
    inv[i] = i;
    ++cnt_op;
}

int solve_2_iter(int i) {
    if (vis[i]) return 0;
    vis[i] = 1;
    return solve_2_iter(seq[i]) + 1;
}

inline int upward2(int x) {
    int m = 0;
    int base = 1;
    while (base < x) base <<= 1, m++;
    return m;
}

void solve() {
    int maxdis = 0;
    for (int i = 1; i <= n; i++) {
        maxdis = mmax(maxdis, solve_2_iter(i));
    }
    for (int i = 1; i <= n; i++) {
        solve_iter(i);
    }
    cout << cnt_op << endl;
    if (maxdis > 2)
        cout << 2 << endl;
    else if (maxdis <= 1)
        cout << 0 << endl;
    else
        cout << 1 << endl;
}

int main() {
    while (scanf("%d", &n) >= 1) {
        cnt_op = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &seq[i]);
            inv[seq[i]] = i;
            vis[i] = 0;
        }
        solve();
    }
    return 0;
}
