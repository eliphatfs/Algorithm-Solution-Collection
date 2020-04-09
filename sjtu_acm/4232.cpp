#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int INF = 987654321;

struct Node {
    Node * sonL, * sonR;
    int segL, segR;  // [L, R)
    int maxScore;
    void update(int target, int newVal) {
        if (target < segL || target >= segR) return;
        maxScore = newVal;
        if (sonL) { sonL->update(target, newVal); maxScore = max(maxScore, sonL->maxScore); }
        if (sonR) { sonR->update(target, newVal); maxScore = max(maxScore, sonR->maxScore); }
    }
    int query(int L, int R) {
        if (L <= segL && R >= segR) return maxScore;
        if (R <= segL || L >= segR) return -INF;
        int nowMax = -INF;
        if (sonL) nowMax = max(sonL->query(L, R), nowMax);
        if (sonR) nowMax = max(sonR->query(L, R), nowMax);
        return nowMax;
    }
    virtual ~Node() { if (sonL) delete sonL; if (sonR) delete sonR; }
};

Node * buildTree(int * scores, int segL, int segR) {
    Node * tr = new Node();
    tr->segL = segL;
    tr->segR = segR;
    if (segL >= segR - 1) {
        tr->sonL = tr->sonR = NULL;
        tr->maxScore = scores[segL];
        return tr;
    }
    int mid = (segL + segR) / 2;
    tr->sonL = buildTree(scores, segL, mid);
    tr->sonR = buildTree(scores, mid, segR);
    tr->maxScore = max(tr->sonL->maxScore, tr->sonR->maxScore);
    return tr;
}

int main() {
    int n, m;
    cin >> n >> m;
    int * scores = new int[n];
    for (int i = 0; i < n; i++) scanf("%d", &scores[i]);
    Node * tree = buildTree(scores, 0, n);
    delete scores;
    
    for (int i = 0; i < m; i++) {
        char kommand[3]; int X; int Y;
        scanf("%s%d%d", kommand, &X, &Y);
        if (kommand[0] == 'Q') printf("%d\n", tree->query(X - 1, Y));
        else tree->update(X - 1, Y);
    }
    
    delete tree;
    return 0;
}
