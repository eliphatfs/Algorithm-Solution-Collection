#include <iostream>
#include <cstdio>
using namespace std;

int m,n,ans=0;

int main()
{
    //freopen("C:/Users/S/Downloads/testdata.in", "r", stdin);
    cin>>m>>n;
    int * buf = new int[m];
    int * tim = new int[m];
    
    for (int j=0; j<m; j++)
    {
        buf[j]=tim[j]=-1;
    }
    
    for (int i=0; i<n; i++)
    {
        int w;
        cin>>w;
        int npt=-1;
        for (int j=0; j<m; j++)
        {
            tim[j]++;
            if(buf[j] == w)
                npt = j;
        }
        if (npt==-1)
        {
            int longest = -1;
            int longesti = -1;
            for (int j=0; j<m; j++)
            {
                if(buf[j] == -1)
                {
                    longest = 1048576;
                    longesti = j;
                    break;
                }
                if(tim[j]>longest)
                {
                    longest = tim[j];
                    longesti = j;
                }
            }
            tim[longesti]=0;
            buf[longesti]=w;
            ans++;
        }
    }
    cout<<ans;
    //freopen("CON", "r", stdin);
    //getchar();getchar();
    return 0;
}
