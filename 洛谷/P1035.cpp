#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int k;
    cin>>k;
    double s=0;
    for (int n=1; n<100000000; n++)
    {
        s+=1/(double)n;
        if (s>k)
        {
            cout<<n;
            return 0;
        }
    }
}
