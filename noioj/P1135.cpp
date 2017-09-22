#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct per {
    int s,w,l,r;
    bool operator<(per oth)const
    {
        return r < oth.r;
    }
};
per d[500001];
int ans = 0;
int lst = -10000000;
int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        scanf("%d%d", &d[i].s, &d[i].w);
        d[i].l = d[i].s - d[i].w;
        d[i].r = d[i].s + d[i].w;
    }
    sort(d, d + n);
    for (int i=0; i<n; i++)
    {
        if (d[i].l > lst)
        {
            ans++;
            lst = d[i].r;
        }
    }
    cout<<ans;
    //getchar(),getchar();
    return 0;
}
