#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> apples = vector<int>();
void read();
int main()
{
    int height;
    int apple[10];
    for (int i=0; i<10; i++)
    {
        cin>>apple[i];
    }
    cin>>height;
    height+=30;
    int counter=0;
    for (int i=0; i<10; i++)
    {
        if(apple[i]<=height)
            counter++;
    }
    cout<<counter;
    return 0;
}
void read()
{
    char buffer;
    while(buffer!= '\n')
    {
        int tmp=0;
        while((buffer=getchar()) != ' ')
        {
            if(buffer == '\n') break;
            tmp*=10;
            tmp+=buffer - 48;
        }
        apples.push_back(tmp);
    }
}
