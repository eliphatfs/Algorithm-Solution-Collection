#include <iostream>
#include <cmath>
using namespace std;

int n;
int A[100007];
int B[100007] = {0};
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) { scanf("%d", &B[i]); B[i] -= A[i]; }
    long long pos = 0, neg = 0;
    for (int i = 1; i <= n; i++) if (B[i] > B[i - 1]) pos += B[i] - B[i - 1]; else neg -= B[i] - B[i - 1];
    printf("%lld", max(pos, neg));
    return 0;
}
