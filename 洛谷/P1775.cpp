#include <iostream>
using namespace std;
long long fib[16384] = {0};
int main()
{
    long long k;
    cin>>k;
    int i;
    fib[1] = fib[2] = 1;
    for (i=3; fib[i-1] < k; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout<<fib[i-2]<<" "<<fib[i-3];
    //cin.get();cin.get();
    return 0;
}
