#include <iostream>
using namespace std;

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

template<typename T>
void do_swap(T& a, T& b) {
    T c = a; a = b; b = c;
}

struct mouse {
    int s, p, no;
    bool operator<(mouse o) {
        if (p == o.p) return no < o.no;
        return p > o.p;
    }
};

inline int compare_int(int a, int b) {
    if (a > b) return 2;
    if (a == b) return 1;
    return 0;
}

int n, r;
#define data datax
mouse data[200007];

int main() {
    cin >> n >> r;
    int m = 2 * n;
    for (int i = 0; i < m; i++) scanf("%d", &data[i].p);
    for (int i = 0; i < m; i++) {
        scanf("%d", &data[i].s);
        data[i].no = i + 1;
    }
    merge_sort(data, 0, m);
    
    for (int pk = 0; pk < r; pk++) {
        for (int i = 0; i < n; i++) {
            data[2 * i].p += compare_int(data[2 * i].s, data[2 * i + 1].s);
            data[2 * i + 1].p += compare_int(data[2 * i + 1].s, data[2 * i].s);
        }
        int mx = m - 1;
        for (int bub = 0; bub < 4; bub++)
            for (int i = 0; i < mx; i++)
                if (!(data[i] < data[i + 1]))
                    do_swap(data[i], data[i + 1]);
    }
    for (int i = 0; i < m; i++) printf("%d ", data[i].no);
    return 0;
}
