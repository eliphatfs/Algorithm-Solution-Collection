#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> nm[10][10];
ll d[51][51][10][10] = {0};
ll f(int i, int j, int d1, int d2) {
    if (i < 3 || j < 0) return 0;
    if (j > i) return 0;
    if (d[i][j][d1][d2] != -1) return d[i][j][d1][d2];
    int res = 0;
    if (d2 == 6 || d2 == 9) {
        for (int k=0; k<9; k++) {
            res += f(i, j - 1, k, d1);
        }
        res *= 2;
    }
    for (int dl=0; dl<10; dl++) {
        for (int k=0; k<nm[dl][d1].size(); k++) {
            if (nm[dl][d1][k] == d2) {
            }
        }
    }
    d[i][j][d1][d2] = res;
    return res;
}
int main() {
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (i + j <= 6) nm[i][j].push_back(6 - i - j);
            if (i + j <= 9) nm[i][j].push_back(9 - i - j);
        }
    }
    for (int i=0; i<10; i++) { 
        for (int j=0; j<10; j++)
        {
            if ((i * i + j * j) % 7 == 6)
                nm[i][j].push_back(7);
        }
    }
    for (int i=0; i<51; i++)
    for (int j=0; j<51; j++)
    for (int k=0; j<10; k++)
    for (int l=0; l<10; l++)
        d[i][j][k][l] = -1;
    for (int j=0; j<51; j++)
    for (int k=0; j<10; k++)
    for (int l=0; l<10; l++)
        d[3][j][k][l] = 0;
    
    for (int d1=1; d1<10; d1++)
    for (int d2=0; d2<10; d2++)
    for (int d3=0; d3<10; d3++) {
        bool flag = false;
        for (int i=0; i<nm[d1][d2].size(); i++)
        {
            if (nm[d1][d2][i] == d3) {
                flag = true;
            }
        }
        if (!flag) continue;
        int c1 = 0;
        if (d1 == 6 || d1 == 9)
            c1++;
        if (d2 == 6 || d2 == 9)
            c1++;
        if (d3 == 6 || d3 == 9)
            c1++;
        d[3][c1][d2][d3]++;
    }
    
    int n, m;
    cin>>n>>m;
    ll ans = 0;
    for (int j=m; j<51; j++)
    for (int k=0; j<10; k++)
    for (int l=0; l<10; l++)
        ans += f(n, j, k, l);
    cout<<ans;
    // 237 247 357 397 457 497
}
