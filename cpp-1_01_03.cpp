#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    unsigned short maxl=8;
    if(a.length()>maxl)
    {
        maxl=a.length();
    }
    if(b.length()>maxl)
    {
        maxl=b.length();
    }
    if(c.length()>maxl)
    {
        maxl=c.length();
    }
    while(a.length()<maxl)
    {
        a=" "+a;
    }
    while(b.length()<maxl)
    {
        b=" "+b;
    }
    while(c.length()<maxl)
    {
        c=" "+c;
    }
    cout<<a<<b<<c;
}
