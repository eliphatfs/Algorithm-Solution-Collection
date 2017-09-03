
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
  double a,b,c,d,x;
  cin>>x>>a>>b>>c>>d;
  cout.setf(ios::fixed);
  cout<<setprecision(7)
      <<(a*x*x*x+b*x*x+c*x+d);
  return 0;
}
