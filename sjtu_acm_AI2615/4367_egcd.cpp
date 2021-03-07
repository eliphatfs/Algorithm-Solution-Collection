#include <iostream>
#include <cmath>

struct EGCDResult {
    long long x, y, g;
    EGCDResult(long long _x, long long _y, long long _g) { x = _x; y = _y; g = _g; }
};

EGCDResult egcd(long long a, long long b) {
    if (b == 0) return EGCDResult(1, 0, a);
    EGCDResult rec = egcd(b, a % b);
    return EGCDResult(rec.y, rec.x - a / b * rec.y, rec.g);
}

int main() {
    long long a, b, c;
    while (true) {
        std::cin >> a >> b >> c;
        if (c == 0) break;
        EGCDResult r = egcd(a, b);
        if (c % r.g != 0) { std::cout << "No Answer\n"; continue; }
        r.x *= c / r.g; r.y *= c / r.g;
        while (r.x < 0) { r.x += b / r.g; r.y -= a / r.g; }
        while (r.x >= b / r.g) { r.x -= b / r.g; r.y += a / r.g; }
        std::cout << r.x << ' ' << r.y << '\n';
    }
    return 0;
}
