#include <iostream>
#include <cstdio>

using namespace std;
char a[1000][1000];
bool visited[1000][1000]={{false}};
bool ok=false;
int point[2];
int n;

void sch(int xnow,int ynow,int xdes,int ydes);
void next(int xnow,int ynow,int x);

int main()
{
	int m;
	//freopen("1792.txt","r",stdin);
	cin>>m;
	for(int tt=0;tt<m;tt++)
	{
		ok=false;
		cin>>n;
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<n;y++)
			{
				char tmp=getchar();
				while(tmp=='\n'||tmp=='\r')
					tmp=getchar();
				a[x][y]=tmp;
			}
		}
		int nx,ny,dx,dy;
		cin>>nx>>ny>>dx>>dy;
		sch(nx,ny,dx,dy);
		if(!ok)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}

void sch(int xnow,int ynow,int xdes,int ydes)
{
	if (a[xnow][ynow]=='#'||a[xdes][ydes]=='#')return;
	for(int req=0;req<4;req++)
	{
		next(xnow,ynow,req);
		if(
		a[point[0]][point[1]]=='.'&&point[0]>=0&&point[0]<n&&point[1]>=0&&point[1]<n&&!visited[point[0]][point[1]])
		{
			visited[point[0]][point[1]]=true;
			if(point[0]==xdes&&point[1]==ydes)
			{
			ok=true;
			}
			else
			{
				sch(point[0],point[1],xdes,ydes);
			}
			visited[point[0]][point[1]]=false;
		}
	}
	return;
}
void next(int xnow,int ynow,int x)
{
	switch (x)
	{
		case 0:
			point[0]=xnow-1;
			point[1]=ynow;
			break;
		case 1:
			point[0]=xnow+1;
			point[1]=ynow;
			break;
		case 2:
			point[0]=xnow;
			point[1]=ynow-1;
			break;
		case 3:
			point[0]=xnow;
			point[1]=ynow+1;
			break;
	}
}
