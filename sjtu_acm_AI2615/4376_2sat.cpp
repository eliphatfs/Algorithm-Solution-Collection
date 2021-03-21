#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 2000001;
static int n, m;
static vector<int> edges[N];  // 2k: xk = 0, 2k + 1: xk = 1
static vector<int> redges[N];

static bool visit[N];
static bool rvisit[N];

static vector<int> postorder;

static vector<int> active_block;
static bool block_book[N];

void rexplore(register int cur) {
    rvisit[cur] = true;
    register unsigned S = redges[cur].size();
    for (register unsigned i = 0; i < S; i++) {
        if (!rvisit[redges[cur][i]]) rexplore(redges[cur][i]);
    }
    postorder.push_back(cur);
}

queue<int> Q;
inline void bfs(int s) {
    Q.push(s);
    while (!Q.empty()) {
        register int cur = Q.front();
        Q.pop();
        visit[cur] = true;
        active_block.push_back(cur);
        block_book[cur] = true;
        for (register unsigned i = 0; i < edges[cur].size(); i++) {
            if (!visit[edges[cur][i]]) {
                Q.push(edges[cur][i]);
                visit[edges[cur][i]] = true;
            }
        }
    }
}

inline int read_int() {
    char ch;
    int x = 0;
    do {
        ch = getchar();
    } while (ch > '9' || ch < '0');
    while (ch <= '9' && ch >= '0') {
        x *= 10;
        x += ch - '0';
        ch = getchar();
    }
    return x;
}

int main() {
    // freopen("1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (register int _ = 0; _ < m; _++) {
        register int i = read_int();
        register short a = read_int();
        register int j = read_int();
        register short b = read_int();
        // i = a || j = b
        // i = !a -> j = b
        // j = !b -> i = a
        --i; --j;
        edges[2 * i + (!a)].push_back(2 * j + b);
        edges[2 * j + (!b)].push_back(2 * i + a);
        redges[2 * j + b].push_back(2 * i + (!a));
        redges[2 * i + a].push_back(2 * j + (!b));
    }
    
    bool sat = true;
    for (register int node = 0; node < 2 * n; node++) if (!rvisit[node]) rexplore(node);
    for (register int j = postorder.size() - 1; j >= 0; j--) {
        if (!sat) break;
        if (!visit[postorder[j]]) {
            bfs(postorder[j]);
            for (register unsigned i = 0; i < active_block.size(); i++) {
                register int variable = active_block[i] / 2;
                if (block_book[2 * variable] && block_book[2 * variable + 1]) { sat = false; break; }
                block_book[active_block[i]] = false;
            }
            active_block.clear();
        }
    }
    printf(sat ? "Yes" : "No");
    return 0;
}
