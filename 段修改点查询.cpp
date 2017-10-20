#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c[100086];
int origin[100086];
int n, m;

inline int lowbit(int x)
{
    return x & (-x);
}

int get_sum(int i)
{
    int sum = 0;
    while (i != 0)
    {
        sum += c[i];
        i -= lowbit(i);
    }
}

int change_num(int x, int ax)
{
    int i = x;
    while (i < n)
    {
        c[i] += ax;
        i += lowbit(i);
    }
}

int main()
{
    memset(c, 0, sizeof(c));
    memset(origin, 0, sizeof(origin));
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        scanf("%d", &origin[i]);
    for (int i=0; i<m; i++)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            change_num(x, 1);
            change_num(y + 1, -1);
        }
        else
        {
            int z;
            scanf("%d", &z);
            printf("%d\n", get_sum(i) + origin[i]);
        }
    }
    cin.get(),cin.get();
    return 0;
}
