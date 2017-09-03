#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;
vector<int> find(int x);

int main()
{
	int x,y;
	scanf("%d%d",&x,&y);
	vector<int> vx;
	vx=find(x);
	vector<int> vy;
	vy=find(y);
	int max=1;
	for(int i=0;i<(vx.size()<vy.size()?vx.size():vy.size());i++)
	{
		if(vx[i]==vy[i])
		{
			max=vx[i];
		}
	}
	cout<<max;
	return 0;
}

vector<int> find(int x)
{
	vector<int> a;
	a.insert(a.begin(),x);
	while(x!=1)
	{
		x/=2;
		a.insert(a.begin(),x);
	}
	return a;
}
