#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
const int INF = 536870912;

struct flow_edge_t {
    int to;
    int w;
    int c;

    flow_edge_t(int _e, int _w, int _c) {
        to = _e; w = _w; c = _c;
    }
};

// [0, n): customers 1205: source 1206: sink others: pigs
array<vector<flow_edge_t>, 1207> flow_edges;
array<vector<int>, 1207> ext_edges;

inline int coo2id(int x, int y) {
    return x * 37 + y;
}

void read_inputs() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int b; cin >> b;
            if (b == 1) flow_edges[1205].push_back(flow_edge_t(coo2id(i, j), 0, INF));
            else if (b == 2) flow_edges[coo2id(i, j)].push_back(flow_edge_t(1206, 0, INF));
            for (int dx : {-1, 1}) {
                flow_edges[coo2id(i, j)].push_back(flow_edge_t(coo2id(i + dx, j), 0, 1));
                flow_edges[coo2id(i, j)].push_back(flow_edge_t(coo2id(i, j + dx), 0, 1));
            }
        }
    }
}

void recreate_ext_graph() {
    for (int i = 0; i < 1207; i++) ext_edges[i].clear();
    for (int i = 0; i < 1207; i++) {
        for (auto e : flow_edges[i]) {
            if (e.w < e.c) ext_edges[i].push_back(e.to);
            if (e.w > 0) ext_edges[e.to].push_back(i);
        }
    }
}

int max_flow() {
    bool flag = true;
    while (flag) {
        flag = false;
        recreate_ext_graph();
        queue<int> bfq; bfq.push(1205);
        array<int, 1207> pre; pre.fill(-1);
        while (!bfq.empty()) {
            int cur = bfq.front(); bfq.pop();
            if (cur == 1206) {
                int btnk = INF;
                int p = cur;
                while (p != 1205) {
                    int tw = 0;
                    for (auto& e : flow_edges[pre[p]])
                        if (e.to == p) tw += e.c - e.w;
                    for (auto& e : flow_edges[p])
                        if (e.to == pre[p]) tw += e.w;
                    btnk = min(btnk, tw);
                    p = pre[p];
                }
                p = cur;
                while (p != 1205) {
                    int tw = btnk;
                    for (auto& e : flow_edges[pre[p]])
                        if (e.to == p) {
                            int f = min(e.c - e.w, tw);
                            e.w += f;
                            tw -= f;
                        }
                    for (auto& e : flow_edges[p])
                        if (e.to == pre[p])
                            e.w -= tw;
                    p = pre[p];
                }
                flag = true; break;
            }
            for (auto to : ext_edges[cur]) {
                if (pre[to] != -1) continue;
                bfq.push(to); pre[to] = cur;
            }
        }
    }
    int mf = 0;
    for (auto e : flow_edges[1205]) mf += e.w;
    return mf;
}

int main() {
    read_inputs();
    cout << max_flow() << endl;
    return 0;
}
