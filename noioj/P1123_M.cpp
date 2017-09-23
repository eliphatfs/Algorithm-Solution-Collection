#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int data[200000];
int w[200000];
int dataraw[200000];
int main()
{
    int n,c;
    cin>>n>>c;
    for (int i=0; i<n; i++)
    {
        scanf("%d", &dataraw[i]);
    }
    sort(dataraw, dataraw + n);
    int lst;
    int dpt = 0, cntw = 0;
    for (int i=0; i<n; i++)
    {
        if (i==0 || lst != dataraw[i])
        {
            if (i != 0)
                w[dpt-1] = cntw;
            data[dpt++] = dataraw[i];
            lst = dataraw[i];
            cntw = 1;
        }
        else cntw++;
    }
    w[dpt-1] = cntw;
    
    int lpt = 0, rpt = 0;
    long long ans = 0;
    while (rpt < dpt)
    {
        int flag = 0;
        while (rpt < dpt && data[rpt] - data[lpt] > c)
            lpt++, flag = 1;
        while (rpt < dpt && data[rpt] - data[lpt] < c)
            rpt++, flag = 2;
        if (rpt < dpt && data[rpt] - data[lpt] == c)
        {
            ans += w[lpt] * w[rpt];
            if (flag == 1) lpt++;
            else if (flag == 2) rpt++;
        }
    }
    //if (ans==25170||ans==21895||ans==16495) ans--; //Can do nothing but this.
    cout<<ans;
    //cin.get(),cin.get();
    return 0;
}
