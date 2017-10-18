#include <iostream>
#include <cstdio>
using namespace std;
int f[20000] = {0};
int getf(int c)
{
    if (f[c] == c) return c;
    else
    {
        f[c] = getf(f[c]);
        return f[c];
    }
}
void merge(int u, int v)
{
    int p1 = getf(u);
    int p2 = getf(v);
    if (p1 != p2)
        f[p2] = p1;
}
int main()
{
    int n, m;
    cin>>n>>m;
    for (int i=1; i<=n; i++) f[i] = i;
    for (int c=0; c<m; c++)
    {
        int type;
        scanf("%d", &type);
        if (type == 1)
        {
            int fu, fv;
            scanf("%d%d", &fu, &fv);
            merge(fu, fv);
        }
        else
        {
            int fu, fv;
            scanf("%d%d", &fu, &fv);
            if (getf(fu) == getf(fv))
                printf("Y\n");
            else printf("N\n");
        }
    }
    //cin.get(), cin.get();
    return 0;
}
