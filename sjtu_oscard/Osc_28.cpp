#include <iostream>
#include <cstdio>
using namespace std;

int n;
int next_pred[100007];
// bool key_ok[1000007] = {0};
int kv[100007][2];
int hashtable[100007] = {0};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &kv[i][0], &kv[i][1]);
    for (int i = 0; i < n; i++)
        next_pred[i] = i;
    for (int i = 0; i < n; i++) {
        int hashvalue = kv[i][0] % n;
        while (hashtable[next_pred[hashvalue]]) {
            ++next_pred[hashvalue];
            if (next_pred[hashvalue] >= n) next_pred[hashvalue] -= n;
        }
        hashtable[next_pred[hashvalue]++] = kv[i][1];
        next_pred[hashvalue] %= n;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", hashtable[i]);
    }
    // cin.get(), cin.get();
    return 0;
}
