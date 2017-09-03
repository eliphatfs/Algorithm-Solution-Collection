#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	/*int x;
	string c="1234567123";
	cin>>x;
	x=x%10;
	if(x==0)x+=10;
	cout<<c[x-1];*/
	int x=20;
	string a="4567",b="123",c=b+a;
	cin>>x;
	x++;
	while(c.length()<x)
	{
		a=b;
		b=c;
		c=b+a;
		if(c.length()<x)
		{
		x-=c.length();
		//for(int i=0;i<c.length();i++)
		c="";
		}
	}
	cout<<c[x-1]<<endl;
	return 0;
}
