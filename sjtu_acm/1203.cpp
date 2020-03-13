#include <iostream>
using namespace std;

template <typename T>
class array_list {
    int size;
    T * data;
public:
    array_list (int size_) {
        size = size_;
        data = new T[size];
    }
    array_list (const array_list<T>& copy) {
        size = copy.size;
        data = new T[size];
        for (int i = 0; i < size; i++)
            data[i] = copy.data[i];
    }
    ~array_list () {
        delete[] data;
    }
    
    T& operator[](int index) { return data[index]; }
    array_list<T> operator+(const array_list<T>& other) {
        array_list<T> concat(size + other.size);
        for (int i = 0; i < size; i++) concat[i] = data[i];
        for (int i = 0; i < other.size; i++) concat[i + size] = other.data[i];
        return concat;
    }
    
    int get_size() { return size; }
};

template<typename T>
void solve_for_type() {
    int len1, len2;
    cin >> len1 >> len2;
    array_list<T> arr1(len1);
    array_list<T> arr2(len2);
    for (int i = 0; i < len1; i++) cin >> arr1[i];
    for (int i = 0; i < len2; i++) cin >> arr2[i];
    array_list<T> result = arr1 + arr2;
    for (int i = 0; i < result.get_size(); i++) cout << result[i] << ' ';
}

int main() {
    char buf[10];
    cin >> buf;
    if (buf[0] == 'i') solve_for_type<int>();
    if (buf[0] == 'c') solve_for_type<char>();
    if (buf[0] == 'd') solve_for_type<double>();
    // cin.get(), cin.get();
    return 0;
}
