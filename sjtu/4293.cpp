#include <iostream>
using namespace std;
 
int d[107][107] = {0};
int n, m;
 
int judge(int x, int y) {
    int cri = d[x][y];
    for (int k = 0; k < n; k++)
        if (d[k][y] >= cri && k != x)
            return 0;
    for (int k = 0; k < m; k++)
        if (d[x][k] <= cri && k != y)
            return 0;
    return 1;
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> d[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (judge(i, j)) {
                cout << i + 1 << " " << j + 1 << endl << d[i][j];
                return 0;
            }
    cout << "No saddle point!";
    return 0;
}
