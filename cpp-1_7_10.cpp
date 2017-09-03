#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>=65&&s[i]<65+26)
        {
            s[i]-=5;
            if(s[i]<65)
                s[i]+=26;
        }
    }
    cout<<s;
    return 0;
}
