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
        if (array[pt1] < array[pt2]) temp[ptTemp++] = array[pt1++];
        else temp[ptTemp++] = array[pt2++];

    while (pt1 < mid) temp[ptTemp++] = array[pt1++];
    while (pt2 < high) temp[ptTemp++] = array[pt2++];
    
    for (int i = low; i < high; i++) array[i] = temp[i - low];

    delete[] temp;
}

int n, m;
int t[100007];
int boy[1000007];
int girl[1000007];
int pb = 0, pg = 0, nb = 0, ng = 0;

long long sumg = 0, sumb = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) { scanf("%d", &t[i]); t[i] += t[i - 1]; }
    cin >> m;
    int gender, it;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &gender, &it);
        if (gender == 1) { boy[nb++] = it; }
        else { girl[ng++] = it; }
    }
    merge_sort(boy, 0, nb);
    merge_sort(girl, 0, ng);
    for (int i = 0; i < n; i++) {
        while (boy[pb] <= t[i] && girl[pg] <= t[i] && pb < nb && pg < ng) {
            sumb += t[i] - boy[pb];
            sumg += t[i] - girl[pg];
            pb++; pg++;
        }
    }
    while (pb < nb) sumb += t[n - 1] - boy[pb++];
    while (pg < ng) sumg += t[n - 1] - girl[pg++];
    printf("%.2lf %.2lf", sumb / (double)nb, sumg / (double)ng);
    return 0;
}
