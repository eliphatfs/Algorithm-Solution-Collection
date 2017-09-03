#include<iostream>
using namespace std;

int main()
	{
		int n;
		int tof;
		cin>>n;
		int * p=new int[n+1];
		for(int i=1;i<=n;i++)
		{
			cin>>p[i];
		}
		cin>>tof;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==tof)
			{
			cout<<i;
		    return 0;
			}
		}
		cout<<-1;
		return 0;
	}
