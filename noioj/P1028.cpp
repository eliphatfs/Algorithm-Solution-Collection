#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cin>>m>>n;
	while (m != n && m != 0 && n != 0)
	{
		if (m > n) m %= n;
		else n %= m;
	}
	if (m == 1 || n == 1) cout<<"Yes";
	else cout<<"No";
	return 0;
}