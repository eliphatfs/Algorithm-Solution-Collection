#include <iostream>
using namespace std;

long long h[507][507];
int m, n;
long long v;

inline long long volumn(long long c) {
    long long cv = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (c > h[i][j]) cv += c - h[i][j];
    return cv;
}

long long binsearch(long long a, long long b) {  // [a, b)
    if (a >= b) return a;
    long long c = (a + b) / 2;
    long long cv = volumn(c);
    if (cv == v) return c;
    if (cv < v) return binsearch(c + 1, b);
    else return binsearch(a, c);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            scanf("%lld", &h[i][j]);
            h[i][j] *= 10000;
        }
    scanf("%lld", &v);
    v *= 10000;
    long long hx = binsearch(0, 2000000000000LL);
    printf("%.2lf\n", hx / 10000.0);
    
    int dcount = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (hx > h[i][j]) ++dcount;
    printf("%.2lf", dcount * 100 / (double)(m * n));
    return 0;
}
