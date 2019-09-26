#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int L;
int arr[107][107] = {0};
int arr2[107][107] = {0};

int main() {
    cin >> L;
    for (int i=1; i<=L; i++)
        for (int j=1; j<=L; j++)
            scanf("%d", &arr[i][j]);
    
    for (int it = 0;; ++it) {
        bool flag = true;
        for (int i=1; i<=L; i++)
            for (int j=1; j<=L; j++)
                if (arr[i][j] == 0) flag = false;
        if (flag) {
            cout << it;
            break;
        }
        memcpy(arr2, arr, sizeof(arr));
        for (int i=1; i<=L; i++)
            for (int j=1; j<=L; j++)
                if (arr[i][j] == 1) {
                    if (arr[i - 1][j] == 0) arr2[i - 1][j] = 1;
                    if (arr[i + 1][j] == 0) arr2[i + 1][j] = 1;
                    if (arr[i][j - 1] == 0) arr2[i][j - 1] = 1;
                    if (arr[i][j + 1] == 0) arr2[i][j + 1] = 1;
                }
        memcpy(arr, arr2, sizeof(arr));
    }
    return 0;
}
