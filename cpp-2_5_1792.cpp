#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char a[1000][1000];
bool visited[1000][1000]={{false}};
bool ok=false;
int n;

void sch(int xnow,int ynow,int xdes,int ydes);
void next(int xnow,int ynow,int x);

int main()
{
	int m;
	cin>>m;
	for(int tt=0;tt<m;tt++)
	{
		ok=false;
		memset(visited, 0, sizeof(visited));
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
		visited[nx][ny]=true;
		if ( nx>=n || ny>=n || dx>=n || dy>=n || nx<0 || ny<0 || dx<0 || dy<0||a[nx][ny]=='#'||a[dx][dy]=='#')
		  ok=false;
		else if (nx==dx&&ny==dy) ok=true;
		else
		  sch(nx,ny,dx,dy);
		if(!ok)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}

void sch(int xnow,int ynow,int xdes,int ydes)
{
    int point[2];
    if (ok) return;
	//if (a[xnow][ynow]=='#'||a[xdes][ydes]=='#')return;
	for(int req=0;req<4;req++)
	{
        if (ok) return;
        	switch (req)
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
		if(point[0]>=0&&point[0]<n
            &&point[1]>=0&&point[1]<n
            && a[point[0]][point[1]]=='.'
            &&!visited[point[0]][point[1]])
		{
			visited[point[0]][point[1]]=true;
			if(point[0]==xdes&&point[1]==ydes)
			{
			    ok=true;
			    return;
			}
			else
			{
				sch(point[0],point[1],xdes,ydes);
			}
			//visited[point[0]][point[1]]=false;
		}
	}
}
