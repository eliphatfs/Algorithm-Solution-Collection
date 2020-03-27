#include <iostream>
#include <cstdio>
using namespace std;

double Q[1000007];
double Y[1000007];
double P[1000007];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%lf", &P[i]);
    Q[1] = Y[1] = P[1];
    double s = Y[1];
    for (int i = 2; i <= n; i++) {
        Q[i] = Q[i - 1] * P[i] + (1.0 - P[i - 1]) * P[i];
        Y[i] = Y[i - 1] * P[i] + Q[i - 1] * P[i] * 2.0 + (1.0 - P[i - 1]) * P[i];
        s += Y[i];
    }
    printf("%.6lf", s);
    return 0;
}
