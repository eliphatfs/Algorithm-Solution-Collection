template<typename T>
void reverse_str(T * x, int slen) {
    for (int i = 0; i < slen / 2; i++) do_swap(x[i], x[slen - 1 - i]);
}

template<typename T>
void do_swap(T& a, T& b) {
    T c = a; a = b; b = c;
}

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

template<typename E>
struct edge {
    int from;
    int to;
    int weight;
    E data;
};

template<typename V, typename E>
class graph {
public:
    V * node_data;
    array_list<edge<E> > * edge_from;
    graph(int n_nodes) {
        node_data = new V[n_nodes];
        edge_from = new array_list<edge<E> >[n_nodes]();
    }
    void create_edge(const edge<E>& e) {
        edge_from[e.from].append(e);
    }
    void create_edge(int from, int to, int weight, const E& data) {
        edge<E> e; e.from = from; e.to = to; e.weight = weight; e.data = data;
        create_edge(e);
    }
    edge<E> remove_edge(int from, int to) {
        for (int i = 0; i < edge_from[from].size(); i++) {
            if (edge_from[from][i].to == to) {
                do_swap(edge_from[from][i], edge_from[from][edge_from[from].size() - 1]);
                return edge_from[from].pop();
            }
        }
    }
};

#include <iostream>
using namespace std;
int test_deque() {
    array_deque<int> t;
    for (int i = 0; i < 50; i++) t.push_back(i);
    cout << t.pop_back() << ' ';
    cout << t.pop_back() << ' ';
    cout << t.pop_front() << ' ';
    cout << t.pop_front() << endl;
    for (int i = 0; i < 50; i++) t.push_front(i);
    cout << t.pop_front() << ' ';
    cout << t.pop_front() << ' ';
    cout << t.pop_back() << ' ';
    cout << t.pop_back() << endl;
    cout << t.size() << endl;
    while (t.size() > 0) { cout << t.pop_front() << ' ' << t.pop_back() << ' '; }
    cin.get(), cin.get();
    return 0;
}

int main() { return test_deque(); }
