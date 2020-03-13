#include <iostream>
#include <cstring>
using namespace std;

char cipher[107];
char plaintext[107];
char cbuffer[107];

bool attempt_a(int n, int a) {
    for (int i = 0; i < n; i++) {
        cbuffer[i] = plaintext[(i % (n / a)) * a + i / (n / a)];
    }
    cbuffer[n] = '\0';
    return strcmp(cipher, cbuffer) == 0;
}

int main() {
    cin >> plaintext;
    cin >> cipher;
    int slen = strlen(cipher);
    for (int i = 1; i <= slen; i++)
        if (slen % i == 0 && attempt_a(slen, i)) {
            cout << i;
            return 0;
        }
    cout << "No Solution";
    return 0;
}
