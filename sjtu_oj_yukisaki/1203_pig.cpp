#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
const int INF = 1073741824;

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

void read_inputs() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        int n_pigs; cin >> n_pigs;
        flow_edges[1205].push_back(flow_edge_t(i + n, 0, n_pigs));
    }
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int j = 0; j < a; j++) {
            int key; scanf("%d", &key); --key;
            for (auto e : flow_edges[key + n]) {
                flow_edges[e.to].push_back(flow_edge_t(i, 0, INF));
            }
            flow_edges[key + n].push_back(flow_edge_t(i, 0, INF));
        }
        int b; cin >> b;
        flow_edges[i].push_back(flow_edge_t(1206, 0, b));
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
                    for (auto& e : flow_edges[pre[p]])
                        if (e.to == p)
                            btnk = min(btnk, e.c - e.w);
                    for (auto& e : flow_edges[p])
                        if (e.to == pre[p])
                            btnk = min(btnk, e.w);
                    p = pre[p];
                }
                p = cur;
                while (p != 1205) {
                    for (auto& e : flow_edges[pre[p]])
                        if (e.to == p)
                            e.w += btnk;
                    for (auto& e : flow_edges[p])
                        if (e.to == pre[p])
                            e.w -= btnk;
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
