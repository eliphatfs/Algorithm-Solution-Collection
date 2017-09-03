#include<iostream>
#include<iomanip>
#define STEPS 1000000000
using namespace std;

int main()
{
	long double p=0;
	for(int i=1;i<STEPS;i++)
	{
		double a=1/(4*(long double)i-3)-1/(4*(long double)i-1);
		p+=a;
	}
	cout<<setprecision(10)<<p*4;
	return 0;
}
