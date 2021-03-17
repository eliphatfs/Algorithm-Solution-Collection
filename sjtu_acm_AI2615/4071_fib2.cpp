#include <iostream>
using namespace std;
const long long P = 1000000007;
const long long DIV2 = (P + 1) / 2;

struct QPS5 {
    long long Q;
    long long S5;
    QPS5(long long q, long long s5) { Q = q % P; S5 = s5 % P; }
};

inline QPS5 mul(QPS5 a, QPS5 b) {
    return QPS5(a.Q * b.Q + 5 * a.S5 * b.S5, a.Q * b.S5 + a.S5 * b.Q);
}

inline QPS5 quick_pow(long long n) {
    // computes (1 + sqrt(5)) / 2 to n-th power
    QPS5 base(1, 1);
    QPS5 ans(1, 0);
    long long d = n - 1;
    while (n) {
        if (n & 1)
            ans = mul(ans, base);
        base = mul(base, base);
        n >>= 1;
    }
    
    long long baseDiv = DIV2;
    long long divisor = 1;
    while (d) {
        if (d & 1)
            divisor = (divisor * baseDiv) % P;
        baseDiv = (baseDiv * baseDiv) % P;
        d >>= 1;
    }
    return QPS5(ans.Q * divisor, ans.S5 * divisor);
}

int main() {
    long long n;
    cin >> n;
    cout << quick_pow(n + 1).S5;
    return 0;
}
