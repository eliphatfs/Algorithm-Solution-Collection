#include <iostream>
#include <cstdio>
using namespace std;

bool used[1 << 25];
bool chosen[1 << 25];

int main() {
    int k;
    cin >> k;
    int n = 0;
    int M = 1 << k;
    
    int L = 0;
    while (L < M) {
        if (!used[L]) {
            used[L] = true;
            chosen[L] = true;
            n++;
            for (int j = 0; j < k; j++) {
                for (int p = 0; p < k; p++) {
                    used[L ^ (1 << j) ^ (1 << p)] = true;
                }
            }
            for (int i = 0; i < k; i++) {
                used[L ^ (1 << i)] = true;
            }
        }
        L++;
    }
    cout << n << endl;
    for (int i = 0; i < M; i++)
        if (chosen[i])
            printf("%d\n", i);
    return 0;
}
