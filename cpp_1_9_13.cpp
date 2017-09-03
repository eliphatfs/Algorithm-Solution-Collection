#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int * m= new int[n+1];
	for(int i=1;i<n+1;i++)
		scanf("%d",&m[i]);
	int p[101]={0};
	int q[101]={0};
	int t=0,pd=0;
	for(int i=n;i>0;i--)
		p[m[i]]=i;
	for(int i=100;i>9;i--)
		if(p[i]!=0)
		{
			t++;
			q[t]=p[i];
		}
		sort(q,q+101);
	for(int i=10;i<101;i++)
		if(q[i]!=0)
		{
			pd++;
			printf("%d",m[q[i]]);
			if(pd!=t)
				printf("%s"," ");
		}
	return 0;
}