#include <iostream>
#include <tuple>
std::tuple<int, int, int> G[5007];
long long D[5007] = {};


int main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z; std::cin >> x >> y >> z;
        G[i] = std::make_tuple(x, y, z);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (D[std::get<0>(G[j])] + std::get<2>(G[j]) < D[std::get<1>(G[j])])
                D[std::get<1>(G[j])] = D[std::get<0>(G[j])] + std::get<2>(G[j]);
    for (int j = 0; j < m; j++)
        if (D[std::get<0>(G[j])] + std::get<2>(G[j]) < D[std::get<1>(G[j])]) {
            std::cout << "Yes"; return 0;
        }
    std::cout << "No"; return 0;
}
