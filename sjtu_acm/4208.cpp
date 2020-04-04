#include <iostream>
#include <cmath>
using namespace std;

inline long long ceil_div(long long x, long long y) { return ((x + y - 1) / y); }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b, x1, y1, x2, y2;
        cin >> a >> b >> x1 >> y1 >> x2 >> y2;
        
        long long u1 = x1 + y1; long long u2 = x2 + y2;
        long long v1 = x1 - y1; long long v2 = x2 - y2;
        
        long long umin = min(u1, u2), umax = max(u1, u2);
        long long vmin = min(v1, v2), vmax = max(v1, v2);
        
        umax -= umin / (2 * a) * (2 * a);
        umin -= umin / (2 * a) * (2 * a);
        vmax -= vmin / (2 * b) * (2 * b);
        vmin -= vmin / (2 * b) * (2 * b);
        
        while (umin < 0) { umin += 2 * a; umax += 2 * a; }
        while (vmin < 0) { vmax += 2 * b; vmin += 2 * b; }
        // Translate so that x > 0, y > 0
        // Because -10 / 3 * 3 > -10, 10 / 3 * 3 < 10
        
        long long mu = umax / (2 * a) - ceil_div(umin, 2 * a) + 1;
        long long mv = vmax / (2 * b) - ceil_div(vmin, 2 * b) + 1;
        
        cout << max(mu, mv) << endl;
    }
}
