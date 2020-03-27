#include <iostream>
#include <cstdio>
using namespace std;

char staku[1000007] = {0};
int spt = 0;
int n;

int LR[1000007] = {0};
int backsteps[1000007] = {0};
int stepn = 0;
int lrpt = 0;

void push_staku(char ch) {
    staku[spt++] = ch;
    
    if (ch == '{') { LR[++lrpt] = 1; backsteps[stepn++] = -1; }
    else if (ch == '[') { LR[++lrpt] = 2; backsteps[stepn++] = -1; }
    else if (ch == '(') { LR[++lrpt] = 3; backsteps[stepn++] = -1; }
    else if (ch == '}' && LR[lrpt] == 1) { --lrpt; backsteps[stepn++] = 1; }
    else if (ch == ']' && LR[lrpt] == 2) { --lrpt; backsteps[stepn++] = 2; }
    else if (ch == ')' && LR[lrpt] == 3) { --lrpt; backsteps[stepn++] = 3; }
    else { LR[++lrpt] = 4; backsteps[stepn++] = -1; }
}

void pop_staku() {
    if (spt > 0) spt--;
    if (stepn > 0) {
        --stepn;
        if (backsteps[stepn] < 0) --lrpt;
        else LR[++lrpt] = backsteps[stepn];
    }
}
void staku_top() {
    if (spt > 0) printf("%c\n", staku[spt - 1]);
}

void staku_matches() {
    printf(LR[lrpt] == 0 ? "YES\n" : "NO\n");
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op;
        char buf[4];
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", buf);
            push_staku(buf[0]);
        }
        else if (op == 2) pop_staku();
        else if (op == 3) staku_top();
        else staku_matches();
    }
    return 0;
}
