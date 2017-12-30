#include <iostream>
#include <string>
using namespace std;
inline char rev(char x)
{
    return x == 'K' ? 'V' : 'K'; 
}

int main()
{
    string inp;
    cin>>inp;
    int len = inp.length();
    int maxa = 0;
    for (int j=0; j<len-1; j++)
    {
        if (inp[j] == 'V' && inp[j + 1] == 'K')
            ++maxa;
    }
    
    for (int i=0; i<len; i++)
    {
        string ns = string(inp);
        ns[i] = rev(ns[i]);
        int ans = 0;
        for (int j=0; j<len-1; j++)
        {
            if (ns[j] == 'V' && ns[j + 1] == 'K')
                ++ans;
        }
        if (ans > maxa) maxa = ans;
    }
    cout<<maxa;
    //cin.get(), cin.get();
    return 0;
}
