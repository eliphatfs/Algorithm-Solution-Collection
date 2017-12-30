#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x, y;
    cin>>x>>y;
    int len = x.length();
    char * z = new char[len + 1];
    z[len] = '\0';
    for (int i=0; i<len; i++)
    {
        if (y[i] > x[i]) {
            cout<<-1;
            //cin.get(), cin.get();
            return 0;
        }
        else {
            z[i] = y[i];
        }
    }
    cout<<z;
    //cin.get(), cin.get();
    return 0;
}
