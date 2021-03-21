#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

// This is a FFT that goes through extreme micro-optimization to pass n = 1e6
// within a recursive framework.
// Not quite elegant, leave it.

const double PI = 3.1415926535897932384626433832795;

struct complex {
    double x, y;
    complex() { x = y = 0; }
    complex(double real, double imag) { x = real; y = imag; }
    inline friend complex operator*(const complex& a, const complex& b) {
        return complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
    }
    inline friend complex operator+(const complex& a, const complex& b) {
        return complex(a.x + b.x, a.y + b.y);
    }
    const complex& operator+=(const complex& b) {
        x += b.x; y += b.y; return *this;
    }
    const complex& operator-=(const complex& b) {
        x -= b.x; y -= b.y; return *this;
    }
};

inline complex elementary(const register int k, const register int N) {
    register double arg = 2 * PI * k / N;
    return complex(cos(arg), sin(arg));
}

const int FT = -1; const int IFT = 1;

complex buffer[4194304 / 2];
complex elements[4194305];

void inplace_ft(complex * f, int direction, unsigned start, unsigned N) {
    if (N == 1) return;
    for (int i = 0; i < N / 2; i++) {
        buffer[i] = f[start + 2 * i];
        buffer[N / 2 + i] = f[start + 2 * i + 1];
    }
    memcpy(f + start, buffer, sizeof(complex) * N);
    inplace_ft(f, direction, start, N / 2);
    inplace_ft(f, direction, start + N / 2, N / 2);
    memcpy(buffer, f + start, sizeof(complex) * (N / 2));
    memcpy(buffer + N / 2, f + start, sizeof(complex) * (N / 2));
    if (direction == 1) {
        for (unsigned i = 0; i < N / 2; i++) {
            complex rot = f[start + N / 2 + i] * elements[N + i];
            buffer[i] += rot;
            buffer[i + N / 2] -= rot;
        }
    }
    else {
        for (unsigned i = 0; i < N / 2; i++) {
            complex rot = f[start + N / 2 + i] * elements[N + N - i];
            buffer[i] += rot;
            buffer[i + N / 2] -= rot;
        }
    }
    memcpy(f + start, buffer, sizeof(complex) * N);
}

inline int read_digit() {
    while (true) {
        char ch = getchar();
        if (ch >= '0' && ch <= '9') return ch - '0';
    }
}

complex A[4194304 / 2], B[4194304 / 2];
int main() {
    unsigned n, m; scanf("%u%u", &n, &m);
    for (unsigned i = 0; i < n + 1; i++) { A[i] = (complex(read_digit(), 0)); }
    for (unsigned i = 0; i < m + 1; i++) { B[i] = (complex(read_digit(), 0)); }
    
    int pad = 1;
    while (pad < m + n + 1) pad *= 2;
    
    for (int i = 0; i < pad; i++)
        elements[pad + i] = elementary(i, pad);
    for (int k = 1; k < pad; k *= 2)
        for (int i = 0; i < k; i++)
            elements[k + i] = elements[pad + i * (pad / k)];
    elements[pad + pad] = elements[pad];

    inplace_ft(A, FT, 0, pad); inplace_ft(B, FT, 0, pad);
    for (unsigned i = 0; i < pad; i++) A[i] = A[i] * B[i];
    inplace_ft(A, IFT, 0, pad);
    for (unsigned i = 0; i < m + n + 1; i++) printf("%d ", (int)(0.5 + A[i].x / pad));
    return 0;
}
