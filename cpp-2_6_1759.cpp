#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int inp[1001];
int maxa[1001]={0};

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>inp[i];
	for(int i=1;i<=n;i++)
	{
		int maxl=0;
		for(int j=1;j<i;j++)
		{
			if(maxa[j]>maxl&&inp[j]<inp[i])
			{
				maxl=maxa[j];
			}
		}
		maxa[i]=maxl+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(maxa[i]>maxa[0])
			maxa[0]=maxa[i];
	}
	cout<<maxa[0];
}
