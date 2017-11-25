#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;
int dx[1008], dy[1008];
int w[1008];
double curx = 0.1, cury = 0.1;
double epsilon = 1e-50;
double lastcurx = 0.1, lastcury = 0.1;
void iterate(double lr)
{
    //cout<<lr<<endl;
    while (true)
    {
        double lastlossx = 0, lastlossy = 0;
        double lossx = 0, lossy = 0;
        for (int i=0; i<n; i++)
        {
            double dtx = dx[i] - lastcurx;
            double dty = dy[i] - lastcury;
            double len = sqrt(dtx * dtx + dty * dty);
            len += epsilon;
            lastlossx += dtx / len * w[i];
            lastlossy += dty / len * w[i];
        }
        curx = lastcurx + lastlossx * lr;
        cury = lastcury + lastlossy * lr;
        for (int i=0; i<n; i++)
        {
            double dtx = dx[i] - curx;
            double dty = dy[i] - cury;
            double len = sqrt(dtx * dtx + dty * dty);
            len += epsilon;
            lossx += dtx / len * w[i];
            lossy += dty / len * w[i];
        }
        double deltaloss = lossx * lossx + lossy * lossy - lastlossx * lastlossx - lastlossy * lastlossy;
        /*cout<<deltaloss<<endl;
        cout<<curx<<char(32)<<cury<<endl;
        cin.get();*/
        if (deltaloss < 0.0)
        {
            if (abs(curx - lastcurx) < 1e-5 && abs(cury - lastcury) < 1e-5)
            {
                return;
            }
            lastcurx = curx, lastcury = cury;
        }
        else
        {
            iterate(lr * 0.5);
            return;
        }
    }
}
int main()
{
    cin>>n;
    double sx = 0, sy = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d%d%d", &dx[i], &dy[i], &w[i]);
        sx += dx[i] * w[i];
        sy += dy[i] * w[i];
    }
    curx = sx / n;
    cury = sy / n;
    iterate(500);
    printf("%.3lf %.3lf", curx, cury);
    return 0;
}
