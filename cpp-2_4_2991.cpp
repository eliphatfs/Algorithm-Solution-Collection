#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	//freopen("2991.in","r",stdin);
	//freopen("2991.out","w",stdout);
	int n;
	cin>>n;
	string * input = new string[n];
	/*for (int i=0;i<n;i++)
		input[i]=i+1;*/
	for(int i=0;i<n;i++)
		cin>>input[i];
	for(int i=0;i<n;i++)
	{
		int length=input[i].length();
		int times;
		if (input[i].length()==1)
			times = input[i][0]-48;
		else if (input[i].length()==2)
			times = (input[i][0]-48)*10+input[i][1]-48;
		else
			times = int(input[i][length-3]-48)*100
				+int(input[i][length-2]-48)*10
				+int(input[i][length-1]-48)*1;
		int base = 1;
		while (times>0)
		{
			base *= 2011;
			base = base % 10000;
			times--;
		}
		cout<<base<<endl;
	}
}
