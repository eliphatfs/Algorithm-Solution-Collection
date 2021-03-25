#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int m[2000000];

inline int med(int a, int b, int c) {
    if (a <= b && b <= c) return b;
    if (b <= a && a <= c) return a;
    if (b <= c && c <= a) return c;
    return b;
}

int med_med_med(int * arr, int n) {
    if (n <= 3) return med(arr[min(0, n - 1)], arr[min(1, n - 1)], arr[min(2, n - 1)]);
    int pt = 0;
    for (int i = 0; i < n - 2; i += 3) {
        m[pt++] = med(arr[i], arr[i + 1], arr[i + 2]);
    }
    return med_med_med(m, pt);
}

int a[6000000];
int quick_sel_a(int n, int k) {
    int p = med_med_med(a, n);
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
