#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;

stack<double> ops = stack<double>();
stack<char> ovs = stack<char>();
stack<int> cnt = stack<int>();

void count()
{
    if (cnt.empty()) return;
    int m = cnt.top() + 1;
    cnt.pop(), cnt.push(m);
}

void calc()
{
    if (cnt.empty() || cnt.top() < 2) return;
    double op1, op2;
    op2 = ops.top();
    ops.pop();
    op1 = ops.top();
    ops.pop();
    double ans;
    switch (ovs.top())
    {
        case '*':
            ans = op1 * op2;
            break;
        case '+':
            ans = op1 + op2;
            break;
        case '-':
            ans = op1 - op2;
            break;
        case '/':
            ans = op1 / op2;
            break;
    }
    ops.push(ans), ovs.pop(), cnt.pop(), count(), calc();
}

int main()
{
    char delimit = ' ';
    while (delimit == ' ') //文件中没有换行，用这个来检测EOF！ 
    {
        string str;
        cin>>str;
        switch(str[0])
        {
            case '*':
            case '+':
            case '-':
            case '/':
                ovs.push(str[0]);
                cnt.push(0);
                break;
            default:
                double op;
                sscanf(str.c_str(), "%lf", &op);
                ops.push(op);
                count();
                calc();
                break;
        }
        delimit = cin.get();
    }
    printf("%.6lf", ops.top());
    //getchar(),getchar();
    return 0;
}
