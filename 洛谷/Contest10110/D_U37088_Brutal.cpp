#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
int powof10[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int main() {
    int n, m;
    long long ans = 0;
    cin>>n>>m;
    if (n <= 2) {
        cout<<0;
        return 0;
    }
    else for (int i=powof10[n-1]; i<powof10[n]; i++) {
        char buf[16];
        sprintf(buf, "%d", i);
        int c = 0;
        for (int j=0; j<n; j++) {
            if (buf[j] == '6' || buf[j] == '9') {
                c++;
            }
        }
        if (c < m) continue;
        bool flag = false;
        for (int j=0; j<=n-3; j++) {
            int s = buf[j] - '0' + buf[j+2] - '0' + buf[j+1] - '0';
            if (s == 6 || s == 9) {
                flag  = true;
            }
            else if (buf[j+2] > '6' && ((buf[j] - '0') * (int)(buf[j] - '0') + (buf[j+1] - '0') * (int)(buf[j+1] - '0')) % (buf[j+2] - '0') == 6) {
                flag = true;
            }
        }
        if (flag) {
            ans++;
        }
    }
    cout<<ans;
    //cin.get(), cin.get();
    return 0;
}
