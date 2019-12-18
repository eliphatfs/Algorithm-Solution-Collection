#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
 
char dst[400], sub[400], src[400];
char opt[400] = {0};
 
bool startswith(char * haystack, char * needle) {
    int lenH = strlen(haystack);
    int lenN = strlen(needle);
    if (lenN > lenH)
        return false;
    for (int i = 0; i < lenN; i++)
        if (haystack[i] != needle[i]) return false;
    return true;
}
 
bool parse(char * inp, char * rep, char * tar) {
    int pt = 0;
    bool accepted = false;
    while (*inp) {
        if (startswith(inp, rep)) {
            strcpy(opt + pt, tar);
            inp += strlen(rep);
            pt += strlen(tar);
            accepted = true;
        }
        else {
            opt[pt++] = *inp;
            inp++;
        }
    }
    opt[pt] = '\0';
    return accepted;
}
 
int main() {
    cin >> dst >> sub >> src;
    if (!parse(dst, sub, src))
        cout << "No string to replace!";
    else if (parse(src, sub, src))
        cout << "error!";
    else {
        parse(dst, sub, src);
        cout << opt;
    }
    return 0;
}
