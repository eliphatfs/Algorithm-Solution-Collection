#include <iostream>
const long long P = 1000000007;

struct Mat2 {
    long long d[2][2];
    Mat2(int m11, int m12, int m21, int m22) { d[0][0] = m11; d[0][1] = m12; d[1][0] = m21; d[1][1] = m22; }
};

Mat2 mmul(const Mat2& L, const Mat2& R) {
    Mat2 A = Mat2(0, 0, 0, 0);
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
    for (int k = 0; k < 2; k++)
        A.d[i][j] += (L.d[i][k] * R.d[k][j]) % P;
    return A;
}

Mat2 quick_pow(const Mat2& Q, long long n) {
    Mat2 base = Q;
    Mat2 ans = Mat2(1, 0, 0, 1);
    while (n > 0) {
        if (n % 2 == 1) ans = mmul(ans, base);
        base = mmul(base, base);
        n /= 2;
    }
    return ans;
}

int main() {
    long long n;
    std::cin >> n;
    Mat2 z = Mat2(0, 1, 1, 1);
    Mat2 init = Mat2(1, 1, 1, 1);
    Mat2 result = mmul(quick_pow(z, n), init);
    std::cout << result.d[0][0] % P;
    return 0;
}
