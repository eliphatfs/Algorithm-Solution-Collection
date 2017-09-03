#include <iostream>
using namespace std;

int main()
{
    register long long a, b, m;
    cin>>a>>b;
    m = b % a;
    /* // 60·Ö 
    for (long long x=0;; x++)
        if ((a * x) % b == 1)
        {
            cout<<x;
            break;
        }
    */
    /* // 60·Ö 
    for (register long long i=1;; i++)
        if ((i * b + 1) % a == 0)
        {
            cout<<(i * b + 1) / a;
            break;
        }
    */
    /* //70·Ö
    for (register long long i=1;; i++)
        if ((a * i - 1) % m == 0)
        {
            cout<<((b * ((a * i - 1) / m) + 1) / a);
            break;
        }
    */
    //getchar(); getchar();
    return 0;
}
