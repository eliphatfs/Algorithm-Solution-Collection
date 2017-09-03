#include <iostream>
using namespace std;

int tmp[21] = {0, 1, 2};

int kind(int t)
{
    if (tmp[t] != 0) return tmp[t];
    return (tmp[t] = kind(t - 1) + kind(t - 2));
}

int main()
{
    int n;
    cin>>n;
    cout<<kind(n);
    return 0;
}
