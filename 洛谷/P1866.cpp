#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long * max = new long long[n];
    for (int i=0; i<n; i++)
        cin>>max[i];
    sort(max, max+n);
    long long mul = 1;
    for (int i=0; i<n; i++)
    {
        max[i] -= i;
        mul *= max[i];
        mul %= 1000000007ll;
    }
    cout<<mul;
    return 0;
}
