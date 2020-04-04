#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
bool is_prime[42] = {};

void generate_prime_table() {
    for (unsigned i = 0; i < sizeof(primes) / sizeof(int); i++)
        is_prime[primes[i]] = true;
}

bool dfs(int n, int * ring, int k, bool * book) {
    if (k == n) {
        if (is_prime[ring[n - 1] + ring[0]]) {
            for (int i = 0; i < n; i++)
                printf("%d ", ring[i]);
            printf("\n");
            return true;
        }
        else return false;
    }
    bool result = false;
    for (int next = 2; next <= n; next++) {
        if (!book[next] && is_prime[ring[k - 1] + next]) {
            ring[k] = next;
            book[next] = true;
            result |= dfs(n, ring, k + 1, book);
            book[next] = false;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    generate_prime_table();
    int * ring = new int[n + 1];
    bool * book = new bool[n + 1];
    memset(book, 0, sizeof(bool) * (n + 1));
    ring[0] = 1; book[1] = true;
    if (!dfs(n, ring, 1, book)) cout << "None" << endl;
    delete ring;
    delete book;
    return 0;
}
