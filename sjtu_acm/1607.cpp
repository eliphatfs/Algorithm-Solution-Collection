#include <iostream>
#include <cstdio>
#include <cstring>
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
        _capacity = 4; _size = 0;
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
};

int ORDER = 0;
struct person {
    int timestamp;
    int groupid;
    bool operator<(const person& other) const {
        return ORDER == 0 ? timestamp < other.timestamp : groupid < other.groupid;
    }
};

int n;
int group_position[2000007];
person people[2000007];

typedef array_deque<person> group;
group * queue[4000007];
int qhead = 0;
int qtail = 0;

void join_groups() {
    int cg = 0;
    int gref = people[0].groupid;
    for (int i = 0; i < n; i++) {
        if (people[i].groupid == gref) people[i].groupid = cg;
        else {
            gref = people[i].groupid;
            people[i].groupid = ++cg;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &people[i].groupid);
        people[i].timestamp = i + 1;
    }
    ORDER = 1;
    merge_sort(people, 0, n);
    join_groups();
    ORDER = 0;
    merge_sort(people, 0, n);
    memset(group_position, 0xff, sizeof(group_position));
    int q;
    cin >> q;
    int inq = 0;
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        if (x == 0) {
            if (inq >= n) continue;
            int& gp = group_position[people[inq].groupid];
            if (gp < 0) { gp = qtail; queue[qtail] = new group(); qtail++; }
            queue[gp]->push_back(people[inq]);
            inq++;
        }
        else {
            if (qtail == qhead) { printf("-1\n"); continue; }
            person popped = queue[qhead]->pop_front();
            printf("%d\n", popped.timestamp);
            if (queue[qhead]->size() == 0) {
                delete queue[qhead];
                qhead++;
                group_position[popped.groupid] = -1;
            }
        }
    }
    return 0;
}
