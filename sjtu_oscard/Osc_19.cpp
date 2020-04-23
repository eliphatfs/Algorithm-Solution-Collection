#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int n, m;
char arr[100007];
int one_c[200007];
int zero_c[200007];

inline int lowbit(int x) { return x & -x; }

inline int sum_to(int * w, int i) {
    int s = 0;
    while (i) { s += w[i]; i -= lowbit(i); }
    return s;
}

inline void change(int * w, int x, int ax) {
    int i = x;
    while (i <= 2 * n + 1) { w[i] += ax; i += lowbit(i); }
}

inline long long cnt(int L, int R) {
    int c_one = 0;
    long long ans = 0;
    for (int i = L; i < R; i++) {
        if (arr[i] == '1') ++c_one;
        if (arr[i] == '0') ans += c_one;
    }
    return ans;
}

inline void do_swap(int x, int y) {
    char p = arr[x];
    arr[x] = arr[y];
    arr[y] = p;
}

int main() {
    cin >> n >> m;
    scanf("%s", arr);
    long long cans = cnt(0, n);
    for (int i = 1; i <= n; i++) {
        change(one_c, i, arr[i - 1] == '1' ? 1 : 0);
        change(zero_c, i, arr[i - 1] == '0' ? 1 : 0);
    }
    for (int i = 0; i < m; i++) {
        int ix, iy;
        scanf("%d%d", &ix, &iy);
        int x = min(ix, iy) + 1, y = max(ix, iy) + 1;
        if (arr[ix] != arr[iy]) {
            if (arr[x - 1] == '1') {  // Right: 1 appear, Left: 1 disappear
                cans -= sum_to(zero_c, y - 1) - sum_to(zero_c, x);
            }
            if (arr[x - 1] == '0') {  // Right: 0 appear, Left: 0 disappear
                cans += sum_to(one_c, y - 1) - sum_to(one_c, x);
            }
            if (arr[y - 1] == '1') {  // 1 move from right to left
                cans += sum_to(zero_c, y - 1) - sum_to(zero_c, x);
            }
            if (arr[y - 1] == '0') {  // 0 move from right to left
                cans -= sum_to(one_c, y - 1) - sum_to(one_c, x);
            }
            if (arr[x - 1] == '1' && arr[y - 1] == '0') cans--;
            if (arr[x - 1] == '0' && arr[y - 1] == '1') cans++;
            
            if (arr[x - 1] == '0') { change(zero_c, x, -1); change(zero_c, y, 1); }
            if (arr[y - 1] == '0') { change(zero_c, y, -1); change(zero_c, x, 1); }
            
            if (arr[x - 1] == '1') { change(one_c, x, -1); change(one_c, y, 1); }
            if (arr[y - 1] == '1') { change(one_c, y, -1); change(one_c, x, 1); }
        }
        printf("%lld\n", cans);
        do_swap(ix, iy);
    }
    return 0;
}
