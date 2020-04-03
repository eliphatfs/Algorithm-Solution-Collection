#include <iostream>
#include <cstdio>
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
        if (array[pt1] < array[pt2]) temp[ptTemp++] = array[pt1++];
        else temp[ptTemp++] = array[pt2++];

    while (pt1 < mid) temp[ptTemp++] = array[pt1++];
    while (pt2 < high) temp[ptTemp++] = array[pt2++];
    
    for (int i = low; i < high; i++) array[i] = temp[i - low];

    delete[] temp;
}

int n, s;
int d[100007];

bool judge(int a) {
    int placed = 1;
    int dx = 0;
    for (int i = 1; i < n; i++) {
        dx += d[i] - d[i - 1];
        if (dx >= a) { dx = 0; placed++; }
        if (placed >= s) return true;
    }
    return false;
}

int bsearch(int a, int b) {  // [a, b)
    int c = (a + b) / 2;
    if (judge(c)) {
        if (judge(c + 1)) return bsearch(c + 1, b);
        return c;
    }
    return bsearch(a, c);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    merge_sort(d, 0, n);
    cout << bsearch(1, d[n - 1] + 1);
    return 0;
}
