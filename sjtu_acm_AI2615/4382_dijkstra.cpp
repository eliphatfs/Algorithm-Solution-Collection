#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<pair<int, int> > G[100007];
bool visited[100007] = {};
int main() {
    int s, t, n, m;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        G[x].push_back(make_pair(z, y));
        G[y].push_back(make_pair(z, x));
    }
    set<pair<int, int> > Q;
    Q.insert(make_pair(0, s));
    while (Q.size() > 0) {
        pair<int, int> cur = *Q.begin();
        Q.erase(cur);
        
        int v = cur.second;
        int L = cur.first;
        
        if (visited[v]) continue;
        visited[v] = true;
        if (v == t) { cout << L; break; }
        
        for (auto next : G[v]) {
            int nv = next.second;
            int nL = L + next.first;
            Q.insert(make_pair(nL, nv));
        }
    }
    return 0;
}
