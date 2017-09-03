#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m[101]={0},input=1;
    cin>>m[0];
    while(input<=m[0])
    {
        cin>>m[input];
        input++;
    }
    sort(m+1,m+100);

    bool bo=false;
    for(int i=1;i<100;i++)
    {
        if(m[i]==m[i+1]&&m[i]!=0&&m[i+1]!=0)
        {
            m[i+1]=0;
            m[0]--;
            bo=true;
        }
    }
    sort(m+1,m+100);
    while(bo)
    {
        bo=false;
    for(int i=1;i<100;i++)
    {
        if(m[i]==m[i+1]&&m[i]!=0&&m[i+1]!=0)
        {
            bo=true;
            m[i+1]=0;
            m[0]--;

        }
    }
    sort(m+1,m+100);
    }
    cout<<m[0]<<endl;
    for(int i=1;i<101;i++)
    {
        if(m[i]!=0)
            cout<<m[i]<<" ";
    }
    return 0;
}
