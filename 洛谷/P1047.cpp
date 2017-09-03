#include <iostream>
#include <cstring>
using namespace std;

int l, m;
int main()
{
    cin>>l>>m;
    l++; 
    int * data = new int[l];
    memset(data, 0, l * 4);
    for (int t=0; t<m; t++)
    {
        int beg, end;
        cin>>beg>>end;
        for (int i=beg; i<=end; i++)
            data[i] = 1;
    }
    int count = 0;
    for (int i=0; i<l; i++)
        if (data[i] == 0) count++;
    cout<<count;
    //getchar();
    //getchar();
    return 0;
}
