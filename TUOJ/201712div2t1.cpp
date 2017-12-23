#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct sbt {
    short data[26];
    sbt() {
        memset(data, 0, sizeof(data));
    }
    sbt operator+(sbt oth) {
        sbt news = sbt();
        for (int i=0; i<26; i++)
            news.data[i] = this->data[i] + oth.data[i];
        return news;
    }
    sbt operator-(sbt oth) {
        sbt news = sbt();
        for (int i=0; i<26; i++)
            news.data[i] = this->data[i] - oth.data[i];
        return news;
    }
};

sbt parse_sbt(string& str) {
    int len = str.length();
    sbt news = sbt();
    for (int i=0; i<len; i++)
    {
        char cur = str[i];
        if (cur >= 'A' && cur <= 'Z')
        {
            if (i + 1 < len && str[i + 1] >= '0' && str[i + 1] <= '9')
                news.data[cur - 'A'] = str[i + 1] - '0';
            else
                news.data[cur - 'A'] = 1;
        }
    }
    return news;
}

string make_simple(sbt subst) {
    char buf[100];
    int bpt = 0;
    for (int i=0; i<26; i++)
    {
        switch(subst.data[i])
        {
            case 0:
                break;
            case 1:
                buf[bpt++] = i + 'A';
                break;
            default:
                if (subst.data[i] > 9 || subst.data[i] < 0)
                    return string("!");
                buf[bpt++] = i + 'A';
                buf[bpt++] = subst.data[i] + '0';
        }
    }
    buf[bpt++] = '\0';
    return string(buf);
}

void do_solve() {
    string cur;
    cin >> cur;
    int len = cur.length();
    bool onRight = false;
    bool unkOnRight = false;
    char buf[100] = {0};
    int bpt = 0;
    vector<sbt> le = vector<sbt>();
    vector<sbt> ri = vector<sbt>();

    for (int i=0; i<len; i++)
    {
        if (cur[i] == '+')
        {
            if (cur[i - 1] == '?') continue;
            buf[bpt++] = '\0';
            string str = string(buf);
            bpt = 0;
            if (onRight)
                ri.push_back(parse_sbt(str));
            else
                le.push_back(parse_sbt(str));
        }
        else if (cur[i] == '=')
        {
            onRight = true;
            if (cur[i - 1] == '?') continue;
            buf[bpt++] = '\0';
            string str = string(buf);
            bpt = 0;
            le.push_back(parse_sbt(str));
        }
        else if (cur[i] == '?')
        {
            unkOnRight = onRight;
        }
        else
            buf[bpt++] = cur[i];
    }
    if (bpt != 0)
    {
        buf[bpt++] = '\0';
        string str = string(buf);
        bpt = 0;
        ri.push_back(parse_sbt(str));
    }
    
    sbt left_sum = sbt();
    for (int i=0; i<le.size(); i++)
    {
        left_sum = left_sum + le[i];
    }
    sbt right_sum = sbt();
    for (int i=0; i<ri.size(); i++)
    {
        right_sum = right_sum + ri[i];
    }
    
    sbt unk = unkOnRight ? left_sum - right_sum : right_sum - left_sum;
    string out = make_simple(unk);
    if (out.length() == 0 || out[0] == '!')
        printf("No Solution\n");
    else
        printf("%s\n", out.c_str());
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        do_solve();
    //cin.get(), cin.get();
    return 0;
}
