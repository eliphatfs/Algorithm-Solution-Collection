#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<100001;i++)
	{
		int a=(1+i)*i/2;
		float b=(a-n)/2;
		if(b>0&&b==int(b))
		{
			cout<<(int)b<<" "<<i;
			break;
		}
	}
	return 0;
}
