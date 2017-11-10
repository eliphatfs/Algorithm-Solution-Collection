#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int v[2017];
int f[2017][2017];
int n;

int sch(int i, int j)
{
    if (f[i][j] >= 0) return f[i][j];
    if (i == j) f[i][j] = v[i] * n;
    else f[i][j] = max(sch(i+1, j) + v[i] * (n - j + i), sch(i, j-1) + v[j] * (n - j + i));
    return f[i][j];
}

int main()
{
    memset(f, 0x9f, sizeof(f));
    cin>>n;
    for (int i=0; i<n; i++)
        scanf("%d", &v[i]);
    cout<<sch(0, n-1);
    //cin.get(), cin.get();
    return 0;
}
