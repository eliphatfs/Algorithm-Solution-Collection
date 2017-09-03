#include <iostream>
#include <cstdio>
using namespace std;
//对于连续的自然数a..b 和为(a+b)*(b-a+1)/2
int sum(int a, int b)
{
    return (a+b)*(b-a+1)/2;
} 
int main()
{
    int m;
    cin>>m;
    int s;
    for (int i=0; i<m; i++)
        for (int j=i+1; j<m; j++)
        {
            s = sum(i, j);
            if(s == m)
                printf("%d %d\n", i, j);
            else if (s > m) break;
        }
    return 0;
}
