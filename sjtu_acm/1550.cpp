#include <iostream>
using namespace std;
#define Max(x, y) (x > y ? x : y)
#define Min(x, y) (x < y ? x : y)

int water[1007];
int ground[1007] = {0};

int main() {
    int n;
    cin >> n;
    while (cin.get() != '[');
    for (int i = 1; i <= n; i++) { scanf("%d", &ground[i]); cin.get(); }
    for (int i = 0; i <= n + 1; i++) water[i] = 0;
    
    for (int i = 0; i <= n + 1; i++) {
        int rmax = 0;
        int lmax = 0;
        for (int j = i + 1; j <= n + 1; j++) {
            rmax = Max(rmax, ground[j]);
        }
        for (int j = 0; j < i; j++) {
            lmax = Max(lmax, ground[j]);
        }
        water[i] = Min(rmax, lmax);
    }
    
    long long ans = 0;
    for (int i = 0; i <= n + 1; i++) {
        if (water[i] > ground[i]) ans += water[i] - ground[i];
    }
    cout << ans;
    // cin.get(), cin.get(), cin.get();
    return 0;
}
