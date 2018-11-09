#include <iostream>
#include <cstdio>
using namespace std;
bool lesser[50004] = {0};
bool greaterx[1000007] = {0};

int current_lesser = 2;

int main() {
    long long l, r;
    cin >> l >> r;

    while (current_lesser < 50000) {
        for (int i = current_lesser * 2; i < 50001; i += current_lesser) {
            lesser[i] = true;
        }
        do {
            ++current_lesser;
        } while (current_lesser < 50000 && lesser[current_lesser]);
    }
    for (int prime = 2; prime < 50000; ++prime) {
        if (lesser[prime]) continue;
        long long s = (l / prime * prime);
        while (s < l) s += prime;
        while (s == prime) s += prime;
        for (; s <= r; s += prime) {
            greaterx[s - l] = 1;
        }
    }
    int ans = 0;
    if (l == 1) l++;
    for (long long i=l; i<=r; i++) {
        if (!greaterx[i - l]) {
            ++ans;
        }
    }
    cout<<ans;
    // getchar(), getchar();
}
