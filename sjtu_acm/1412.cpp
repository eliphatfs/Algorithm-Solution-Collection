#include <iostream>
#include <cstring>
using namespace std;
char a[1017] = {};
char b[1017] = {};
char c[1017] = {};
const char zero[1017] = {};
char binary[4007] = {};

template<typename T>
void do_swap(T& a, T& b) {
    T c = a; a = b; b = c;
}

template<typename T>
void reverse_str(T * x, int slen) {
    for (int i = 0; i < slen / 2; i++) do_swap(x[i], x[slen - 1 - i]);
}

void minus48(char * x, int slen) {
    for (int i = 0; i < slen; i++) x[i] -= '0';
}

void output(char * buffer, int maxlen) {
    int i;
    for (i = maxlen; i > 0; i--) if (buffer[i] != 0) break;
    for (; i >= 0; i--) cout << (char)(buffer[i] + '0');
}

int compare_ab(const char * aa, const char * bb) {
    for (int i = 506; i >= 0; i--)
        if (aa[i] > bb[i]) return 1;
        else if (aa[i] < bb[i]) return -1;
    return 0;
}

void inplace_sub(char * dst, char * suber) {
    for (int i = 0; i < 506; i++) {
        dst[i] -= suber[i];
        if (dst[i] < 0) { dst[i + 1]--; dst[i] += 10; }
    }
}

void inplace_mod(char * dst, char * modder) {
    for (int i = 506; i >= 0; i--)
        while (compare_ab(dst + i, modder) >= 0)
            inplace_sub(dst + i, modder);
}

void binarize(char * dst, char * src) {
    int dpt = 0;
    while (compare_ab(src, zero) > 0) {
        dst[dpt++] = src[0] % 2;
        for (int i = 506; i >= 0; i--) {
            if (src[i] % 2 == 1 && i > 0)
                src[i - 1] += 10;
            src[i] /= 2;
        }
    }
}

void calc_gcd(char * aa, char * bb) {
    if (compare_ab(aa, zero) == 0) {
        memcpy(c, bb, sizeof(c));
        return;
    }
    inplace_mod(bb, aa);
    calc_gcd(bb, aa);
}

int main() {
    cin >> a;
    cin >> b;
    reverse_str(a, strlen(a));
    reverse_str(b, strlen(b));
    minus48(a, strlen(a));
    minus48(b, strlen(b));
    if (compare_ab(a, b) < 0) calc_gcd(a, b); else calc_gcd(b, a);
    binarize(binary, c);
    output(binary, 4006);
    return 0;
}
