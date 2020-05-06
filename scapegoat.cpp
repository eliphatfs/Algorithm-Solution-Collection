#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

template <typename T>
struct sgnode {
    T data;
    sgnode * left, * right;
    sgnode() { left = right = NULL; }
    sgnode(T d) { data = d; left = right = NULL; }
};

template <typename T>
class scapegoat_tree {
private:
    sgnode<T> * tree;
    int maxsize;
    int size;
    double alpha;
    
    int insert_and_propagate(const T& data, sgnode<T> * & cur, sgnode<T> * & target, sgnode<T> * & branch, int depth) {
        int s = sg_insert(data, target, depth + 1);
        if (s == 0) return 0;
        int sbranch = sg_size(branch);
        if (s / alpha >= s + sbranch + 1) { sg_rebalance(cur); return 0; }
        else return s + sbranch + 1;
    }
    
    int sg_insert(const T& data, sgnode<T> * & cur, int depth) {
        if (cur == NULL) {
            cur = new sgnode<T>(data);
            return depth > -log(size) / log(alpha) ? 1 : 0;
        }
        if (data < cur->data) return insert_and_propagate(data, cur, cur->left, cur->right, depth);
        else return insert_and_propagate(data, cur, cur->right, cur->left, depth);
    }
    
    sgnode<T> * & sg_find(const T& data, sgnode<T> * & cur) {
        if (cur == NULL) return cur;
        if (cur->data == data) return cur;
        if (data < cur->data) return sg_find(data, cur->left);
        return sg_find(data, cur->right);
    }
    
    sgnode<T> * & sg_leftmost(sgnode<T> * & cur) {
        if (cur->left) return sg_leftmost(cur->left);
        return cur;
    }
    
    void sg_pop(sgnode<T> * & cur) {
        if (cur->left == NULL && cur->right == NULL) { delete cur; cur = NULL; return; }
        if (cur->left && cur->right) {
            sgnode<T> * & target = sg_leftmost(cur->right);
            cur->data = target->data;
            sg_pop(target);
            return;
        }
        sgnode<T> * todel = cur;
        if (cur->left) cur = cur->left;
        else if (cur->right) cur = cur->right;
        delete todel;
    }
    
    void sg_walk(sgnode<T> * root, T * & next) {
        if (root == NULL) return;
        if (root->left) sg_walk(root->left, next);
        *(next++) = root->data;
        if (root->right) sg_walk(root->right, next);
    }
    
    void sg_rebuild(sgnode<T> * root, T * space, int L, int R) {
        int mid = (L + R) / 2;
        root->data = space[mid];
        if (L < mid) { root->left = new sgnode<T>(); sg_rebuild(root->left, space, L, mid); }
        if (mid + 1 < R) { root->right = new sgnode<T>(); sg_rebuild(root->right, space, mid + 1, R); }
    }

    void sg_rebalance(sgnode<T> * root) {
        int n = sg_size(root);
        T * space = new T[n];
        T * useless_bk = space;
        sg_walk(root, useless_bk);
        sg_clear(root->left); sg_clear(root->right);
        sg_rebuild(root, space, 0, n);
        delete[] space;
    }
    
    int sg_size(sgnode<T> * cur) {
        if (cur == NULL) return 0;
        return 1 + sg_size(cur->left) + sg_size(cur->right);
    }
    
    void sg_clear(sgnode<T> * & cur) {
        if (cur == NULL) return;
        sg_clear(cur->left); sg_clear(cur->right);
        delete cur;
        cur = NULL;
    }
public:
    scapegoat_tree(double _alpha = 0.65) { tree = NULL; size = maxsize = 0; alpha = _alpha; }
    int get_size() const { return size; }
    
    void walk(T * space) { sg_walk(tree, space); }
    
    void insert(const T& data) {
        ++size; maxsize = max(size, maxsize);
        sg_insert(data, tree, 0);
    }
    
    sgnode<T> * find(const T& data) { return sg_find(data, tree); }
    
    void remove(const T& data) {
        sgnode<T> * & target = sg_find(data, tree);
        if (target != NULL) { sg_pop(target); --size; }
        if (sg_remove(data, tree)) --size;
        if (size <= maxsize * alpha && size > 0) {
            sg_rebalance(tree);
            maxsize = size;
        }
    }

    sgnode<T> * leftmost() { return tree ? sg_leftmost(tree) : NULL; }
    ~scapegoat_tree() { sg_clear(tree); size = 0; }
};

// Only to test with sorting capability
int main() {
    int n;
    cin >> n;
    scapegoat_tree<int> tree;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        tree.insert(x);
    }
    /*for (int i = 0; i < n; i++) {
        int x = tree.leftmost()->data;
        printf("%d ", x);
        tree.remove(x);
    }*/
    int * sorted = new int[n]; 
    tree.walk(sorted);
    for (int i = 0; i < n; i++) printf("%d ", sorted[i]);
    delete sorted;
    return 0;
}
