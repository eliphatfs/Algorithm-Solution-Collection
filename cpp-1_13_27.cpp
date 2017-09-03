#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

using namespace std;

int x=0;
string divide13(string num,int len);

int main()
{
	string numSou;
	int numCalc[105]={0};
	string numRes;
	cin>>numSou;
	for(int i=0;i<numSou.length();i++)
		numSou[i]-=48;
	numRes=divide13(numSou,numSou.length());
	cout<<numRes<<endl
		<<x;
	return 0;
}

string divide13(string num,int len)
{
	int res[105]={0};
	for(int i=0;i<len;i++)
	{
		res[i]=num[i];
	}
	for(int i=0;i<len;++i)
	{
		int digit=num[i];
		digit+=x*10;
		res[i]=digit/13;
		x=digit%13;
	}
	string r="";
	int i=0;
	while(res[i]==0)i++;
	for(;i<len;++i)
	{
		r+=(char)(res[i]+48);
	}
	if(r=="")
		r="0";
	return r;
}
