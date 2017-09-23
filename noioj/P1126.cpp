#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int rules[10][16] = {0};
bool visited[10086] = {0};
long long ans = 0;
int n,k;
queue<int> nums = queue<int>();

int main()
{
    cin>>n>>k;
    for (int i=0; i<k; i++)
    {
        int d1, d2;
        scanf("%d%d", &d1, &d2);
        rules[d1][0]++;
        rules[d1][rules[d1][0]] = d2;
    }
    nums.push(n);
    while (!nums.empty())
    {
        int cur = nums.front();
        nums.pop();
        //cout<<cur<<endl;
        visited[cur] = true;
        ans++;
        int ds[5] = {0};
        int dpt = 0;
        while (cur != 0)
        {
            ds[dpt++] = cur % 10;
            cur /= 10;
        }
        int maxd = dpt;
        for (dpt=0; dpt<maxd; dpt++)
        {
            int d = ds[dpt];
            for (int i=1; i<=rules[d][0]; i++)
            {
                int base = 1;
                int nn = 0;
                for (int l=0; l<5; l++)
                {
                    if (l == dpt)
                        nn += rules[d][i] * base;
                    else nn += ds[l] * base;
                    base *= 10;
                }
                if (!visited[nn])
                {
                    nums.push(nn);
                    visited[nn] = true;
                }
                //cout<<"V"<<nn<<endl;
            }
        }
    }
    cout<<ans;
    //cin.get(),cin.get();
    return 0;
}
