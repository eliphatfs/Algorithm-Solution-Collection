#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int maxf = (int)sqrt(n) + 1;
    for (int i=2; i<maxf; i++)
    {
        if (n % i == 0)
        {
            cout << (n / i);
            break;
        }
    }
    return 0;
}
