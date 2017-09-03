#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a, b;
int data[100007];
int bsearch (int l, int r, int value);
bool judge(int maxl);
int main()
{
    scanf("%d%d", &a, &b);
    for (int i=0; i<a; i++)
        scanf ("%d", &data[i]);
    sort(data, data + a);
    int first = data[0];
    int last = data[a-1];
    
    int l = 0;
    int r = (last - first) / (b - 1) + 1;
    int m = (l + r) / 2;
    while (l < r)
    {
        m = (l + r) / 2;
        bool jm = judge(m);
        bool jmn = judge(m+1);
        if (jm && (!jmn))
        {
            cout<<m;
            //getchar();
            //getchar();
            return 0;
        }
        else if (!jm)
        {
            r = m - 1;
        }
        else l = m + 1;
    }
    
    int now = r + 5;
    while (!judge(now)) now--;
    cout<<now;
    //getchar();
    //getchar();
    return 0;
}

bool judge(int maxl)
{
    int tosch = 0;
    for (int i=0; i<b; i++)
    {
        int pos = bsearch (0, a-1, tosch);
        if (pos == -1) return false;
        tosch = data[pos] + maxl;
    }
    return true;
}

int bsearch (int l, int r, int value)
{
    if (value > data[a-1]) return -1;
    if (value <= data[0]) return 0;
    if (l > r) return -1;
    int m = (l + r) / 2;
    if (data[m]>=value && data[m-1] < value)
        return m;
    else if (data[m]<value) return bsearch(m + 1, r, value);
    else if (data[m-1]>= value) return bsearch(l, m - 1, value);
}
