#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

inline long long superxor(long long input) {
    static int digits[15];
    memset(digits, 0, sizeof(digits));
    for (long long i = input / 20 * 20; i <= input; i++) {
        long long n = i;
        for (register int d = 0; d < 15; d++) {
            digits[d] += n % 10;
            n /= 10;
        }
    }
    long long base = 1;
    long long ans = 0;
    for (int d = 0; d < 15; d++) {
        ans += base * (digits[d] % 10);
        base *= 10;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    long long n;
    for (int i = 0; i < t; i++) {
        scanf("%lld", &n);
        printf("%lld\n", superxor(n));
    }
    // cin.get(), cin.get();
    return 0;
}
