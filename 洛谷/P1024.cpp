#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
float a,b,c,d;
float f(float x);
float search(float l, float r);
int main()
{
    cin >> a >> b >> c >> d;
    float ans;
    float anss[3];
    ans = search(-100, 100);
    anss[0] = ans;
    float s = (-b - ans) / a;
    float mu = (-d / ans) / a;
    //剩下两根是方程t2-s+mu=0两根
    float delta = sqrt(s*s-4*mu);
    anss[1] = (s + delta) / a / 2;
    anss[2] = (s - delta) / a / 2;
    sort(anss, anss+3);
    for (int i=0; i<3; i++)
        printf("%.2f ", anss[i]);
    return 0;
}
//二分 
float search(float l, float r)
{
    float m = (l+r)/2;
    if (abs(f(m))<0.001) return m;
    if (f(l) * f(m) > 0) return search(m, r);
    else return search(l, m);
}
float f(float x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
