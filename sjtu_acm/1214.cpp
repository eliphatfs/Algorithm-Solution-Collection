#include <iostream>
#include <cstdio>
using namespace std;

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
    virtual T& operator[](int index) { return data[(head + index) % _size]; }
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
    T front() { return data[head]; }
    T back() { return data[prev_index(tail)]; }
};

int isSonOfOthers[1000001];
int leftSon[1000001];
int sibling[1000001];
int val[1000001];
int n;

void preOrder(int cur) {
    if (cur == 0) return;
    printf("%d ", val[cur]);
    preOrder(leftSon[cur]);
    preOrder(sibling[cur]);
}

void postOrder(int cur) {
    if (cur == 0) return;
    postOrder(leftSon[cur]);
    printf("%d ", val[cur]);
    postOrder(sibling[cur]);
}

void layered(int root) {
    array_deque<int> bfq;
    bfq.push_back(root);
    while (bfq.size() > 0) {
        int cur = bfq.pop_front();
        printf("%d ", val[cur]);
        int son = leftSon[cur];
        while (son != 0) {
            bfq.push_back(son);
            son = sibling[son];
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", leftSon + i, sibling + i, val + i);
        isSonOfOthers[leftSon[i]] = i;
        isSonOfOthers[sibling[i]] = i;
    }
    int root = 0;
    for (int i = 1; i <= n; i++) {
        if (!isSonOfOthers[i]) root = i;
    }
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    layered(root);
    printf("\n");
    return 0;
}
