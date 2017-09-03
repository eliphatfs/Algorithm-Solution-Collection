#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
    vector<vector<char> > splited = vector<vector<char> >();
    string word;
    cin>>word;
    getchar();
    string passage;
    getline(cin, passage);
    int last=0;
    vector<char> str = vector<char>();
    char * w = new char[word.length()];
    char * p = new char[passage.length()];
    for (int i=0; i<word.length(); i++)
    {
        w[i] = word[i];
        if (word[i] <= 'Z' && word[i] >= 'A')
            w[i] += 32;
    }
    for (int i=0; i<passage.length(); i++)
    {
        p[i] = passage[i];
        if (passage[i] <= 'Z' && passage[i] >= 'A')
            p[i] += 32;
    }
    for (int i=0; i<passage.length(); i++)
    {
        if (p[i] != ' ')
            str.push_back(p[i]);
        else
        {
            splited.push_back(str);
            str = vector<char>();
        }
    }
    splited.push_back(str);
    int ans = 0;
    string tmpp(p);
    string tmpw(w);
    int pos = -1;
    int l = 0;
    for (int i=0; i<splited.size(); i++)
    {
        bool flag = true;
        if (splited[i].size() != word.length()) flag = false;
        else for (int j=0; j<splited[i].size(); j++)
            if (splited[i][j] != w[j]) flag = false;
        if (flag)
        {
            ans++;
            if (pos == -1) pos = l;
        }
        l += splited[i].size() + 1;
    }
    if (ans > 0)
        cout<<ans<<" "<<pos;
    else cout<<-1;
    //getchar();getchar();
    return 0;
}
