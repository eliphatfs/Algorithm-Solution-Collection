#include <stdio.h>
#include <math.h>

int a[300000];
int rr[300000];
int m, n;

void merge_sort(int l, int r);

void merge_sort(int l, int r)
{
    if (l >= r - 1) return;
    int m = (l + r) >> 1;
    merge_sort(l, m);
    merge_sort(m, r);
    int p1; int p2; int k;
    p1 = l;
    k = l;
    p2 = m;
    while (p1 < m && p2 < r)
    {
        if (a[p1] < a[p2])
            rr[k++] = a[p1++];
        else
            rr[k++] = a[p2++];
    }
    while (p1 < m)
        rr[k++] = a[p1++];
    while (p2 < r)
        rr[k++] = a[p2++];
    int i;
    for (i=l; i<r; i++)
        a[i] = rr[i];
}

int findm(int l, int r, int target)
{
    if (target > a[r]) return target - a[r];
    else if (target < a[l]) return a[l] - target;
    
    int m = (l + r) >> 1;
    if (target < a[m]) return findm(l, m, target);
    else if (target > a[m + 1]) return findm(m + 1, r, target);
    else
    {
        int ls = abs(target - a[m]);
        int rs = abs(target - a[m + 1]);
        return ls < rs ? ls : rs;
    }
}

int main()
{
    scanf("%d%d", &m, &n);
    int i;
    for (i=0; i<m; i++)
        scanf("%d", &a[i]);
    merge_sort(0, m);

    long long ans = 0;
    for (i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        ans += findm(0, m - 1, tmp);
    }
    printf("%d", ans);
    
    //getchar(), getchar();
    return 0;
}
