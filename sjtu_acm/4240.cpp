#include <iostream>
#include <cstdio>
using namespace std;

char buck[4100000] = {0};

int main() {
    int s;
    cin >> s;
    for (int i = 0; i < s; i++) {
        int x;
        scanf("%d", &x);
        buck[x + 2000000] = 1;
    }
    int p;
    cin >> p;
    for (int i = 0; i < p; i++) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 0) buck[x + 2000000] = 0;
        else buck[x + 2000000] = 1;
    }
    for (int i = 0; i < 4100000; i++) {
        for (int j = 0; j < buck[i]; j++)
            printf("%d ", i - 2000000);
    }
    return 0;
}
