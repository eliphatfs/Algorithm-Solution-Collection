#include <iostream>
#include <cstdio>
using namespace std;
int n;
int dat[1001];
int maxl[1001] = {0};
int n2;
int dat2[1001];
int maxd[1001] = {0};
int maxl2[1001] = {0};
int main()
{
    cin>>n;
    for (int i=0; i<n; i++)
        scanf("%d", &dat[i]);
    for (int i=0; i<n; i++)
    {
        int maxnow = 0;
        for (int j=0; j<i; j++)
        {
            if ((maxl[j] > maxnow) && (dat[j] < dat[i]))
                maxnow = maxl[j];
        }
        maxl[i] = maxnow + 1;
    }
    for (int k=0; k==0; k++)
    {
        n2 = n - k;
        for (int i=0; i<n2; i++)
            maxd[i] = 0;
        for (int i=k; i<n; i++)
        {
            dat2[n2-1-(i-k)] = dat[i];
        }
        for (int i=0; i<n2; i++)
        {
            int maxnow = 0;
            for (int j=0; j<i; j++)
            {
                if ((maxd[j] > maxnow) && (dat2[j] < dat2[i]))
                    maxnow = maxd[j];
            }
            maxd[i] = maxnow + 1;
        }
        int answer = 0;
        for (int i=0; i<n2; i++)
        {
            maxl2[n2-1-i] = maxd[i];
            //if (maxd[i] > answer)
            //    answer = maxd[i];
        }
        //maxl2[k] = answer;
    }
    int answer = 0;
    for (int i=0; i<n; i++)
    {
        //cout<<maxl[i]<<" "<<maxd[i]<<endl;
        if ((maxl[i] + maxl2[i] - 1) > answer)
        {
            answer = (maxl[i] + maxl2[i] - 1);
            //answer = i;
        }
    }
    cout<<answer;
    //getchar();getchar();
    return 0;
}
