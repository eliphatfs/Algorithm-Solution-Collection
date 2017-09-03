#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int type = 0; // 0:整数 1:分数 2:小数 3:百分数
    string num;
    cin>>num;
    vector<char> part1 = vector<char>();
    vector<char> part2 = vector<char>();
    bool flag = true;
    for (int i=0; i<num.length(); i++)
    {
        if (num[i] == '.') {type = 2; flag = false; continue;}
        else if (num[i] == '/') {type = 1; flag = false; continue;}
        else if (num[i] == '%') {type = 3; flag = false; continue;}
        if (flag)
            part1.push_back(num[i]);
        else part2.push_back(num[i]);
    }
    
    bool allzero = true;
    for (int i=0; i<part1.size(); i++)
        if (part1[i] != '0')
            allzero = false;
    if (allzero)
        cout<<0;
    else
    {
        flag = false;
        for (int i=part1.size()-1; i>=0; i--)
        {
            if (part1[i] != '0')
                flag = true;
            if (flag) cout<<part1[i];
        }
    }
    
    if (type == 1) cout<<"/";
    else if (type == 2) cout<<".";
    else if (type == 3) cout<<"%";
    
    allzero = true;
    for (int i=0; i<part2.size(); i++)
        if (part2[i] != '0')
            allzero = false;
    if (allzero && part2.size() != 0)
        cout<<0;
    else
    {
        flag = false;
        if (type == 2)
            for (int i=0; i<part2.size(); i++)
                if (part2[i] == '0')
                {
                    part2[i] = 0;
                }
                else break;
        for (int i=part2.size()-1; i>=0; i--)
        {
            if (part2[i] != '0')
                flag = true;
            if (flag && part2[i] != 0) cout<<part2[i];
        }
    }
    
    //getchar();getchar();
    return 0;
}
