#include <iostream>
#include <cstdio>
using namespace std;
int a[200][200] = {0};
bool cr[200];
bool cc[200];
int n;

int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cr[i] = cc[i] = false;
        for (int j=0; j<n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int uc = 0;
    for (int i=0; i<n; i++)
    {
        int count = 0;
        for (int j=0; j<n; j++)
        {
            if (a[i][j]) count++;
        }
        if (count % 2 == 1)
        {
            uc++;
            cr[i] = true;
        }
    }
    for (int i=0; i<n; i++)
    {
        int count = 0;
        for (int j=0; j<n; j++)
        {
            if (a[j][i]) count++;
        }
        if (count % 2 == 1)
        {
            uc++;
            cc[i] = true;
        }
    }
    if (uc == 0)
    {
        cout<<"OK";
        //cin.get(),cin.get();
        return 0;
    }
    else for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cr[i] = !cr[i];
            cc[j] = !cc[j];
            bool flag = false;
            for (int x=0; x<n; x++)
                if (cr[x] || cc[x]) flag = true;
            
            if (!flag)
            {
                cout<<(i+1)<<" "<<(j+1);
                //cin.get(),cin.get();
                return 0;
            }
            cr[i] = !cr[i];
            cc[j] = !cc[j];
        }
    }
    cout<<"Corrupt";
    //cin.get(),cin.get();
    return 0;
} 
