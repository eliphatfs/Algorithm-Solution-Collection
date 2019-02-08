#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

char m[501][501];

int main()
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        scanf("%s", m[i]);
    }
    long long ans = 0;
    for (int i=1; i<n-1; i++)
    {
        for (int j=1; j<n-1; j++)
        {
            if (m[i][j] != 'X') continue;
            if (m[i - 1][j - 1] != 'X') continue;
            if (m[i + 1][j + 1] != 'X') continue;
            if (m[i + 1][j - 1] != 'X') continue;
            if (m[i - 1][j + 1] != 'X') continue;
            ++ans;
        }
    }
    cout << ans;
    // cin.get(), cin.get();
    return 0;
}
