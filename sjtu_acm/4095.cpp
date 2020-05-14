#include <iostream>
#include <cstring>
using namespace std;

int numbers[100000];

int main() {
    int n, m;
    cin >> n >> m;
    if (m == 1) { cout << n; return 0; }
    m--;
    for (int i = 0; i < n; i++) numbers[i] = i + 1;
    register int prvkick = 0;
    for (register int i = n; i > 1; i--) {
        register int twoi = 2 * i - 2;
        prvkick += m;
        prvkick %= twoi;
        register int kicked = prvkick < i ? prvkick : twoi - prvkick;
        memcpy(numbers + kicked, numbers + kicked + 1, sizeof(int) * (i - kicked));
        if (prvkick >= i - 1) prvkick--;
    }
    cout << numbers[0];
    return 0;
}
