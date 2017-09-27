#include <iostream>
#include <cstdio>
using namespace std;

int n, k;
short data[100086];

int judge(int target)
{
	if (target == 0) return 1;
	int lpt = 0, rpt = 0;
	int wcnt = 0, bcnt = 0;
	if (data[0]) ++wcnt;
	else ++bcnt;
	
	while (lpt < n && rpt < n)
	{
		if (wcnt + bcnt < target)
		{
			++rpt;
			if (rpt >= n) return 0;
			if (data[rpt]) ++wcnt;
			else ++bcnt;
			
			if (bcnt > k)
				do
				{
					if (data[lpt]) --wcnt;
					else --bcnt;
					++lpt;
					if (lpt >= n) return 0;
				} while (bcnt > k);
		}
		else return 1;
	}
	return 0;
}

int search(int l, int r)
{
	int m = (l + r) >> 1;
	int jm = judge(m);
	int jmr = judge(m + 1);
	if (jm && !jmr)
		return m;
	else if (!jm)
		return search(l, m);
	else return search(m + 1, r);
}

int main()
{
	cin>>n>>k;
	for (int i=0; i<n; i++)
		scanf("%d", &data[i]);
	cout<<search(0, n);
	return 0;
}
