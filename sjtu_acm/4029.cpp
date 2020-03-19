#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n;
int a[1007];
bool book[20002] = {};
int maxa = 0;
int avail[20002] = {};

template<typename T>
class array_list {
protected:
    int _size;
    int _capacity;
    T * data;
    void extend_to(int capacity) {
        T * ndata = new T[capacity];
        for (int i = 0; i < _capacity; i++) ndata[i] = data[i];
        delete[] data;
        _capacity = capacity;
        data = ndata;
    }
public:
    array_list() {
        _capacity = 16; _size = 0;
        data = new T[_capacity];
    }
    array_list(const array_list<T>& copy) {
        _size = copy._size; _capacity = copy._capacity;
        data = new T[_capacity];
        for (int i = 0; i < _capacity; i++) data[i] = copy.data[i];
    }
    virtual int size() const { return _size; }
    T * raw_data() { return data; }
    virtual T& operator[](int index) { return data[index]; }
    void append(const T& elm) {
        if (_size == _capacity) extend_to(_capacity * 2);
        data[_size++] = elm;
    }
    T pop() { return data[--_size]; }
    virtual ~array_list() { delete[] data; }
};

template<typename T>
class array_deque: public array_list<T> {
    using array_list<T>::_size;
    using array_list<T>::extend_to;
    using array_list<T>::_capacity;
    using array_list<T>::data;
protected:
    int next_index(int index) { if (index + 1 >= _size) return (index + 1 - _size); else return index + 1; }
    int prev_index(int index) { if (index - 1 < 0) return (index - 1 + _size); else return index - 1; }
    void extend_and_realloc() {
        extend_to(_capacity * 2);
        int i, j;
        for (i = head, j = _size; i != tail; i = next_index(i), j++) {
            data[j] = data[i];
        }
        head = _size;
        _size = _capacity;
        tail = j >= _size ? j - _size : j;
    }
public:
    int head, tail;  // [head, tail)
    array_deque(): array_list<T>() {
        head = 0; tail = 0; _size = _capacity;
    }
    array_deque(const array_deque<T>& copy): array_list<T>(copy) {
        head = copy.head; tail = copy.tail;
    }
    void push_back(const T& elm) {
        if (head == next_index(tail)) extend_and_realloc();
        data[tail] = elm;
        tail = next_index(tail);
    }
    void push_front(const T& elm) {
        if (tail == prev_index(head)) extend_and_realloc();
        data[head = prev_index(head)] = elm;
    }
    virtual int size() { return tail - head >= 0 ? tail - head : tail - head + _size; }
    T pop_back() {
        return data[tail = prev_index(tail)];
    }
    T pop_front() {
        T ret = data[head];
        head = next_index(head);
        return ret;
    }
};

array_deque<int> bfq;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > maxa) maxa = a[i];
    }
    for (int i = 0; i < 20002; i++) avail[i] = -1;
    
    bfq.push_back(0);
    avail[0] = 0;
    while (bfq.size() > 0) {
        int cur = bfq.pop_front();
        book[cur] = false;
        for (int i = 0; i < n; i++) {
            int next_c = (a[i] + cur) % maxa;
            int next_v = (a[i] + cur) / maxa + avail[cur];
            if (avail[next_c] < 0 || avail[next_c] > next_v) {
                avail[next_c] = next_v;
                if (book[next_c]) continue;
                bfq.push_back(next_c);
                book[next_c] = true;
            }
        }
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int cquery;
        scanf("%d", &cquery);
        printf((avail[cquery % maxa] * maxa <= cquery && avail[cquery % maxa] >= 0) ? "YES\n" : "NO\n");
    }
    return 0;
}
