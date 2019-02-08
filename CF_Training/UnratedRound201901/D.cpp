#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<int> edges[100007];
int vis[100007] = {0};
queue<int> road;
set<int> linked;

void bfs()
{
    linked.insert(1);
    while (linked.size() > 0)
    {
        int cur = *linked.begin();
        road.push(cur);
        linked.erase(cur);
        vis[cur] = 1;
        for (int i=0; i<edges[cur].size(); i++)
        {
            int end = edges[cur][i];
            if (!vis[end])
                linked.insert(end);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<m; i++)
    {
        int s, e;
        scanf("%d%d", &s, &e);
        edges[s].push_back(e);
        edges[e].push_back(s);
    }
    bfs();
    for (int i=1; i<=n; i++)
        printf("%d ", road.front()), road.pop();
    // cin.get(), cin.get();
    return 0;
}
