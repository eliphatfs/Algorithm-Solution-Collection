#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct node {
    node * L;
    node * R;
    int D;
};

int k;
int pre[150007];
int mid[150007];
int post[150007];
int mid_r[150007];
int post_r[150007];

node * make_node() {
    node * n = new node;
    n->L = n->R = NULL;
    return n;
}

node * Q[150007];
int qh = 0, qt = 0;

void walk(node * n) {
    qh = qt = 0;
    Q[qt++] = n;
    while (qh != qt) {
        node * kn = Q[qh++];
        printf("%d ", kn->D);
        if (kn->L) Q[qt++] = kn->L;
        if (kn->R) Q[qt++] = kn->R;
    }
}

int gen(node * n, int cur, int L, int R) {
    int d = pre[cur];
    n->D = d;
    if (mid_r[d] > L && mid_r[d] < R) {
        n->L = make_node();
        cur = gen(n->L, cur + 1, L, mid_r[d]);
    }
    if (mid_r[d] >= L && mid_r[d] < R - 1) {
        n->R = make_node();
        cur = gen(n->R, cur + 1, mid_r[d] + 1, R);
    }
    return cur;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < k; i++) scanf("%d", &mid[i]);
    for (int i = 0; i < k; i++) scanf("%d", &post[i]);
    for (int i = 0; i < k; i++) mid_r[mid[i]] = i;
    for (int i = 0; i < k; i++) post_r[post[i]] = i;
    int cur = 0;
    while (cur < k) {
        node * n = make_node();
        int end = post_r[pre[cur]];
        cur = gen(n, cur, cur, end + 1) + 1;
        walk(n);
    }
    return 0;
}
