#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int nmap[11][11];
int maxl[11][11][11][11];
int maxof(int v1, int v2, int v3, int v4)
{
    return max(max(max(v1, v2), v3), v4);
}
int main()
{
    //freopen("testdata.in", "r", stdin);
    int n;
    cin>>n;
    for (int x=1; x<=n; x++)
        for (int y=1; y<=n; y++)
            nmap[x][y] = 0;
            
    while (true) {
        int xx, yy, va;
        scanf("%d%d%d", &xx, &yy, &va);
        if ((va == 0) && (xx == 0) && (yy == 0))
            break;
        nmap[xx][yy] = va;
    }
    
    int x1, x2, y1, y2;
    for (x1 = 1; x1 <= n; x1++)
        for (y1 = 1; y1 <= n; y1++)
            for (x2 = 1; x2 <= n; x2++)
                for (y2 = 1; y2 <= n; y2++)
                {
                    int m[4] = {0, 0, 0, 0};
                    if (x1 > 0 && x2 > 0) m[0] = maxl[x1-1][y1][x2-1][y2];
                    if (y1 > 0 && x2 > 0) m[1] = maxl[x1][y1-1][x2-1][y2];
                    if (x1 > 0 && y2 > 0) m[2] = maxl[x1-1][y1][x2][y2-1];
                    if (y1 > 0 && y2 > 0) m[3] = maxl[x1][y1-1][x2][y2-1];
                    maxl[x1][y1][x2][y2] = maxof(m[0], m[1], m[2], m[3]) + nmap[x1][y1] + nmap[x2][y2];
                    if ((x1 == x2) && (y1 == y2))
                        maxl[x1][y1][x2][y2] -= nmap[x2][y2];
                    //cout << x1 << y1 << x2 << y2 << ":" << maxl[x1][y1][x2][y2] << endl;
                }
    cout<<maxl[n][n][n][n];
    /*freopen("CON", "r", stdin);
    cin.get();cin.get();*/
    return 0;
}
