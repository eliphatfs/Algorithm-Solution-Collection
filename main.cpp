/*#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>
using namespace std;
int main()
{
    string ch;
    int flag=6;
    if(flag==1)
    {
int m=0,n=0;
int jh1[1000];
int jh2[1000];
    int i=1;
for(i=1;i<1001;i++)
{
    jh1[i]=0;
    jh2[i]=0;
}
    float y;
    i=1;
    for(float x=0;x<101;x++)
    {
        if(x!=10)
        {
        y=9/(10-x);
        if(y<0)
            y=0.01;
        }
        else
            y=0.01;

        if(y-(int)y==0)
        {
            jh1[i]=x;
            jh2[i]=y;
        }
            i++;
    }
            cout<<"{";
            for(i=1;i<1000;i++)
            {
                if(jh2[i]!=0)
                {
                    m++;
                }
            }
            for(i=1;i<1000;i++)
            {
                if(jh1[i]!=0)
                {
                    n++;
                    cout << jh1[i];
                    if(n!=m)
                    cout << ",";
                }
            }
            cout<<"}"<<endl;
            n=0;
            m=0;
            cout<<"{";
            for(i=1;i<1000;i++)
            {
                if(jh2[i]!=0)
                {
                    m++;
                }
            }
            for(i=1;i<1000;i++)
            {
                if(jh2[i]!=0)
                {
                    n++;
                    cout << jh2[i];
                    if(n!=m)
                    cout << ",";
                }
            }
            cout<<"}";
    }
    if(flag==2)//It is a exploration from flag==1
    {
        float stud;
        stud=9/100.0;
        cout << stud;
    }
    if(flag==3)
    {
        int a,b,c,d,x[121],y[121],i;
//calc:
        for(a=-5;a<=5;a++)
        {
            for(b=-5;b<=5;b++)
            {
                x[a*11+b+60]=12*a+8*b;
            }
        }

        for(c=-5;c<=5;c++)
        {
            for(d=-5;d<=5;d++)
            {
                y[c*11+d+60]=20*c+16*d;
            }
        }
//sort:
        sort(x,x+121);
        sort(y,y+121);
//output:
        cout<<"{";
        for(i=10;i<101;++i)
        {
            bool bo=false;
            for(int j=0;j<i;++j)
            {
                if(x[j]==x[i]) {bo=true;break;}
            }
            if(bo==false)
            {
        cout<<x[i];
        if(i!=100)
            cout<<",";
            }
        }
        cout<<"}"<<endl;
        cout<<"{";
        for(i=10;i<101;++i)
        {
            bool bo=false;
            for(int j=0;j<i;++j)
            {
                if(y[j]==y[i]) {bo=true;break;}
            }
            if(bo==false)
            {
        cout<<y[i];
        if(i!=100)
            cout<<",";
            }
        }
        cout<<"}";
    }
    if(flag==4)
    {
        int i;
        cout<<"20160___\b\b\b\b\b\b\b\b";
        cin >>i;
        cout<<i;
    }
    if(flag==5)
    {
        setlocale(LC_ALL,"ansi");
        for(int i=1;i<=100;i++)
           { cout <<ch; getchar();getchar();getchar();}
    }
    if(flag==6)
    {
        double times(0);
        double power=1.0;
        double Base=5999/6000.0;
        while(power>=0.5)
        {
            power*=Base;
            times++;
        }
        cout<<times<<":"<<endl
           <<power;
    }
    return 0;
}*/
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
#define PI 3.14159265358

double r[10001];
int n, f;
double ans;

bool canwork(double size)
{
    int i;
    int sum=0;
    for(i=0;i<n;i++)
        sum+=r[i]/size;
    return sum>=f;
}

void solve(double left, double right)
{
    if(right-left<0.00001)
        {
            ans=left;
            return;
        }
    double mid=(left+right)/2;
    if(canwork(mid))
        solve(mid, right);
    else
         solve(left, mid);
}

int main()
{
    int i;
    double sizesum=0, maxsize;
    cin>>n>>f;
    f++;
    for(i=0;i<n;i++)
    {
        cin>>r[i];
        r[i]=r[i]*r[i]*PI;
        sizesum+=r[i];
    }
    maxsize=sizesum/f+0.0000001;
    solve(0, maxsize);
    printf("%.3f\n", ans);
    return 0;
}
