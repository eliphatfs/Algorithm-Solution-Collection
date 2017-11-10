#include <iostream>
#include <cstdio>
using namespace std;
int n, m, r, c;
int num[1008][1008];
int pr[1008][1008];
int ans = 0;

int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        scanf("%d", &num[i][j]);
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        int pt = 0;
        for (int j = 0; j < c; j++)
            cur += num[i][j];
        pr[i][pt++] = cur;
        for (int j = c; j < m; j++)
        {
            cur -= num[i][j - c], cur += num[i][j];
            pr[i][pt++] = cur;
        }
        //n, (m - c + 1)
    }
    for (int j = 0; j < m - c + 1; j++)
    {
        int cur = 0;
        for (int i = 0; i < r; i++)
            cur += pr[i][j];
        if (cur > ans) ans = cur;
        for (int i = r; i < n; i++)
        {
            cur -= pr[i - r][j];
            cur += pr[i][j];
            if (cur > ans) ans = cur;
        }
    }
    cout<<ans;
    //cin.get(), cin.get();
    return 0;
}
