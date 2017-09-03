#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int c=1;
    int * data = new int[n];
    for (int i=0; i<n; i++)
        scanf("%d", &data[i]);
    int sum=0;
    for (int i=0; i<n; i++)
    {
        sum+=data[i];
        if (sum > m)
        {
            sum=0;
            c++;
            i--;
        }
    }
    cout<<c;
    //getchar();getchar();
    return 0;
}
