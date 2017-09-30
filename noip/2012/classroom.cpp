#include <iostream>
#include <cstdio>
#include <time.h>

using namespace std;
long long r[1000001];
long long d[1000001];
long long s[1000001];
long long t[1000001];

long long q1[1000001];
long long q2[1000001];
int n, m;

int judge(int test)
{
    memset(q1, 0, sizeof(q1));
    memset(q2, 0, sizeof(q2));
    for (int i=1; i<=test; i++)
    {
        q1[s[i]] += d[i];
        q1[t[i]+1] -= d[i];
    }
    for (int i=1; i<=n; i++)
    {
        q2[i] = q2[i-1] + q1[i];
    }
    for (int i=1; i<=n; i++)
    {
        if (r[i] - q2[i] < 0)
            return 0;
    }
    return 1;
}

int sch(int l, int r)
{
    int m = (l + r) >> 1;
    int a = judge(m);
    if (!a)
    {
        return sch(l, m);
    }
    int b = judge(m + 1);
    if (b)
    {
        return sch(m + 1, r);
    }
    return m + 1;
}
int main()
{
    int bg = clock();
    freopen("classroom20.in", "r", stdin);
    freopen("classroom.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &r[i]);
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &d[i], &s[i], &t[i]);
    }
    if (judge(n))
        cout<<0;
    else
        cout<<-1<<endl<<sch(1, n);
    int end = clock();
    cout<<endl<<(end-bg);
    return 0;
}
