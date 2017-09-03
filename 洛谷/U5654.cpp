#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main()
{
    //freopen("U5654.in","r",stdin);
    int n,q;
    cin>>n>>q;
    string * phone = new string [n];
    string * quest = new string [q];
    map<string,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>phone[i];
        //cout<<phone[i]<<endl;
    }
    for(int i=0;i<q;i++)
    {
        cin>>quest[i];
        //cout<<quest[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
    	for(int k=1;k<=phone[i].length();k++)
    	{
    		string tmp(k,0);
    		for(int l=0;l<k;l++)
    			tmp[l]=phone[i][l];
    		mp[tmp]++;
		}
	}
    for(int i=0;i<q;i++)
    {
        printf("%d\n",mp[quest[i]]);
    }
    return 0;
}
