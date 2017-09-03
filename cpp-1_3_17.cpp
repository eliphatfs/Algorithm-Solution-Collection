
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
  double x,y,a,b,m,n,p;
  cin>>x>>y>>a>>b>>m>>n;
  double l1=sqrt((b-y)*(b-y)+(a-x)*(a-x));
  double l2=sqrt((b-n)*(b-n)+(a-m)*(a-m));
  double l3=sqrt((n-y)*(n-y)+(m-x)*(m-x));
  p=(l1+l2+l3)/2;
  cout.setf(ios::fixed);
  cout<<setprecision(2)<<sqrt(p*(p-l1)*(p-l2)*(p-l3));
  return 0;
}
