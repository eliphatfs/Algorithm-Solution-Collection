#include<iostream>
#include<string>
using namespace std;
int main()
	{
		int n;
		cin>>n;
		int * a=new int[n+1];
		string * b=new string[n+1];
		int maxa=0,maxi;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
			if(a[i]>maxa)
			{
			  maxa=a[i];
			  maxi=i;
			}
		}
		cout<<b[maxi];
		return 0;
	}
