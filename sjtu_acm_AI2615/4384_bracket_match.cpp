#include <iostream>
#include <cmath>
#include <cstring>

inline bool matches(char a, char b) {
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

char cstr[201];
int memo[201][201];
// [s, e)
int max_match(int s, int e) {
    if (e - s <= 0) return 0;
    if (memo[s][e] >= 0) return memo[s][e];
    int ans = 0;
    if (matches(cstr[s], cstr[e]))
        ans = std::max(ans, 2 + max_match(s + 1, e - 1));
    for (int k = s + 1; k <= e - 1; k++)
        ans = std::max(ans, max_match(s, k) + max_match(k, e));
    return memo[s][e] = ans;
}

int main() {
    std::cin >> cstr;
    for (int i = 0; i < 201; i++)
        for (int j = 0; j < 201; j++)
            memo[i][j] = -1;
    std::cout << max_match(0, std::strlen(cstr));
    return 0;
}
