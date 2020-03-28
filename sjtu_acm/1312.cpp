#include <iostream>
using namespace std;

const char * outp[] = { "Yeah!\n", "5555\n" };

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        if (k == 1) cout << outp[n % 2];
        else cout << outp[n <= k];
    }
    return 0;
}
