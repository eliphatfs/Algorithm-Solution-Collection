#include <iostream>
#include <string>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int n, a, q;
long double p = 0.0;
string s;
set<int> l;
map<set<int>, bool> vis;

void dfs(int depth)
{
    if (vis[l]) return;
    vis[l] = true;
    long double pc = 1.0;
    for (int i=0; i<n; i++)
    {
        bool book = false;
        for (set<int>::iterator it = l.begin(); it != l.end(); it++)
            if ((*it) == i)
            {
                book = true;
                if (s[i] == '1')
                    pc *= (100 - a) / 100.0;
                else
                    pc *= a / 100.0;
            }
        if (!book)
        {
            if (s[i] == '0')
                pc *= (100 - a) / 100.0;
            else
                pc *= a / 100.0;
        }
    }
    p += pc;
    if (depth == n - q) return;
    else
    {
        for (int i=0; i<n; i++)
        {
            bool book = false;
            for (set<int>::iterator it = l.begin(); it != l.end(); it++)
                if ((*it) == i)
                {
                    book = true;
                }
            if (book) continue;
            l.insert(i);
            dfs(depth + 1);
            l.erase(i);
        }
    }
}

int main()
{
    cin>>n>>a>>q;
    cin>>s;
    if (q == 0) printf("1.000");
    else
    {
        dfs(0);
        printf("%.3lf", (double) p);
    }
    //cin.get(), cin.get();
    return 0;
}
