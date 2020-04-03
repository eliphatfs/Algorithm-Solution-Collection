#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, m;
char d[2001][2001];
int pref_1[2001][2001];

inline int ceil_div(int x, int y) { return (x + y - 1) / y; }

int answer_with(int k) {
    int fn = ceil_div(n, k);
    int fm = ceil_div(m, k);
    int ans = 0;
    for (int i = 0; i < fn; i++)
    for (int j = 0; j < fm; j++) {
        register int fx = (i + 1) * k;
        register int fy = (j + 1) * k;
        register int block_n0 = 0;
        for (register int x = i * k; x < fx; x++) {
            block_n0 += pref_1[fy][x] - pref_1[j * k][x];
        }
        ans += min(block_n0, k * k - block_n0);
    }
    return ans;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++)
    for (register int j = 0; j < m; j++)
        d[i][j] -= '0';
    for (int i = 0; i < n * 2; i++) {
        for (register int j = 0; j < m * 2; j++) {
            pref_1[j + 1][i] = pref_1[j][i] + d[i][j];
        }
    }
    int a = 987654321;
    for (int k = 2; k <= min(n, m); k++) {
        a = min(a, answer_with(k));
    }
    cout << a;
    return 0;
}
