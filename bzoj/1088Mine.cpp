#include <iostream>
#include <cstdio>

using namespace std;

int ans=0;
bool now[10001]={false};
int col2[10001];
bool ok=true;
int n;
void pd();

void pd()
{
	for(int i=1;i<n-1;i++)
	{
		int nowNum=0;
		if(now[i-1])nowNum++;
		if(now[i])nowNum++;
		int nextNum=col2[i]-nowNum;
		if(nextNum==1)now[i+1]=true;
		else if(nextNum==0)now[i+1]=false;
		else
		{
			ok=false;
			return;
		}
	}
	int nowNum=0;
	if(now[n-2])nowNum++;
	if(now[n-1])nowNum++;
	if(nowNum!=col2[n-1])
	{
		ok=false;
		return;
	}
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&col2[i]);
	}
	switch (col2[0])
	{
		case 0:
			now[0]=false;
			now[1]=false;
			pd();
			if(ok)ans++;
			break;
		case 1:
			now[0]=false;
			now[1]=true;
			pd();
			if(ok)ans++;
			ok=true;
			now[1]=false;
			now[0]=true;
			pd();
			if(ok)ans++;
			break;
		case 2:
			now[0]=true;
			now[1]=true;
			pd();
			if(ok)ans++;
			break;
	}
	cout<<ans;
	return 0;
}
