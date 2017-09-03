#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int * x=new int[n];
	vector<int> * pile=new vector<int>[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	sort(x,x+n);
	countX=0;
	countY=0;
	while(true)
	{
		if(n>0)
		{
			pile[countX].push_back(x[n-1]);
			n--;
			countX++;
			for(int i=0;i<n;i++)
			{
				if(i>pile[countX][n])
			}
		}
		else break;
	}
	return 0;
}
