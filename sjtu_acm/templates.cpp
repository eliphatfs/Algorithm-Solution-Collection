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
    int _size;
    int _capacity;
    T * data;
protected:
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
    int size() const { return _size; }
    T& operator[](int index) { return data[index]; }
    void append(T elm) {
        if (_size == _capacity) extend_to(_capacity * 2);
        data[_size++] = elm;
    }
    T pop() { return data[--_size]; }
    ~array_list() { delete[] data; }
};
