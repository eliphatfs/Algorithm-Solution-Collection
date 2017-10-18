#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll c(ll n, ll m)
{
	if (n == m) return 1;
	else return c(n - 1, m) * n / (n - m);
}
int main()
{
	int ni, mi;
	cin>>ni>>mi;
	cout<<c(ni + mi - 1, mi - 1);
	return 0;
}
