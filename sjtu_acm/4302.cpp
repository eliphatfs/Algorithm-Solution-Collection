#include <iostream>
using namespace std;
#define F 40
 
class HugeInteger {
    bool pos;
    int * num;
    int size;
public:
    HugeInteger(void) {
        num = new int[F];
        size = 0;
        pos = true;
        for (int i = 0; i < F; i++) num[i] = 0;
    }
    HugeInteger(const HugeInteger & copy) {
        num = new int[F];
        size = copy.size;
        pos = copy.pos;
        for (int i = 0; i < F; i++) num[i] = copy.num[i];
    }
    ~HugeInteger() {
        delete[] num;
    }
    void size_consistent() {
        size = F;
        while (size > 1 && num[size - 1] == 0) {
            --size;
        }
    }
    void input() {
        char buffer[64];
        cin >> buffer;
        char * pbuf = buffer;
        if ('-' == *pbuf) {
            pos = false;
            ++pbuf;
        }
        while (*pbuf) {
            num[size++] = (*pbuf) - '0';
            ++pbuf;
        }
        for (int i = 0; i < size / 2; i++) {
            swap(num[size - 1 - i], num[i]);
        }
    }
    friend HugeInteger operator+(const HugeInteger& one, const HugeInteger& another) {
        HugeInteger n;
        if (one.pos == another.pos) {
            n.pos = one.pos;
            for (int i = 0; i < F; i++)
                n.num[i] = one.num[i] + another.num[i];
            for (int i = 0; i < F - 1; i++) {
                // cout << n.num[i] << ' ' << n.num[i + 1] << ' ';
                n.num[i + 1] += n.num[i] / 10;
                n.num[i] %= 10;
                // cout << n.num[i] << ' ' << n.num[i + 1] << endl;
            }
        }
        else {
            if (one.pos && !another.pos) {
                for (int i = 0; i < F; i++)
                    n.num[i] = one.num[i] - another.num[i];
                for (int i = 0; i < F - 1; i++) {
                    while (n.num[i] < 0) {
                        n.num[i] += 10;
                        n.num[i + 1]--;
                    }
                }
                if (n.num[F - 1] < 0) {
                    HugeInteger moved1(one);
                    HugeInteger moved2(another);
                    moved1.pos = false;
                    moved2.pos = true;
                    HugeInteger nn = moved2 + moved1;
                    nn.pos = false;
                    return nn;
                }
            }
            else return another + one;
        }
        return n;
    }
    bool operator==(const HugeInteger& another) {
        if (pos != another.pos)
            return false;
        for (int i = 0; i < F; i++)
            if (num[i] != another.num[i])
                return false;
        return true;
    }
    void output() {
        size_consistent();
        if (!pos) cout << '-';
        for (int i = size - 1; i >= 0; i--)
            cout << num[i];
        cout << endl;
    }
};
 
int main() {
    HugeInteger a, b;
    a.input();
    b.input();
    a.output();
    b.output();
    (a + b).output();
    cout << ((a == b) ? "True" : "False");
    return 0;
}
