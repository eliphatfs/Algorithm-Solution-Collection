#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string strs[100000];
string kind;

bool compare(string a,string b)
{
    if (kind[0] == 'n')
    {
        string s1 = string(a);
        string s2 = string(b);
        for (int j=0; j<s1.length(); j++)
        {
            if ((s1[j] <= 'Z') && (s1[j] >= 'A'))
                s1[j] += ('a' - 'A');
        }
        for (int j=0; j<s2.length(); j++)
        {
            if ((s2[j] <= 'Z') && (s2[j] >= 'A'))
                s2[j] += ('a' - 'A');
        }
        return s1 < s2;
    }
    else
        return a < b;
}

int n;

int main()
{
    string tmp;
    cin>>kind;
    cin>>n;
    getchar();
    for (int i=0; i<n; i++)
    {
        char buffer[4096];
        gets(buffer);
        tmp = buffer;
        strs[i] = tmp;
    }
    sort(strs, strs + n, compare);
    if (kind[kind.length()-2] == 'n')
    {
        for (int i=0; i<n; i++)
            cout<<strs[i]<<endl;
    }
    else for (int i=n-1; i>=0; i--)
            cout<<strs[i]<<endl;
    return 0;
}
