#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

short fi[152][152] = {0};

inline void rotate_90(int& dx, int& dy) {
    // res: -i dx + dy
    int odx = dx, ody = dy;
    dx = ody; dy = -odx;
}

int main() {
    int n;
    cin >> n;
    
    int dix = 1; int diy = 0;
    int cx = 0; int cy = 0;
    for (int i = 0; i < n * n; i++) {
        fi[cx][cy] = i + 1;
        if (cx + dix >= n || cx + dix < 0
            || cy - diy >= n || cy - diy < 0
            || fi[cx + dix][cy - diy] > 0) rotate_90(dix, diy);
        cx += dix; cy -= diy;
        // cout << cx << ' ' << cy << endl;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << fi[j][i];
        }
        cout << endl;
    }
    return 0;
}
