#include <iostream>
using namespace std;

int n;
struct act {
    int s, e;
    bool operator<(act o) { if (s == o.s) return e < o.e; else return s < o.s; }
};
act d[100007];

template<typename T>
void merge_sort(T * array, int low, int high) {  // [low, high)
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

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d%d", &d[i].s, &d[i].e);
    merge_sort(d, 0, n);
    int ans = 0;
    int cur_left = 91000000;
    for (int i = n - 1; i >= 0; i--) {
        if (d[i].e <= cur_left) {
            cur_left = d[i].s;
            ++ans;
        }
    }
    cout << ans;
    return 0;
}
