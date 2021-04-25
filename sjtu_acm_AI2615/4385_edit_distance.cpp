#include <iostream>
#include <cstring>
#include <cmath>

int x, y;
char a[3001], b[3001];
int memo[3001][3001];

int edit_dist(int na, int nb) {
    if (na == 0) return nb * x;
    if (nb == 0) return na * x;
    if (memo[na][nb] >= 0) return memo[na][nb];
    int ans = x + std::min(edit_dist(na - 1, nb), edit_dist(na, nb - 1));
    ans = std::min(ans, edit_dist(na - 1, nb - 1) + (a[na - 1] == b[nb - 1] ? 0 : y));
    return memo[na][nb] = ans;
}

int main() {
    for (int i = 0; i < 3001; i++)
        for (int j = 0; j < 3001; j++)
            memo[i][j] = -1;
    std::cin >> x >> y >> a >> b;
    std::cout << edit_dist(std::strlen(a), std::strlen(b));
    return 0;
}
