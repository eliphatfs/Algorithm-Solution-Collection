#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

int main()
{
	freopen("1748.open","r",stdin);
	vector<int> nmn,nmm;
	do
	{
		int n,m;
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		nmn.insert(nmn.end(),n);
		nmm.insert(nmm.end(),m);
	}
	while(true);
	for(int c=0;c<nmn.size();c++)
	{
		int n=nmn[c];
		int m=nmm[c];
		vector<int> monkeys;
		for(int i=1;i<n+1;i++)
			monkeys.insert(monkeys.end(),i);
		int l=0,time=0,count=0;
		while(monkeys.size()!=count+1)
		{
			l++;time++;
			if(l>monkeys.size())
				l=1;
			while(monkeys[l-1]==0)
			{
				l++;
				if(l>monkeys.size())
					l=1;
			}
			if(time==m)
			{
				//cout<<monkeys[l-1]<<endl;
				monkeys[l-1]=0;
				//for(int j=0;j<monkeys.size();j++)cout<<monkeys[j];
				//cout<<endl;
				time=0;
				count++;
			}
		}
		for(int j=0;j<monkeys.size();j++)
			if(monkeys[j]!=0)
				cout<<monkeys[j]<<endl;
	}
	return 0;
}
