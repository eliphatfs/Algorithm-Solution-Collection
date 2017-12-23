#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
using namespace std;

int sq[501][501];

int chxs[501];

int main()
{
    int n, m, t;
    cin>>n>>m>>t;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=m; j++)
        scanf("%d", &sq[i][j]);
    
    int ed = 150000000 / n;
    int maxc = 150000000 / t / n;
    for (int i=0; i<t; i++)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        int cu_sum = 0;
        for (int z=0; z<k; z++)
            cu_sum += sq[x+z][y+z];
        bool ok = true;
        for (int rn = 0; rn < maxc; rn++)
        {
            int t_sum = 0;
            for (int z=0; z<k; z++)
                chxs[y+z] = y+z;
            for (int z=0; z<k; z++)
            {
                int cx, cy;
                cx = rand() % k + y;
                cy = rand() % k + y;
                register int p = chxs[cx];
                chxs[cx] = chxs[cy];
                chxs[cy] = p;
            }
            for (int z=0; z<k; z++)
            {
                t_sum += sq[x+z][chxs[z+y]];
            }
            if (cu_sum != t_sum)
            {
                printf("N\n");
                ok = false;
                ed -= rn;
                maxc = ed / (t - i);
                break;
            }
        }
        if (ok)
            printf("Y\n");
    }
    //cin.get(), cin.get();
    return 0;
}
