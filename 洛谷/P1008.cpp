#include<iostream>
#include<cstdio>
using namespace std;
bool usedNum[9];
void CalcNum(int x);
int main()
{
    for(int i=100; i<333; i++)
    {
        for (int j=0; j<9; j++)
            usedNum[j]=false;
        int i2 = i * 2;
        int i3 = i * 3;
        CalcNum(i);
        CalcNum(i2);
        CalcNum(i3);
        bool flag=true;
        for (int j=0; j<9; j++)
            flag = flag && usedNum[j];
        if (flag)
            printf("%d %d %d\n", i, i2, i3);
    }
    return 0;
}

void CalcNum(int x)
{
    int n1=x%10;
    int n2=(x%100)/10;
    int n3=x/100;
    if (n1==0||n2==0||n3==0) return;
    usedNum[n1-1]=true;
    usedNum[n2-1]=true;
    usedNum[n3-1]=true;
}
