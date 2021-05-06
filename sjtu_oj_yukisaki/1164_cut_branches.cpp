#include <iostream>
#include <memory>
#include <algorithm>
#include <array>
using namespace std;

int n, m;

struct node_t {
    shared_ptr<node_t> left, right;
    int weight;
    int block_max_withbr[207];
    bool connected_root;
    node_t(int w) {
        weight = w;
        for (int i = 0; i <= m; i++) block_max_withbr[i] = 0;
        left = nullptr;
        right = nullptr;
        connected_root = false;
    }
    void DP() {
        if (left) left->DP();
        if (right) right->DP();
        for (int i = 0; i <= m; i++) {
            int ans = weight;
            if (i >= 1 && left) ans = max(ans, weight + left->block_max_withbr[i - 1]);
            if (i >= 1 && right) ans = max(ans, weight + right->block_max_withbr[i - 1]);
            for (int j = 0; left && right && j <= i - 2; j++)
                ans = max(ans, weight + left->block_max_withbr[j] + right->block_max_withbr[i - 2 - j]);
            block_max_withbr[i] = ans;
        }
    }
};

array<shared_ptr<node_t>, 207> nodes_init;

int main() {
    cin >> n >> m;
    nodes_init[1] = make_shared<node_t>(0);
    nodes_init[1]->connected_root = true;
    for (int i = 2; i <= n; i++) {
        int w; cin >> w;
        nodes_init[i] = make_shared<node_t>(w);
    }
    for (int i = 0; i < n - 1; i++) {
        int s, e; cin >> s >> e;
        if (nodes_init[e]->connected_root)
            swap(s, e);
        if (!nodes_init[s]->left) nodes_init[s]->left = nodes_init[e];
        else if (!nodes_init[s]->right) nodes_init[s]->right = nodes_init[e];
        nodes_init[e]->connected_root = true;
    }
    nodes_init[1]->DP();
    cout << nodes_init[1]->block_max_withbr[m];
    return 0;
}
