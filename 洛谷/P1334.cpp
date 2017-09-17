#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int n, tmp;
multiset<int> mset = multiset<int>();
int main()
{
    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", &tmp), mset.insert(tmp);
    long long ans = 0;
    while (mset.size() > 1)
    {
        int min1 = *mset.begin(), min2 = *(++mset.begin());
        mset.erase(mset.begin()), mset.erase(mset.begin()), mset.insert(min1 + min2);
        ans += min1 + min2;
    }
    cout << ans;
    //cin.get(), cin.get();
    return 0;
} 
