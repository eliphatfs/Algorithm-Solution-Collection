#include <stdio.h>
#include <string.h>
short a[511], b[511];
short ans[1023];
char ai[511], bi[511];

int main() {
    scanf("%s%s", ai, bi);
    int na = strlen(ai), nb = strlen(bi);
    for (int i = 0; i < na; i++) a[i] = ai[na - 1 - i] - '0';
    for (int i = 0; i < nb; i++) b[i] = bi[nb - 1 - i] - '0';
    
    for (int i = 0; i < 511; i++)
        for (int j = 0; j < 511; j++)
            ans[i + j] += a[i] * b[j];
    for (int i = 0; i < 1023; i++) { ans[i + 1] += ans[i] / 10; ans[i] %= 10; }
    
    int nout = 0;
    for (int i = 1022; i >= 0; i--) {
        if (nout == 0 && ans[i] == 0) continue;
        nout++; printf("%c", (char)(ans[i] + '0'));
    }
    if (nout == 0) printf("0");
    return 0;
}
