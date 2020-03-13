#include <iostream>
#include <cstdio>
using namespace std;
const int AMAX = 100007;

inline int a_threshold(int b, int c) {
    // b ^ 2 - 4ac >= 0
    // a <= b ^ 2 / 4c
    return b * b / 4 / c;
}

int prefix[AMAX] = {0};  // prefix[i]: count a <= i

int main() {
    int n;
    cin >> n;
    int scanned = 0;
    int amaxloc = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &amaxloc);
        for (; scanned < amaxloc; scanned++) prefix[scanned] = i;
    }
    for (; scanned < amaxloc + 1; scanned++) prefix[scanned] = n;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int b; int c;
        scanf("%d%d", &b, &c);
        int athres = a_threshold(b, c);
        if (athres > amaxloc) printf("%d\n", n);
        else printf("%d\n", prefix[athres]);
    }
    return 0;
}
