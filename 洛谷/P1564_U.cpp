#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int * whose = new int[n];
    for (int i=0; i<n; i++)
        scanf("%d", &whose[i]);
    int count = 1;
    int c[3] = {0, 0, 0};
    int delta = 0;
    for (int i=0; i<n; i++)
    {
        c[whose[i]]++;
        delta = abs(c[1] - c[2]);
        if (delta > m)
        {
            count++;
            i--;
            c[1] = c[2] = 0;
        }
    }
    cout << count;
    getchar(); getchar();
    return 0;
} 
