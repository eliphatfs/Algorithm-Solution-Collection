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

int n;
int a[100007];
const long long p = 1000000007LL;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(a, 0, n);
    long long answer = 0;
    for (long long i = 0; i < n - 1; i++) {
        answer += (a[i + 1] - a[i]) * (i + 1) * (n - i - 1);
        answer %= p;
    }
    cout << answer;
    return 0;
} 
