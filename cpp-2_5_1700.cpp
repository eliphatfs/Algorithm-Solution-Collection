#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool col[9]={false};
bool dj1[20]={false};
bool dj2[20]={false};
int queen[9][9]={{0}};
int total=0;

void search(int x);
void print();

void search(int x)
{
	for(int y=1;y<9;y++)
	{
		if(!col[y]&&!dj1[x+y]&&!dj2[x-y+8])
		{
			queen[x][y]=1;
			col[y]=true;
			dj1[x+y]=true;
			dj2[x-y+8]=true;
			if(x==8)print();
			else search(x+1);
			queen[x][y]=0;
			col[y]=false;
			dj1[x+y]=false;
			dj2[x-y+8]=false;
		}
	}
}

void print()
{
	total++;
	printf("No. %d\n",total);
	for(int x=1;x<9;x++)
	{
		for(int y=1;y<9;y++)
		{
			printf("%d ",queen[y][x]);
		}
		printf("\n");
	}
}

int main()
{
	search(1);
	return 0;
}
