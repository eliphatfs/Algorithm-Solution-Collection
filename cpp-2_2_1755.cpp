#include<iostream>
#include<cstdio>

using namespace std;

int feb(int i)
{
	if(i==1||i==2)
	{
		return 1;
	}
	return feb(i-1)+feb(i-2);
}

int main()
{
	int n;
	cin>>n;
	int * in=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",in+i);
	for(int i=0;i<n;i++)
	{
		cout<<feb(in[i])<<endl;
	}
	return 0;
}
