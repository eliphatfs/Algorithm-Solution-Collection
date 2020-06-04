#include <iostream>
#include <cstdio>
using namespace std;

inline int imax(int a, int b) { return a > b ? a : b; }
inline double dmax(double a, double b) { return a > b ? a : b; }

inline int simu(int a, int b, int c, int d, int e) {
    int xc = 1;
    for (int i = 1; i <= e; i++) {
        if (rand() % 100 < a + imax(xc - c, 0) * d) {
            xc = 1;
            if (rand() % 100 < b) return i;
        }
        else xc++;
    }
    return e;
}

double hard(int a, int b, int c, int d, int e) {
    long long stime = 0;
    int t = 0;
    while (stime < 50000000) {
        stime += simu(a, b, c, d, e);
        t += 1;
    }
    return stime / (double)t;
}

double softer(int a, int b, int c, int d, int e) {
    double ans = 0.0;
    double prob = 1.0;
    double * k0 = new double[e + 1];
    for (int i = 1; i <= e; i++) k0[i] = 0.0;
    k0[0] = 1.0;

    for (int i = 1; i < e; i++) {
        double psix = 0.0;
        for (int k = 0; k <= e; k++) {
            double shift = min(1.0, (a + dmax(i - k - c, 0) * d) / 100.0);
            psix += k0[k] * shift;
            k0[k] *= prob * (1 - shift);
        }
        double pm = prob * psix * (b / 100.0);
        k0[i] = psix * prob - pm;
        for (int k = 0; k <= e; k++) k0[k] /= (prob - pm);

        ans += pm * i;
        prob -= pm;
        if (prob < 1e-3 / e) return ans;
    }
    ans += prob * e;
    return ans;
}

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    printf("%.2lf", softer(a, b, c, d, e));
    cin.get(), cin.get();
    return 0;
}
