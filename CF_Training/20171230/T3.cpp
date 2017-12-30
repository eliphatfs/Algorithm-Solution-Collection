#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

int n, p;
int co[200000];
int ini[200000];

bool judge(double v)
{
    double needed = 0;
    for (int i=0; i<n; i++)
        if (co[i] * v > ini[i])
            needed += co[i] * v - ini[i];
    return p * v >= needed;
}

double bsch(double left, double right)
{
    double mid = (left + right) / 2.0;
    bool jm = judge(mid);
    bool jn = judge(mid + 0.00001 * max(1.0, mid));
    if (jn) return bsch(mid, right);
    else if (!jm) return bsch(left, mid);
    else return mid;
}

int main()
{
    cin>>n>>p;
    for (int i=0; i<n; i++)
        scanf("%d%d", &co[i], &ini[i]);
    long long cosum = 0;
    for (int i=0; i<n; i++)
        cosum += co[i];
    if (cosum <= p) cout<<-1;
    else
        cout << bsch(0, 1e100);
    //cin.get(), cin.get();
    return 0;
}
