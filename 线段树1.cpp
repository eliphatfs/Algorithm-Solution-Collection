#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
struct node {
    ll l, r; //[l, r]
    ll data;
    ll modify;
};
node tree[400007];
ll init[100007];
int n, m;

void build(int id, int l, int r)
{
    node& t = tree[id];
    t.l = l;
    t.r = r;
    t.modify = 0;
    if (l == r)
        t.data = init[l];
    else
    {
        int m = (l + r) >> 1;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        t.data = tree[id * 2].data + tree[id * 2 + 1].data;
    }
}

void findadd(int id, ll l, ll r, ll k)
{
    if (tree[id].l > r || tree[id].r < l)
        return;
    if (tree[id].l >= l && tree[id].r <= r)
    {
        tree[id].modify += k;
    }
    else
    {
        findadd(id * 2, l, r, k);
        findadd(id * 2 + 1, l, r, k);
        tree[id].data += k * (min(tree[id].r, r) - max(tree[id].l, l) + 1);
    }
}

void add(ll l, ll r, ll k)
{
    findadd(1, l, r, k);
}

ll findsum(int id, ll l, ll r)
{
    if (tree[id].l > r || tree[id].r < l)
        return 0;
    if (tree[id].l >= l && tree[id].r <= r)
        return tree[id].data + tree[id].modify * (tree[id].r - tree[id].l + 1);
    else
    {
        tree[id * 2].modify += tree[id].modify;
        tree[id * 2 + 1].modify += tree[id].modify;
        tree[id].data += tree[id].modify * (tree[id].r - tree[id].l + 1);
        tree[id].modify = 0;
        return findsum(id * 2, l, r) + findsum(id * 2 + 1, l, r);
    }
}

ll getsum(ll l, ll r)
{
    return findsum(1, l, r);
}

int main()
{
    cin>>n>>m;
    ll op, o1, o2, o3;
    for (int i=1; i<=n; i++)
        scanf("%lld", &init[i]);
    build(1, 1, n);
    //for (int i=1; i<n * 2; i++)
    //    printf("[%d,%d]:%lld ", tree[i].l, tree[i].r, tree[i].data);
    //printf("\n");
    for (int i=0; i<m; i++)
    {
        scanf("%lld", &op);
        if (op == 1)
        {
            scanf("%lld%lld%lld", &o1, &o2, &o3);
            add(o1, o2, o3);
            /*for (int i=1; i<n * 2; i++)
                printf("[%d,%d]:%lld %lld", tree[i].l, tree[i].r, tree[i].data, tree[i].modify);
            printf("\n");*/
        }
        else
        {
            scanf("%lld%lld", &o1, &o2);
            printf("%lld\n", getsum(o1, o2));
        }
    }
    return 0;
}
