#include<iostream>
#include<cstdio>
#include<stack>
#include<stdlib.h>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	freopen("1.i","r",stdin);
	string in[1000];
	for(int t=0;t<1000;t++)
		in[t]="";
	stack<char> st;
	stack<double> st2;
	int i=0,numCount=0;
    char ip[1000];
    cin.getline(ip,900);
    cout<<ip<<endl;
    bool flag=false;
	for(int j=0;j<1000;j++)
	{
		if(ip[j]!=' ')
		{
			flag=false;
			in[i]+=ip[j];
		}
		else
		{
			if(!flag)
			{
			i++;
			flag=true;
			}
			else break;
		}
	}
	for(int j=0;j<1000;j++)
		if(in[j]=="+"||in[j]=="-"||in[j]=="*"||in[j]=="/")
		{
			st.push(in[j][0]);
		}
		else
		{
			numCount++;
			st2.push(atof(in[j].c_str()));
			if(numCount==2)
			{
				numCount=0;
				double x1=st2.top();
				st2.pop();
				double x2=st2.top();
				st2.pop();
				char g=st.top();
				st.pop();
				switch(g)
				{
					case '+':
						st2.push(x1+x2);
						break;
					case '-':
						st2.push(x2-x1);
						break;
					case '*':
						st2.push(x1*x2);
						break;
					case '/':
						st2.push(x2/x1);
						break;
				}
			}
		}
	cout<<st2.top();
	return 0;
}
