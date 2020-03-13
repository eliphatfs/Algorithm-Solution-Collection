#include <iostream>
using namespace std;

long long mmin(long long x, long long y) {
    return x > y ? y : x;
}

long long mmax(long long x, long long y) {
    return x < y ? y : x;
}

long long iter(long long x, long long y) {
    if (x == 0 || y == 0) return 0;
    return y / x * (4 * x) + iter(y % x, x);
}

int main() {
    long long x, y;
    cin >> x >> y;
    cout << iter(mmin(x, y), mmax(x, y));
    return 0;
}
