#include <iostream>
#include <string>
using namespace std;

int f[100007];
int find(int a) {
    if (a == f[a]) return a;
    return f[a] = find(f[a]);
}
bool unio(int a, int b) {
    int ancest_a = find(a);
    int ancest_b = find(b);
    if (ancest_a == ancest_b) return false;
    f[ancest_b] = ancest_a;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) f[i] = i;
    string ans = "No";
    for (int i = 0; i < m; i++) {
        int s, e;
        scanf("%d%d", &s, &e);
        if (!unio(s - 1, e - 1)) { ans = "Yes"; break; }
    }
    cout << ans;
    return 0;
}
