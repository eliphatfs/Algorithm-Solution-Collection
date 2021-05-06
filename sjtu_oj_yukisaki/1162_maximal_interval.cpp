#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n;
int presum[200007];
int main() {
    cin >> n;
    int cursum = 0;
    for (int i = 0; i < n; i++) {
        int c; scanf("%d", &c);
        cursum += c;
        presum[i] = cursum;
    }
    int premin = 0;
    int ans = -(1 << 30);
    for (int i = 0; i < n; i++) {
        ans = max(ans, presum[i] - premin);
        premin = min(premin, presum[i]);
    }
    cout << ans;
    return 0;
}