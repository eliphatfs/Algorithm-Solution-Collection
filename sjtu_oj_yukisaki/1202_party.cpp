#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
array<vector<int>, 205> origin_edges;
array<int, 205> gender_cluster;  // 0: UNINIT 1: A 2: B

struct flow_edge_t {
    int to;
    int w;

    flow_edge_t(int _e, int _w) {
        to = _e; w = _w;
    }
};

// n: source, n + 1: sink, out: gender_cluster 1, in: .. 2
array<vector<flow_edge_t>, 205> flow_edges;
array<vector<int>, 205> ext_edges;

void read_inputs() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        origin_edges[s].push_back(e);
        origin_edges[e].push_back(s);
    }
}

void cluster_gender() {
    queue<int> bfq;
    for (int i = 0; i < n; i++) {
        if (gender_cluster[i]) continue;
        gender_cluster[i] = 1;
        bfq.push(i);
        while (!bfq.empty()) {
            auto cur = bfq.front(); bfq.pop();
            for (auto next : origin_edges[cur]) {
                if (gender_cluster[next]) continue;
                gender_cluster[next] = 3 - gender_cluster[cur];
                bfq.push(next);
            }
        }
    }
}

void convert_graph() {
    for (int i = 0; i < n; i++) {
        if (gender_cluster[i] == 1) flow_edges[n].push_back(flow_edge_t(i, 0));
        else flow_edges[i].push_back(flow_edge_t(n + 1, 0));
        for (auto j : origin_edges[i])
            if (gender_cluster[i] == 1)
                flow_edges[i].push_back(flow_edge_t(j, 0));
    }
}

void recreate_ext_graph() {
    for (int i = 0; i < n + 2; i++) ext_edges[i].clear();
    for (int i = 0; i < n + 2; i++) {
        for (auto e : flow_edges[i]) {
            if (e.w == 0) ext_edges[i].push_back(e.to);
            else ext_edges[e.to].push_back(i);
        }
    }
}

int max_flow() {
    bool flag = true;
    while (flag) {
        flag = false;
        recreate_ext_graph();
        queue<int> bfq; bfq.push(n);
        array<int, 205> pre; pre.fill(-1);
        while (!bfq.empty()) {
            int cur = bfq.front(); bfq.pop();
            if (cur == n + 1) {
                int p = cur;
                while (p != n) {
                    for (auto& e : flow_edges[pre[p]])
                        if (e.to == p)
                            e.w = !e.w;
                    for (auto& e : flow_edges[p])
                        if (e.to == pre[p])
                            e.w = !e.w;
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
    for (auto e : flow_edges[n]) mf += e.w;
    return mf;
}

int main() {
    read_inputs();
    cluster_gender();
    convert_graph();
    cout << n - max_flow() << endl;
    return 0;
}
