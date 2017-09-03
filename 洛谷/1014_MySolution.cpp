#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	freopen("1014.in","r",stdin);
	int n;
	cin>>n;
	int row=0;
	while(n>row)
	{
		n-=row;
		row++;
	}
	cout<<(row+1-n)<<"/"<<n;
	return 0;
}
