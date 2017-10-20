#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct edge
{
    int to;
    int w;
};

queue<int> bfq;
vector<edge> edges[10086];
long long dis[10086]= {0};
int book[10086] = {0};

void bfs()
{
    while (!bfq.empty())
    {
        int cur = bfq.front();
        bfq.pop();
        book[cur] = 0;
        for (int i=0; i<edges[cur].size(); ++i)
        {
            edge * e = &edges[cur][i];
            if (dis[e->to] > dis[cur] + e->w)
            {
                dis[e->to] = dis[cur] + e->w;
                if (!book[e->to])
                {
                    book[e->to] = 1;
                    bfq.push(e->to);
                }
            }
        }
    }
}
 
int main()
{
    int n, m, s;
    cin>>n>>m>>s;
    for (int i=0; i<m; i++)
    {
        int f;
        edge e;
        scanf("%d%d%d", &f, &e.to, &e.w);
        edges[f].push_back(e);
    }
    for (int i=1; i<=n; i++)
    {
        dis[i] = 2147483647;
    }
    dis[s] = 0;
    bfq.push(s);
    book[s] = 1;
    bfs();
    for (int i=1; i<=n; i++)
    {
        printf("%d ", dis[i]);
    }
    return 0;
}
