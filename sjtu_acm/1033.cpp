#include <iostream>
using namespace std;
typedef long long ll;

struct token {
    char type;
    ll tag;
    token() { type = 0; tag = 0; }
    token(char t, ll g) { type = t; tag = g; }
    bool operator==(token p) { return type == p.type && tag == p.tag; }
    bool operator!=(token p) { return !(*this == p); }
};

token processed[1007];
int ntoken = 0;
int tpt = 0;

ll atom();
ll pow_term();
ll muldiv_term();
ll expr();

ll atom() {
    if (processed[tpt] == token('c', '(')) {
        tpt++;
        ll val = expr();
        if (processed[tpt++] != token('c', ')')) throw 1;
        return val;
    }
    else if (processed[tpt].type == 'i') {
        return processed[tpt++].tag;
    }
    else if (processed[tpt] == token('c', '-')) {
        tpt++;
        return -atom();
    }
    throw 2;
}

ll pow_term() {
    ll base = atom();
    ll val = 1;
    if (processed[tpt] == token('c', '^')) {
        tpt++;
        ll po = pow_term();
        if (base == 1 || base == 0) return base;
        if (base == -1) return po % 2 == 0 ? 1 : -1;
        if (po > 64) po = 64;
        for (int i = 0; i < po; i++) val *= base;
    }
    else val = base;
    return val;
}

ll muldiv_term() {
    ll val = pow_term();
    while (processed[tpt] == token('c', '*') || processed[tpt] == token('c', '/')) {
        token t = processed[tpt];
        tpt++;
        ll opr2 = pow_term();
        if (t == token('c', '*')) val *= opr2;
        else if (opr2 == 0) throw 1025; else val /= opr2;
    }
    return val;
}

ll expr() {
    ll val = muldiv_term();
    while (processed[tpt] == token('c', '+') || processed[tpt] == token('c', '-')) {
        token t = processed[tpt];
        tpt++;
        ll opr2 = muldiv_term();
        if (t == token('c', '+')) val += opr2;
        else val -= opr2;
    }
    return val;
}

int main() {
    while (!cin.eof()) {
        while (cin.peek() == ' ' || cin.peek() == '\n' || cin.peek() == '\r') { cin.get(); if (cin.eof()) break; }
        if (!cin.peek()) break;
        if (cin.eof()) break;
        if (cin.peek() >= '0' && cin.peek() <= '9') {
            long long x; cin >> x;
            processed[ntoken++] = token('i', x);
        }
        else processed[ntoken++] = token('c', cin.get());
    }
    try {
        ll x = expr();
        if (tpt != ntoken) throw -1;
        cout << x;
    }
    catch (int v) {
        cout << "Error";
    }
    return 0;
}
