#include <iostream>
using namespace std;
int pow_mod(int x, int n, int mod){
int res=1;
while (n>0){
if (n&1) res=res*x%mod;
x=x*x%mod;
n>>=1;
}
return res;
}
int main()
{
    register int n,m,k,x;
    cin>>n>>m>>k>>x;
    int l=k;
    k=1;
    k=pow_mod(10,l,n);
    for (long long i=0; i<k; i++)
        x=(((x+m)<n)?(x+m):(x+m-n));
    cout<<x;
    return 0;
}
