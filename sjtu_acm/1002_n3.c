#include <stdio.h>
#include <string.h>
int n, m;
    int w, h;
int arr[1007][1007];

int sum_field0h(nl, nh) {
    int i, j;
    int s = 0;
    for (j = 0; j < h; j++) {
        for (i = nl; i < nh; i++) {
            s += arr[j][i];
        }
    }
    return s;
}

int sum_field1(nl, nh, ml) {
    int i;
    int s = 0;
    for (i = nl; i < nh; i++) {
        s += arr[ml][i];
    }
    return s;
}

int main() {
    scanf("%d%d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[j][i]);
        }
    }
    scanf("%d%d", &w, &h);
    int u;
    int ans = 0;
    u = 0;
    int temp1;
    int temp = sum_field0h(u, u + w);
    temp1 = temp;
    if (temp > ans) ans = temp;
    for (j = 0; j <= m - h; j++) {
        temp -= sum_field1(u, u + w, j);
        temp += sum_field1(u, u + w, j + h);
        if (temp > ans) ans = temp;
    }
    for (u = 1; u <= n - w; u++) {
        temp = temp1 - sum_field0h(u - 1, u) + sum_field0h(u + w - 1, u + w);
        temp1 = temp;
        if (temp > ans) ans = temp;
        for (j = 0; j <= m - h; j++) {
            temp -= sum_field1(u, u + w, j);
            temp += sum_field1(u, u + w, j + h);
            if (temp > ans) ans = temp;
        }
    }
    printf("%d", ans);
    return 0;
}
