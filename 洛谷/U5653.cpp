#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("U5653.in","r",stdin);
	int n,q;
	cin>>n>>q;
	long long * bisM = new long long [n];
	for(int t=0;t<n;t++)
	{
		cin>>bisM[t];
	}
	vector<long long> questQ1,questQ2,questC1,questC2,questC3;
	vector<char> questOrder;
	char qFlag;
	long long qContent[3];
	for(int t=0;t<q;t++)
	{
		cin>>qFlag;
		if (qFlag == 'C')
		{
			cin>>qContent[0]>>qContent[1]>>qContent[2];
			questC1.push_back(qContent[0]);
			questC2.push_back(qContent[1]);
			questC3.push_back(qContent[2]);
			questOrder.push_back('c');
		}
		else if(qFlag == 'Q')
		{
			cin>>qContent[0]>>qContent[1];
			questQ1.push_back(qContent[0]);
			questQ2.push_back(qContent[1]);
			questOrder.push_back('q');
		}
	}
	int countC=0,countQ=0;
	long long C[3],Q[2];
	for(int i=0;i<q;i++)
	{
		if(questOrder[i]=='c')
		{
			C[0]=questC1[countC];
			C[1]=questC2[countC];
			C[2]=questC3[countC];
			countC++;
			for(long long j=C[0]-1;j<C[1];j++)
			{
				bisM[j]+=C[2];
			}
		}
		else
		{
			Q[0]=questQ1[countQ];
			Q[1]=questQ2[countQ];
			countQ++;
			long long result=0;
			for(long long j=Q[0]-1;j<Q[1];j++)
			{
				result+=bisM[j];
			}
			cout<<result<<endl;
		}
	}
	return 0;
}
