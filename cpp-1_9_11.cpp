#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	string f;
	int k;
	cin>>k>>f;
	char x=' ';
	int fuck=1;
	for(int i=0;i<f.length();i++)
	{
		if(x==f[i])
		{
			fuck++;
			if(fuck==k)
			{
				cout<<x;
				return 0;
			}
		}
		else
		{
			fuck=1;
			x=f[i];
		}
	}
	cout<<"No";
	return 0;
}
