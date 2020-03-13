#include <iostream>
#include <cstdio>
using namespace std;

inline int updated(int ans, int newans) {
    if (newans <= 24 && newans > ans) return newans;
    return ans;
}

int solve(int * a, int n) {
    if (n == 1) return a[0];
    int deduct[4];
    int dpt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            dpt = 0;
            for (int k = 0; k < n; k++)
                if (k != i && k != j) deduct[dpt++] = a[k];
            deduct[dpt] = a[i] + a[j];
            ans = updated(ans, solve(deduct, n - 1)); 
            deduct[dpt] = a[i] * a[j];
            ans = updated(ans, solve(deduct, n - 1)); 
            deduct[dpt] = a[i] - a[j];
            ans = updated(ans, solve(deduct, n - 1)); 
            if (a[j] != 0 && a[i] % a[j] == 0) {
                deduct[dpt] = a[i] / a[j];
                ans = updated(ans, solve(deduct, n - 1)); 
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int num[4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++)
            scanf("%d", &num[j]);
        cout << solve(num, 4) << '\n';
    }
    return 0;
}
