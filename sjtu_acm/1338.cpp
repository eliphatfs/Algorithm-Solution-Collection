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

int main() {
    int n;
    cin >> n;
    int * a = new int[n];
    int * b = new int[n];
    
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    
    merge_sort<int>(a, 0, n);
    merge_sort<int>(b, 0, n);
    
    unsigned long long ans_max = 0;
    for (int i = 0; i < n; i++) ans_max += (unsigned long long)a[i] * (unsigned long long)b[i];
    unsigned long long ans_min = 0;
    for (int i = 0; i < n; i++) ans_min += (unsigned long long)a[i] * (unsigned long long)b[n - i - 1];
    
    cout << ans_max << ' ' << ans_min;
    
    delete a;
    delete b;
    return 0;
}
