#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int dat[1000086] = {0};
int cnt[2017] = {0};
int minl = 1048576;
int ansa, ansb;
int counter;
inline bool judge()
{
    return (counter == 0);
}
int main()
{
    cin>>n>>m;
    counter = m;
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &dat[i]);
    }
    counter--;
    cnt[dat[1]]++;
    if (judge())
    {
        cout<<1<<" "<<1;
        return 0;
    };
    int nowpt = 2;
    for (int i=2; i<=n; i++)
    {
        cnt[dat[i-1]]--;
        if (cnt[dat[i-1]] == 0)
            counter++;
        for (; nowpt<=n; nowpt++)
        {
            if(judge())
            {
                if (nowpt-i<minl)
                {
                    ansa = i;
                    ansb = nowpt-1;
                    minl = nowpt-i;
                }
                break;
            }
            if(cnt[dat[nowpt]] == 0)
                counter--;
            cnt[dat[nowpt]]++;
        }
    }
    if (ansa == 0) cout<<1<<" "<<n;
    else cout<<ansa<<" "<<ansb;
    //cin.get();cin.get();
    return 0;
}

