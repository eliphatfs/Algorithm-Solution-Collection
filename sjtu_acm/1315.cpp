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

int gcd(int a, int b) {  // a >= b
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int n;

struct frac {
    int num, den;
    frac() {}
    frac(int nu, int d) { num = nu; den = d; }
    frac simplified() {
        return frac(num / gcd(num, den), den / gcd(num, den));
    }
    bool operator<(const frac & o) const {
        return num * o.den < o.num * den;
    }
    int identifier() { return num * (n + 1) + den; }
};

int main() {
    cin >> n;
    int * exist = new int[(n + 2) * (n + 2)];
    frac * fracs = new frac[(n + 2) * (n + 2)];
    int nfrac = 0;
    for (int i = 0; i < (n + 2) * (n + 2); i++) exist[i] = 0;
    
    for (int den = 1; den <= n; den++) {
        for (int num = 0; num <= den; num++) {
            frac cur = frac(num, den).simplified();
            if (0 == exist[cur.identifier()]) {
                fracs[nfrac++] = cur;
                exist[cur.identifier()] = 1;
            }
        }
    }
    
    merge_sort(fracs, 0, nfrac);
    for (int i = 0; i < nfrac; i++)
        cout << fracs[i].num << '/' << fracs[i].den << '\n';
    
    delete fracs;
    delete exist;
    return 0;
}
