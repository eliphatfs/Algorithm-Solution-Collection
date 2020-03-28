#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define D 1
#define J -1
int max_step(int * lin, int n, int k, int depth);
int min_step(int * lin, int n, int k, int depth);

int valid(int * lin, int n, int i, int j) {
    for (int a = 0; a < j; a++) if (!lin[(i + a) % n]) return 0;
    return 1;
}

int max_step(int * lin, int n, int k, int depth) {
    int value = J;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++) {
            if (j > k) break;
            if (!valid(lin, n, i, j)) continue;
            int * nlin = new int[n];
            memcpy(nlin, lin, sizeof(int) * n);
            for (int m = 0; m < j; m++) nlin[(i + m) % n] = 0;
            value = max(value, min_step(nlin, n, k, depth + 1));
            delete nlin;
            if (value == D) return value;
        }
    // for (int i = 0; i < depth; i++) cout << ' ';
    // for (int i = 0; i < n; i++) cout << bool(lin[i]);
    // cout << " A" << (value == D ? "D" : "J") << endl;
    return value;
}

int min_step(int * lin, int n, int k, int depth) {
    int value = D;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++) {
            if (j > k) break;
            if (!valid(lin, n, i, j)) continue;
            int * nlin = new int[n];
            memcpy(nlin, lin, sizeof(int) * n);
            for (int m = 0; m < j; m++) nlin[(i + m) % n] = 0;
            value = min(value, max_step(nlin, n, k, depth + 1));
            delete nlin;
            if (value == J) return value;
        }
    // for (int i = 0; i < depth; i++) cout << ' ';
    // for (int i = 0; i < n; i++) cout << bool(lin[i]);
    // cout << " I" << (value == D ? "D" : "J") << endl;
    return value;
}

int main() {
    int n, k;
    while (1) {
        cin >> n >> k;
        int * lin = new int[n];
        memset(lin, 1, sizeof(int) * n);
        cout << (max_step(lin, n, k, 0) == D ? "D" : "J") << endl;
        delete lin;
    }
    return 0;
}
