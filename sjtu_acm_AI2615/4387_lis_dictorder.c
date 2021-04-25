#include <stdio.h>

int n;
int seq[10001];

int memo[10001];
int pre[10001], posta[10001], postb[10001];

static int paste(int p, int * post) {
    post[p] = -1;
    while (pre[p] >= 0) { post[pre[p]] = p; p = pre[p]; }
    return p;
}

static int compare_posts(int pa, int pb) {
    while (pa != -1 && pb != -1)
        if (seq[pa] != seq[pb])
            return seq[pa] - seq[pb];
        else { pa = posta[pa]; pb = postb[pb]; }
    if (pa != -1) return 1;
    if (pb != -1) return -1;
    return 0;
}

int lis_end_at(int k) {
    if (memo[k] > 0) return memo[k];
    int ans = 1;
    for (register int i = 0; i < k; i++)
        if (seq[i] < seq[k]) {
            register int leai = memo[i];
            if (memo[i] >= ans) {
                pre[k] = i;
                ans = leai + 1;
            }
        }
    for (register int i = 0; i < k; i++)
        if (seq[i] < seq[k]) {
            if (memo[i] + 1 == ans && i != pre[k]) {
                int cmpp = compare_posts(paste(i, posta), paste(pre[k], postb));
                if (cmpp < 0) pre[k] = i;
            }
        }
    return memo[k] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", seq + i);
    for (int i = 0; i < 10001; i++) pre[i] = -1;
    
    int maxi = 0, maxd = 0;
    for (int i = 0; i < n; i++)
        if (lis_end_at(i) > maxd) {
            maxd = lis_end_at(i);
            maxi = i;
        }
    for (int i = 0; i < n; i++)
        if (lis_end_at(i) == maxd && i != maxi) {
            int cmpp = compare_posts(paste(i, posta), paste(maxi, postb));
            if (cmpp < 0) maxi = i;
        }
    printf("%d\n", maxd);
    int p = paste(maxi, posta);
    while (p != maxi) { printf("%d ", seq[p]); p = posta[p]; }
    printf("%d\n", seq[p]);
    return 0;
}
