#include <iostream>
#include <cstdio>
using namespace std;

int stk[1000007];
int stkpt;

void solve() {
    int n;
    stkpt = 0;
    scanf("%d", &n);
    register int next = 1;
    register bool flag = true;
    for (register int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        if (!flag) continue;
        if (stkpt > 0 && stk[stkpt - 1] == c) { stkpt--; continue; }
        while (next < c) stk[stkpt++] = next++;
        if (next != c) { flag = false; }
        next++;
    }
    printf((!flag || stkpt != 0) ? "No\n" : "Yes\n");
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}
