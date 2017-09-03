#include<iostream>
using namespace std;
int main()
{
	int m,n,b=1;
	cin>>n;
	int e[100005];
	for(int i=0;i<=100004;i++)
	  e[i]=2147483640;
	for(int i=1;i<=n;i++)
	  cin>>e[i];
	cin>>m;
	int * t=new int[m+7];
	int * o=new int[m+7];
	for(int i=1;i<=m;i++)
	  cin>>t[i];
	for(int i=1;i<=m;i++)
	{
		for(int a=1000;a>=1;a/=10)
		for(int j=n+2;j>b;j-=a)
		{
			if(t[i]==e[j])
			{
				o[i]=e[j];
				break;
			}
			if(e[j]<t[i])
			{
				cout<<e[j]<<endl;
				b=j-1;
				break;
			}
			if(e[j]>t[i]&&e[j-1]<=t[i])
			{
				int pd=(e[j]-t[i])-(t[i]-e[j-1]);
				if(pd<0)
				{
				o[i]=e[j];
				flag=true;
				}
				else if(pd>0)
				{
				o[i]=e[j-1];
				flag=true;
				}
				else
				{
					o[i]=e[j-1];
					flag=true;
				}
				break;
			}
		}
	}
	for(int i=1;i<=m;i++)
	  cout<<o[i]<<endl;
	return 0;
}
