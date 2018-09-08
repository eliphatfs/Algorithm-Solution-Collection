#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll d[1000007] = {0};
bool b[1000007] = {0};
ll cur_sum;

int main() {
    int n, m;
    cin >> n >> m;
    cur_sum = 0;
    for (int i=1; i<=n; i++) {
        scanf("%lld", &d[i]);
        cur_sum += d[i];
        b[i] = true;
    }
    char buf[5];
    for (int q=0; q<m; q++) {
        scanf("%s", buf);
        char ch = buf[0];
        if (ch == 'C') {
            int x, y;
            scanf("%d%d", &x, &y);
            d[x] -= y;
            cur_sum -= y;
        } else if (ch == 'I') {
            int x, y;
            scanf("%d%d", &x, &y);
            cur_sum -= d[x];
            d[x] = y;
            cur_sum += y;
            b[x] = true;
        } else if (ch == 'D') {
            int x;
            scanf("%d", &x);
            int c = 0;
            for (int i=0; i<500007; i++) {
                if (b[i]) c++;
                if (c == x) {
                    cur_sum -= d[i];
                    d[i] = 0;
                    b[i] = false;
                    break;
                }
            }
        } else if (ch == 'Q') {
            printf("%lld\n", cur_sum);
        }
    }
    return 0;
}
