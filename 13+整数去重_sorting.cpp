#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 20008;

struct Num
{
	int d;
	int seq;
};

Num num[MAXN];

int n;

bool cmp1(Num p1, Num p2)
{
	if(p1.d < p2.d)
		return true;
	else if(p1.d == p2.d)
		return p1.seq < p2.seq;
	return false;
}

bool cmp2(Num p1, Num p2)
{
	return p1.seq < p2.seq;
}

int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	
	int i, j;
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> num[i].d;
		num[i].seq = i;
	}
	sort(num, num+n, cmp1);
	
	i = 1; 
	j = 0;
	while(i < n)
	{
		if(num[i].d != num[j].d)
		{
			j++;
			num[j].d = num[i].d;
			num[j].seq = num[i].seq;
		}
		i++;
	}
	
	sort(num, num + j + 1, cmp2);
	
	for(i = 0; i < j; i++)
		cout << num[i].d << " ";
	cout << num[j].d;
	
	return 0;
}
