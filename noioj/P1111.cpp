#include <iostream>
#include <set>
#include <queue>
#include <cstdio>
using namespace std;

int data[1000001];

int main()
{
    //freopen("C:/Users/user/Downloads/blash0.in", "r", stdin);
	int a,n;
	while (scanf("%d%d", &a, &n) == 2)
	{
        int i = 1, j = 1;
        int dpt = 1;
        data[1] = a;
        while (dpt < n)
        {
            int x = data[i] * 2 + 1;
            int y = data[j] * 3 + 1;
            if (x < y)
            {
                data[++dpt] = x;
                ++i;
            }
            else if (x > y)
            {
                data[++dpt] = y;
                ++j;
            }
            else
            {
                data[++dpt] = x;
                ++i;
                ++j;
            }
        }
        cout<<data[dpt]<<endl;
		
		/*set<long long> blah = set<long long>();
		blah.insert(a);
		int cnt = 0;
		set<long long>::iterator cur = blah.begin();
		while (true)
		{
            ++cnt;
			if (cnt == n)
			{
				cout<<(*cur)<<endl;
				break;
			}
			blah.insert(2 * (*cur) + 1), blah.insert(3 * (*cur) + 1);
            ++cur;
		}*/
	}
	return 0;
}
