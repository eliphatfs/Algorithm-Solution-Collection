#include <iostream>
#include <cstdio>
using namespace std;
int a[100000];
int c[100000];
int tot = 0;

void merge_sort(int l, int r)
{
    if (l >= r - 1) return;
    int m = (l + r) >> 1;
    merge_sort(l, m);
    merge_sort(m, r);
    int i = l;
    int j = m;
    int k = l;
    while (i < m && j < r)
    {
        if (a[i] <= a[j])
            c[k++] = a[i++];
        else
        {
            c[k++] = a[j++];
            tot += m - i;
        }
    }
    while (i < m) c[k++] = a[i++];
    while (j < r) c[k++] = a[j++];
    for (int x = l; x < r; x++)
        a[x] = c[x];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(0, n);
    cout << tot;
    //cin.get(), cin.get();
    return 0;
}
