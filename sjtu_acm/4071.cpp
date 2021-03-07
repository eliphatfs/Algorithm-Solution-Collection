#include <iostream>
using namespace std;
typedef long long LL;

struct mat22 {
    LL m11, m12, m21, m22;
    
    mat22() {}
    
    mat22(LL d11, LL d12, LL d21, LL d22) {
        m11 = d11; m12 = d12;
        m21 = d21; m22 = d22;
    }
    
    mat22 operator*(const mat22& o) {
        return mat22(
            m11 * o.m11 + m12 * o.m21,
            m11 * o.m12 + m12 * o.m22,
            m21 * o.m11 + m22 * o.m21,
            m21 * o.m12 + m22 * o.m22
        );
    }
    
    static mat22 eye() { return mat22(1, 0, 0, 1); }
    
    mat22 operator%(LL p) {
        return mat22(m11 % p, m12 % p, m21 % p, m22 % p);
    }
    
    mat22 pow_mod(LL n, LL p) {
        mat22 base = *this;
        mat22 result = eye();
        while (n) {
            if (n % 2 == 1) {
                result = (result * base) % p;
            }
            base = (base * base) % p;
            n /= 2;
        }
        return result;
    }
};

const LL P = 1000000007;
int main() {
    LL n;
    mat22 Fib(0, 1, 1, 1);
    mat22 x0(1, 1, 1, 1);
    cin >> n;
    mat22 ans = Fib.pow_mod(n, P) * x0;
    cout << ans.m11 % P;
    return 0;
}
