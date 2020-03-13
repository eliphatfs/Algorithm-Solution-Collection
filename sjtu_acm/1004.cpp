#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int m, t, u, f, d;
    cin >> m >> t >> u >> f >> d;
    
    int ftime = 2 * f;
    int udtime = u + d;
    
    int ans = 0;
    int ti = 0;
    for (int i = 0; i < t; i++) {
        char rd;
        cin >> rd;
        if (rd == 'f') ti += ftime; else ti += udtime;
        if (ti > m) break;
        ++ans;
    }
    cout << ans << endl;
    // cin.get(), cin.get();
    return 0;
}
