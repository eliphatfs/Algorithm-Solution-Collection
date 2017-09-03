#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
struct pr
{
    int id;
    string get;
};
int compare(pr a, pr b)
{
    if (a.get.length() > b.get.length()) return 1;
    else if (a.get.length() < b.get.length()) return 0;
    for (int i=0; i<a.get.length(); i++)
    {
        if(a.get[i] < b.get[i]) return 0;
        else if(a.get[i] > b.get[i]) return 1;
    }
    return 0;
}
pr data[30];
int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>data[i].get;
        data[i].id=i;
    }
    sort(data, data+n, compare);
    cout<<data[0].id+1<<endl<<data[0].get;
    return 0;
}
