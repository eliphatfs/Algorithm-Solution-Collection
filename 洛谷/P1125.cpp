#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    cin>>str;
    map<int, int> chartable = map<int, int>();
    for (int i=0; i<str.length(); i++)
    {
        chartable[(int)str[i]]++;
    }
    int max = -1;
    int min = 1048576;
    map<int, int>::iterator it;
    for (it = chartable.begin(); it != chartable.end(); it++)
    {
        if (it->second > max) max = it->second;
        if (it->second < min) min = it->second;
    }
    int delta = max - min;
    bool flag = true;
    if (delta <= 1) flag = false;
    for (int i=2; i<delta; i++)
    {
        if (delta % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout<<"Lucky Word"<<endl<<delta;
    else
        cout<<"No Answer"<<endl<<0;
    //getchar();getchar();
    return 0;
}
