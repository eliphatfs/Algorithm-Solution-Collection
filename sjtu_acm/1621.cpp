#include <iostream>
using namespace std;

template<typename T>
void merge_sort(T * array, int low, int high) { // [low, high)
    if (low >= high - 1) return;
    int mid = (low + high) / 2;
    merge_sort(array, low, mid);
    merge_sort(array, mid, high);
    int pt1 = low, pt2 = mid;
    
    T * temp = new T[high - low];
    int ptTemp = 0;

    while (pt1 < mid && pt2 < high)
        if (array[pt1] > array[pt2]) temp[ptTemp++] = array[pt1++];
        else temp[ptTemp++] = array[pt2++];

    while (pt1 < mid) temp[ptTemp++] = array[pt1++];
    while (pt2 < high) temp[ptTemp++] = array[pt2++];
    
    for (int i = low; i < high; i++) array[i] = temp[i - low];

    delete[] temp;
}

int n;
char matrix[1002][1002];
int larges[1002][1002];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%s", matrix[i] + 1);

    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            if (matrix[i][j] == '1')
                larges[j][i] = larges[j - 1][i] + 1;
    int ans = 0;
    for (int j = 1; j <= n; j++) {
        merge_sort(larges[j], 0, n);
        for (int i = 0; i < n; i++) {
            if (larges[j][i] * (i + 1) > ans)
                ans = larges[j][i] * (i + 1);
        }
    }
    cout << ans;
    return 0;
}
