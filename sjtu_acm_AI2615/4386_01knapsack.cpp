#include <iostream>
#include <cmath>

int n, m;
int w, v;

int f[100007];
// f(n, w) = max(f(n - 1, w), f(n - 1, w - wn) + vn);

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> w >> v;
        for (int x = m; x >= w; x--)
            f[x] = std::max(f[x], f[x - w] + v);
    }
    std::cout << f[m];
    return 0;
}
