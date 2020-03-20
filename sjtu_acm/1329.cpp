#include <iostream>
using namespace std;

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int * req = new int[m * 2];
    int * mask = req + m;
    for (int i = 0; i < m; i++) {
        int cmask = 0;
        int creq = 0;
        do {
            int req;
            scanf("%d", &req);
            if (req > 0) { creq |= (1 << (req - 1)); cmask |= (1 << (req - 1)); }
            else { cmask |= (1 << (-req - 1)); }
            while (cin.peek() == ' ' || cin.peek() == '\r') cin.get();
        } while (cin.peek() != '\n');
        req[i] = creq; mask[i] = cmask;
    }
    int topp = 1 << n;
    for (register int i = 0; i < topp; ++i) {
        bool flag = true;
        for (register int j = 0; j < m; ++j) {
            if ((~(i ^ req[j]) & mask[j]) == 0) {
                flag = false; break;
            }
        }
        if (flag) {
            printf("Bingo!\n");
            delete req;
            return;
        }
    }
    printf("Sigh...\n");
    delete req;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}
