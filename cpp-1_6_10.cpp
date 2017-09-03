#include<iostream>
#include<string>
using namespace std;
class L{
public:
    L()
    {
        length=0;
        for(int i=0;i<201;i++)
            digit[i]=0;
    }

    L operator+(L num)
    {
        length=max(num.length,length)+1;
        for(int i=0;i<length;i++)
        {
            digit[i]+=num.digit[i];
            if(digit[i]>=10)
            {
                digit[i]-=10;
                digit[i+1]++;
            }
        }
        while((digit[length-1]==0)&&length!=1)
        {
            length--;
        }
        return *this;
    }
    void operator=(L num)
    {
        for(int i=0;i<201;i++)
            digit[i]=num.digit[i];
        length=num.length;
    }

    void operator=(string s)
    {
        length=s.length();
        for(int i=0;i<length;i++)
        {
            digit[i]=int(s[length-i-1])-48;
        }
    }
    string out()
    {
        string outs="";
        for(int i=0;i<length;i++)
        {
            outs=char(digit[i]+48)+outs;
        }
        return outs;
    }

private:
    short digit[201];
    short length;
}
    ;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    L n1,n2,result;
    n1=s1;
    n2=s2;
    result=n1+n2;
    cout<<result.out();
    return 0;
}
