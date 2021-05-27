#include <iostream>
#include <array>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
array<set<int>, 205> origin_edges;
array<int, 205> gender_cluster;  // 0: UNINIT 1: A 2: B

void read_inputs() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        origin_edges[s].insert(e);
        origin_edges[e].insert(s);
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

}

void recreate_ext_graph() {
}

void max_flow() {

}

int rand_round() {
    int ans = n;
    auto run_edges = origin_edges;
    for (int i = 0; i < n; i++) {
        int maxd = 0;
        int maxj = -1;
        int curcount = 1;
        for (int j = 0; j < n; j++) {
            if (run_edges[j].size() > maxd) {
                maxd = run_edges[j].size();
                maxj = j;
                curcount = 1;
            }
            else if (run_edges[j].size() == maxd) {
                if (rand() % (curcount + 1) == 0)
                    maxj = j;
            }
        }
        if (maxd == 0) break;
        for (auto ed : run_edges[maxj]) {
            run_edges[ed].erase(maxj);
        }
        run_edges[maxj].clear();
        ans--;
    }
    return ans;
}

int main() {
    read_inputs();
    int attempt = 0;
    for (int i = 0; i < 60 * n; i++) {
        attempt = max(attempt, rand_round());
    }
    cout << attempt << endl;
    // cluster_gender();
    return 0;
}
