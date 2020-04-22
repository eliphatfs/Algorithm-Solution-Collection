#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main() {
    int n;
    cin >> n;
    int * child_count = new int[n];
    memset(child_count, 0, sizeof(int) * n);
    int * node_id = new int[n];
    memset(node_id, 0, sizeof(int) * n);
    node_id[0] = 1;
    for (int i = 1; i < n; i++) {
        int fa;
        scanf("%d", &fa);
        if (child_count[fa] == 0) node_id[i] = node_id[fa] * 2;
        else node_id[i] = node_id[fa] * 2 + 1;
        child_count[fa]++;
    }
    delete child_count;
    bool * id_exist = new bool[n + 1];
    for (int i = 0; i <= n; i++) id_exist[i] = false;
    const char * result = "true";
    for (int i = 0; i < n; i++)
        if (node_id[i] > n) { result = "false"; break; }
        else id_exist[node_id[i]] = true;
    delete node_id;
    for (int i = 1; i <= n; i++)
        if (!id_exist[i]) { result = "false"; break; }
    cout << result;
    delete id_exist;
    return 0;
}
