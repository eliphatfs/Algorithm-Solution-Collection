#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN = 128;

struct bignum
{
    short digits[MAXN];
    int len;
    bignum()
    {
        len = 0;
    }
    bignum operator=(int num)
    {
        len = 0;
        while (num > 0)
        {
            digits[len] = num % 10;
            num /= 10;
            ++len;
        }
        return *this;
    }
    bignum operator=(bignum num)
    {
        len = num.len;
        for (int i=0; i<len; i++)
            digits[i] = num.digits[i];
        return *this;
    }
    void add(bignum* sol, bignum oth)
    {
        memset(sol->digits, 0, sizeof(short)*(max(len, oth.len) + 1));
        register int l = 0;
        while (l < len && l < oth.len)
        {
            sol->digits[l] += digits[l] + oth.digits[l];
            if (sol->digits[l] >= 10000)
                sol->digits[l] -= 10000, sol->digits[l+1] += 1;
            ++l;
        }
        while (l < len)
        {
            sol->digits[l] += digits[l];
            if (sol->digits[l] >= 10000)
                sol->digits[l] -= 10000, sol->digits[l+1] += 1;
            ++l;
        }
        while (l < oth.len)
        {
            sol->digits[l] += oth.digits[l];
            if (sol->digits[l] >= 10000)
                sol->digits[l] -= 10000, sol->digits[l+1] += 1;
            ++l;
        }
        if (sol->digits[l] > 0)
            ++l;
        sol->len = l;
    }
    bignum operator+(bignum oth)
    {
        bignum a = bignum();
        add(&a, oth);
        return a;
    }
    string toString()
    {
        string str = string();
        str.resize(len*4);
        int strpt = 0;
        bool flag = false;
        for (int i=len-1; i>=0; i--)
        {
            if (flag || (digits[i]/1000)%10 != 0)
                str[strpt++] = (digits[i]/1000)%10 + '0', flag = true;
            if (flag || (digits[i]/100)%10 != 0)
                str[strpt++] = (digits[i]/100)%10 + '0', flag = true;
            if (flag || (digits[i]/10)%10 != 0)
                str[strpt++] = (digits[i]/10)%10 + '0', flag = true;
            str[strpt++] = digits[i]%10 + '0';
            flag = true;
        }
        return string(str.c_str());
    }
};

bignum ans[3][801];
int main()
{
    int m, n;
    cin>>m>>n;
    for (int i=0; i<3; i++)
        for (int j=0; j<801; j++)
            ans[i][j] = 1;
    for (int x=2; x<=m; x++)
    {
        for (int y=2; y<=n; y++)
        {
            ans[(x+1)%2+1][y].add(&ans[x%2+1][y], ans[x%2+1][y-1]);
        }
    }
    cout<<ans[m%2+1][n].toString();
    //cin.get(),cin.get();
    return 0;
}
