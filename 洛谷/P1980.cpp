#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char buffer[10];
    long long counter = 0;
    int n, x;
    cin>>n>>x;
    for (int i=1; i<=n; i++)
    {
        sprintf(buffer, "%d", i);
        for (int j=0; j<10; j++)
        {
            if(buffer[j]=='\0') break;
            if(buffer[j]-48 == x) counter++;
        }
    }
    cout<<counter;
    return 0;
}
