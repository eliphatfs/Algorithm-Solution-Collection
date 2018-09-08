#include <iostream>
#include <cstdio>
using namespace std;
typedef __int128 ll;
ll pmod(ll a, ll b, ll mode);
long long solve() {
    int n;
    scanf("%d", &n);
    int k = (n + 1) / 2;
    ll mod25 = 25ll * 1000000007ll;
    ll x = pmod(26, k - 1, 25ll * mod25);
    ll part1;
    if (x == 0) part1 = mod25 - 1;
    else part1 = (x - 1ll) / 25ll;
    ll contrib1 = (part1 * 2ll * 26ll * 26ll);
    ll contrib2 = (pmod(26, k + 1, mod25) * (2 * k - 1));
    ll contriball = contrib2 - 26 - contrib1;
    if (contriball < 0)
        contriball += mod25 * (-contriball / mod25 + 50ll);
    return (long long)((contriball % mod25) / 25);
}


ll pmod(ll a, ll b, ll mode)
{
	ll sum = 1;
	a = a % mode;
	while (b > 0) {
		if (b % 2 == 1)
			sum = (sum * a) % mode;
		b /= 2;
		a = (a * a) % mode;
	}
	return sum;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) printf("%lld\n", solve());
}
