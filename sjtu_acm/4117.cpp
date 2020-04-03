#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long pref[100086];
long long chng[100086];
long long block[10086];
long long block_sum[10086];
int n, q;
int pb;

#define block_of(x) (x / pb)
#define next_block(x) ((x + pb - 1) / pb)
#define ptcg(x) (chng[x] + block[x / pb])

int main() {
    scanf("%d%d", &n, &q);
    pb = (int)sqrt(n);  // i * pb -> (i + 1) * pb
    for (int i = 1; i <= n; i++) { scanf("%lld", &pref[i]); pref[i] += pref[i - 1]; }
    
    char op[3];
    for (int z = 0; z < q; z++) {
        scanf("%s", op);
        if (op[0] == 'Q') {
            int x, y;
            scanf("%d%d", &x, &y);
            long long ans = pref[y] - pref[x - 1];
            int nextblockx = next_block(x);
            if (y - x <= pb) for (int i = x; i <= y; i++) ans += ptcg(i);
            else {
                for (int i = x; i < nextblockx * pb; i++) ans += ptcg(i);
                for (int i = nextblockx; i < block_of(y); i++) ans += block[i] * pb + block_sum[i];
                for (int i = block_of(y) * pb; i <= y; i++) ans += ptcg(i);
            }
            printf("%lld\n", ans);
        }
        else {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            int nextblockx = next_block(x);
            if (y - x <= pb) for (int i = x; i <= y; i++) { chng[i] += c; block_sum[block_of(i)] += c; }
            else {
                for (int i = x; i < nextblockx * pb; i++) { chng[i] += c; block_sum[block_of(i)] += c; }
                for (int i = nextblockx; i < block_of(y); i++) block[i] += c;
                for (int i = block_of(y) * pb; i <= y; i++) { chng[i] += c; block_sum[block_of(i)] += c; }
            }
        }
    }
    return 0;
}
