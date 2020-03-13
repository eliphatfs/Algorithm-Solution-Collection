#include <iostream>
using namespace std;
#define P 19301

int _f[3337] = {1, 1, 2, 0};
int f(int x) {
    if (_f[x]) return _f[x];
    // Match 'a' -> x - 1
    long long ans = f(x - 1);
    
    // Match '(' -> i ) x - i - 2
    for (int i = 0; i <= x - 2; i++)
        ans += f(i) * f(x - i - 2);
    return _f[x] = ans % P;
}

int main() {
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}
