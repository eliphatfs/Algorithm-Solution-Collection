#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

unsigned seed = 1337;
inline unsigned lcg(unsigned n) {
    return (seed *= 31) % n;
}

int a[6000000];
int quick_sel_a(int n, int k) {
    int p = a[lcg(n)];
    int cless = 0, cgreater = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < p) ++cless;
        else if (a[i] > p) ++cgreater;
    if (cless > k) {
        int pt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < p) a[pt++] = a[i];
        return quick_sel_a(pt, k);
    } else if (n - cgreater <= k) {
        int pt = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > p) a[pt++] = a[i];
        return quick_sel_a(pt, k - (n - cgreater));
    } else return p;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d", quick_sel_a(n, k - 1));
    return 0;
}
