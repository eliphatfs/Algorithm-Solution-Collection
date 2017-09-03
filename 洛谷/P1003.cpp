#include <iostream>
#include <cstdio>
using namespace std;

int n;
int pX,pY;
int * rects;
int ans=-2;

bool overlap(int x, int y, int w, int h);

int main()
{
    cin>>n;
    rects = new int[4*n];
    for(int i=0; i<n; i++)
    {
        int j = i*4;
        scanf("%d%d%d%d", &rects[j], &rects[j+1], &rects[j+2], &rects[j+3]);
    }
    cin>>pX>>pY;
    for(int i=0; i<n; i++)
    {
        int j = i*4;
        if(overlap(rects[j], rects[j+1], rects[j+2], rects[j+3]))
        {
            ans=i;
        }
    }
    cout<<(ans+1);
    //getchar();getchar();
    return 0;
}

bool overlap(int x, int y, int w, int h)
{
    if((pX>=x) && (pX<=x+w) && (pY>=y) && (pY<= y+h)) return true;
    else return false;
}
