#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
int n, m, b, e;
struct ed {
    int s, t, w;
};
struct mv {
    ll ai, x;
    bool operator<(mv oth) const {
        if (ai < oth.ai) return true;
        else return false;
    }
};
vector<ed> eds[100007]; // eds[start]: ed
ll mind[100007];
bool book[100007] = {false};
void spfa() {
    queue<int> bfq;
    for (int i=0; i<=n; i++) {
        mind[i] = 473982734732987478ll;
    }
    mind[b] = 0;
    bfq.push(b);
    while (!bfq.empty()) {
        int cur = bfq.front();
        bfq.pop();
        book[cur] = false;
        for (int i=0; i<eds[cur].size(); i++) {
            ed cedge = eds[cur][i];
            if (mind[cedge.t] > mind[cedge.s] + cedge.w) {
                mind[cedge.t] = mind[cedge.s] + cedge.w;
                // cout<<cedge.t<<" "<<cedge.s<<" "<<cedge.w<<" "<<mind[cedge.t]<< "; ";
                if (!book[cedge.t]) {
                    book[cedge.t] = true;
                    bfq.push(cedge.t);
                }
            }
        }
    }
}

mv mvs[100007];

int main() {
    cin >> n >> m >> b >> e;
    for (int i=0; i<m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ed nedge;
        nedge.s = x; nedge.t = y; nedge.w = z;
        eds[x].push_back(nedge);
        nedge.s = y; nedge.t = x; nedge.w = z;
        eds[y].push_back(nedge);
    }
    spfa();
    int t;
    cin >> t;
    ll mint = 473982734732987478ll;
    for (int i=0; i<t; i++) {
        scanf("%lld%lld", &mvs[i].ai, &mvs[i].x);
    }
    sort(mvs, mvs + t);
    mvs[t].ai = 473982734732987470ll;
    int lastplace = e;
    ll lasttime = 0;
    if (mind[e] < mvs[0].ai) {
        mint = mind[e];
    }
    for (int i=0; i<t; i++) {
        if (mind[mvs[i].x] < mvs[i + 1].ai) {
            mint = min(mint, max((ll)mvs[i].ai, mind[mvs[i].x]));
        }
        lastplace = mvs[i].x;
        lasttime = mvs[i].ai;
    }
    if (max(mind[lastplace], lasttime) < mint) {
        mint = max(mind[lastplace], lasttime);
    }
    printf("%lld", mint);
    // cin.get(), cin.get(); 
    return 0;
}
