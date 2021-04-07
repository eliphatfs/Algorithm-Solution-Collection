#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int s; int e; int w;
    bool operator<(edge o) { return w < o.w; }
};

int f[200000];
int find_f(int a) {
    if (f[a] == a) return a;
    return f[a] = find_f(f[a]);
}

bool merge(int a, int b) {
    int fa = find_f(a), fb = find_f(b);
    if (fa == fb) return false;
    f[fb] = fa;
    return true;
}

int main() {
    int n, m;
    vector<edge> G;
    cin >> n >> m;
    for (int i = 0; i < n; i++) f[i] = i;
    for (int i = 0; i < m; i++) {
        edge e;
        scanf("%d%d%d", &e.s, &e.e, &e.w);
        --e.s; --e.e;
        G.push_back(e);
    }
    sort(G.begin(), G.end());
    long long ans = 0;
    for (int i = 0; i < m; i++)
        if (merge(G[i].s, G[i].e)) ans += G[i].w;
    cout << ans;
    return 0;
}
