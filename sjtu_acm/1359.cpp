#include <iostream>
#include <cstring>
using namespace std;

char buffer[1536];

unsigned map_value(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 1 - 'A';
    if (ch >= 'a' && ch <= 'z') return ch + 27 - 'a';
    return 0u;
}

int main() {
    unsigned long long ans = 0;
    cin.getline(buffer, 1535, '\n');
    unsigned slen = strlen(buffer);
    
    for (unsigned i = 0; i < slen; i++)
        ans += (i + 1) * map_value(buffer[i]);
    
    cout << ans;
    // cin.get(), cin.get();
    return 0;
}
