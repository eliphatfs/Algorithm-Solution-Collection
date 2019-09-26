#include <stdio.h>
#include <string.h>
int n, m;
int arr[1007][1007];
int pref[1007][1007];

int sum_field(nl, ml, mh) {
    return pref[nl][mh] - pref[nl][ml];
}


int main() {
    scanf("%d%d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int w, h;
    scanf("%d%d", &w, &h);
    int u;
    int ans = 0;
    for (i = 0; i < n; i++) {
        pref[i][0] = arr[i][0];
        for (j = 1; j < m; j++)
            pref[i][j] = pref[i][j - 1] + arr[i][j];
    }
    for (u = 0; u <= m - h; u++) {
        int temp = 0;
        for (i = 0; i < w; i++) temp += sum_field(i, u, u + h);
        if (temp > ans) ans = temp;
        for (j = 0; j <= n - w; j++) {
            temp -= sum_field(j, u, u + h);
            temp += sum_field(j + w, u, u + h);
            if (temp > ans) ans = temp;
        }
    }
    printf("%d", ans);
    return 0;
}
