#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
long long dx[20008];
long long dy[20008];
struct point
{
    long long x, y;
    bool operator<(point o)const
    {
        if (x < o.x) return true;
        if (x == o.x && y < o.y) return true;
        return false;
    }
};
map<point, bool> ptmap;
int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
        scanf("%lld%lld", &dx[i], &dy[i]);
    long long sumx = 0;
    long long sumy = 0;
    for (int i=0; i<n; i++)
    {
        point p;
        p.x = dx[i];
        p.y = dy[i];
        ptmap[p] = true;
        sumx += dx[i];
        sumy += dy[i];
    }
    long double vx = sumx / (long double)n;
    long double vy = sumy / (long double)n;
    bool flag = true;
    for (int i=0; i<n; i++)
    {
        point p;
        p.x = (long long)(vx * 2 - dx[i] + 0.01 + 12345678) - 12345678;
        p.y = (long long)(vy * 2 - dy[i] + 0.01 + 12345678) - 12345678;
        //cout<<p.x<<' '<<p.y<<endl;
        if (ptmap.find(p) == ptmap.end())
        {
            flag = false;
            break;
        }
    }
    if (flag)
        printf("V.I.P. should stay at (%.1lf,%.1lf).", (double)vx, (double)vy);
    else
        printf("This is a dangerous situation!");
    //cin.get(), cin.get();
    return 0;
}
