#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
multiset<int> nums = multiset<int>();
long long ans = 0;
int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        nums.insert(tmp);
    }
    for (int i=0; i<n-1; i++)
    {
        int nheap = 0;
        nheap += *nums.begin();
        nums.erase(nums.begin());
        nheap += *nums.begin();
        nums.erase(nums.begin());
        nums.insert(nheap);
        ans += nheap;
    }
    cout<<ans;
    return 0;
}
