#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
map<string, string> dict;
int main()
{
    char buffer[32];
    char k[16], v[16];
    string key, value;
    while(gets(buffer) && buffer[0] >= 'a')
    {
        sscanf(buffer, "%s%s", v, k);
        key = k;
        value = v;
        dict[key] = value;
    }
    while(gets(buffer) && buffer[0] >= 'a')
    {
        key = buffer;
        value = dict[key];
        if (value != "")
            printf("%s\n", value.c_str());
        else printf("eh\n");
    }
    return 0;
}
