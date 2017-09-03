#include <cstdio>
#include <iostream>

using namespace std;

double f(double x);
double search(double l,double r);

int main()
{
	printf("%.6lf",search(1.5,2.4));
	return 0;
}

double f(double x)
{
	return (x*x*x*x*x
			-15*x*x*x*x
			+85*x*x*x
			-225*x*x
			+274*x
			-121);
}

double search(double l,double r)
{
	if(r-l<0.0000001&&f(r)<0&&f(l)>0)
		return((l+r)/2);
	double mid = (l+r)/2;
	if(f(mid)>0&&f(r)<0)
		return search(mid,r);
	else return search(l,mid);
}
