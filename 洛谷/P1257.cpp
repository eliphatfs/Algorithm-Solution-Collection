#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int x[10002];
int y[10002];

int main()
{
    int n;
    cin>>n;
    register int tmpx, tmpy;
    register long long tmpz;
    for (int i=0; i<n; i++)
        scanf("%d%d", &x[i], &y[i]);
    
    long long mindis2 = 4294967296ll;
    
    for (int i=0; i<n; i++)
        for (int j=i+1; j<n; j++)
        {
            tmpx = x[i] - x[j];
            tmpy = y[i] - y[j];
            tmpz = (long long)tmpx * tmpx + (long long)tmpy * tmpy;
            mindis2 = mindis2 < tmpz ? mindis2 : tmpz;
        }
    printf("%.4f", sqrt(mindis2));
    //getchar();getchar();
    return 0;
}
