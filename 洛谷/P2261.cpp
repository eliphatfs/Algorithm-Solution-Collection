#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll ans=0,p,q,n,k;
    cin >>n>>k;
    if(n>k)ans+=(n-k)*k,n=k;
    for(ll i=1;i<=n;i++){
        p=k/i,q=k%i;//p为商，i为队列首相项
        ll j=k/p;//j为尾项
        if(j>n)j=n;
        ans+=(q+q-(j-i)*p)*(j-i+1)/2;
        i=j;
    }
    cout<<ans<<endl;
    return 0;
}
