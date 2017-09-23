#include <iostream>
#include <cstdio>
using namespace std;

int d[50211] = {0};
int sch(int l, int r, int q)
{
    int m = (l + r) >> 1;
    if (q < d[m])
    {
        return sch(l, m, q);
    }
    else if (q >= d[m] && q < d[m+1]) return m;
    else return sch(m + 1, r, q);
}

int main()
{
    int n, q;
    cin>>n>>q;
    for (int i=1; i<=n; i++)
    {
        int b;
        scanf("%d", &b);
        d[i] = d[i-1] + b;
    }
    for (int i=0; i<q; i++)
    {
        int qr;
        scanf("%d", &qr);
        printf("%d\n", sch(0, n, qr) + 1);
    }
    //cin.get(),cin.get();
    return 0;
}
