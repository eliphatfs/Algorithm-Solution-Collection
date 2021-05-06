#include <iostream>
#include <queue>
#include <array>
using namespace std;

int m, n, k;
int wasted[207];
array<array<long long, 1 << 6>, 1 << 6> state[2];

inline constexpr bool check_valid(int last2_6, int last1_6, int next_6) {
    int lasts[3] = {0, last1_6, last2_6};
    for (int i = 0; i < 6; i++) if (next_6 & (1 << i))
        for (int drow : {1, 2})
            for (int dcol : {2 / drow, -2 / drow}) {
                int col = i + dcol;
                if (col >= 0 && col < 6 && (lasts[drow] & (1 << col)))
                    return false;
            }
    return true;
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int wx, wy;
        cin >> wx >> wy;
        wasted[wx - 1] |= (1 << (wy - 1));
    }
    state[0][0][0] = state[1][0][0] = 1;
    for (int i = 0; i < m; i++) {
        auto& fill_swap = state[i % 2];
        auto& load_swap = state[(i + 1) % 2];
        for (int sc = 0; sc < (1 << n); sc++) {
            fill_swap[sc].fill(0);
            if (wasted[i] & sc) { continue; }
            for (int s1 = 0; s1 < (1 << n); s1++)
                for (int s2 = 0; s2 < (1 << n); s2++)
                    if (check_valid(s2, s1, sc)) {
                        fill_swap[sc][s1] += load_swap[s1][s2];
                        fill_swap[sc][s1] %= 1000000007;
                    }
        }
    }
    long long ans = 0;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < (1 << n); j++)
            ans = (ans + state[(m - 1) % 2][i][j]) % 1000000007;
    cout << ans;
    return 0;
}
