#include <iostream>
using namespace std;

const long long p = 1000000007;

long long _f[1003] = {1};
long long f(int x) {
    if (_f[x] > 0) return _f[x];
    long long ans = 0;
    for (int i = x % 2; i <= x; i += 2)
        ans += f((x - i) / 2);
    
    return _f[x] = ans % p;
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}
