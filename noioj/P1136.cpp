#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct wordtype
{
    long long data[4];
    void init(char cnt[])
    {
        int cpt = 0;
        for (int i=0; i<4; i++)
        {
            data[i] = 0;
            long long base = 1;
            for (int j=0; j<7 && cpt < 26; j++)
            {
                data[i] += base * cnt[cpt++];
                base *= 128;
            }
        }
    }
    bool operator<(wordtype other)const
    {
        for (int i=0; i<4; i++)
        {
            if (data[i] < other.data[i]) return true;
            else if (data[i] > other.data[i]) return false;
        }
        return false;
    }
};

map<wordtype,int> typemap = map<wordtype,int>();
int types = 0;

int main()
{
    int n;
    cin>>n;
    char buffer[127];
    for (int i=0; i<n; i++)
    {
        scanf("%s", buffer);
        char cnt[26] = {0};
        int len = strlen(buffer);
        for (int j=0; j<len; j++)
        {
            cnt[buffer[j]-'A']++;
        }
        wordtype wd;
        wd.init(cnt);
        if (typemap[wd] == 0) types++;
        typemap[wd]++;
    }
    cout<<types;
    //cin.get(),cin.get();
    return 0;
}
